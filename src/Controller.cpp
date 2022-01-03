#include "Controller.h"
#include <iostream>
int stepCounter;
bool key, won;

Controller::Controller()
    :m_board(), m_currChar(0) , m_caption()
{   
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    loadTextures();    
}

void Controller::run(sf::RenderWindow& window)
{
    m_board = Board(WINDOW_WIDTH, WINDOW_HEIGHT - BAR_SIZE, sf::Vector2f(0, 0), m_character, m_tiles, m_textures);
    readTeleports();
    findGnome();
    sf::Event event;
    const sf::Time timerLimit = sf::seconds(0.2f);
    sf::Clock clock;
    sf::Time deltaTimePlayer, deltaTimeGnomes;

    m_caption.updateLevel();
    m_caption.updateTime(-5);
    while (window.isOpen()) 
    {

        setHalo();  
        window.clear();
        m_board.draw(window);
        window.draw(m_playerHalo);
        m_caption.draw(window);
        window.display();

        if (m_caption.getTime() <= 0)
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            if (clock.getElapsedTime() > timerLimit)
                clock.restart();

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    switchCharacter();
                    if(typeid(*m_character[m_currChar]) == typeid(Gnome))
                        switchCharacter();
                }   

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Right);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Down);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Left);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Up);

                if (!manageCollisions(m_currChar, deltaTimePlayer, clock))
                    m_character[m_currChar]->setLocation(m_character[m_currChar]->getLastLoc());

                if (m_won || m_caption.getTime() == 0)
                    window.close();
            }
        } 

        for (int i = 0; i < m_gnomes.size(); i++)
        {
            if (!manageCollisions(m_gnomes[i], deltaTimeGnomes, m_clocks[i]))
            {
                m_character[m_gnomes[i]]->setLocation(m_character[m_gnomes[i]]->getLastLoc());
                m_character[m_gnomes[i]]->setDirection(sf::Keyboard::Up);
            } 
        }
    }
}

void Controller::switchCharacter()
{
    m_currChar = ++m_currChar % (PLAYABLE + m_gnomes.size()); 
}

void Controller::loadTextures()
{
    for (int i = 0; i < NUM_OF_PICS; i++)
        m_textures[i].loadFromFile(objectTextures[i]);
}

void Controller::findGnome()
{
    for (int i = 0; i < m_character.size(); i++)
    {
        if (typeid(*m_character[i]) == typeid(Gnome))
        {
            m_gnomes.push_back(i);
            m_clocks.push_back(sf::Clock());
            m_character[i]->setDirection(sf::Keyboard::Up);
        }
    }  
}

bool Controller::manageCollisions(int currChar , sf::Time& deltaTime, sf::Clock& clock)
{
    
    m_character[currChar]->setLastLoc(m_character[currChar]->getLocation());
    deltaTime = clock.restart();
    m_character[currChar]->movePlayer(deltaTime);

    if (!locationAllowed(*m_character[currChar]))
        return false;

    for (auto& character : m_character)
    {
        if (m_character[currChar]->checkCollision(*character))  
            return false;
    }

    for (auto& tile : m_tiles )
    {
        if (tile != nullptr && m_character[currChar]->checkCollision(*tile))
        {
            m_character[currChar]->handleCollision(*tile);
            switch (tile->getDispatch())
            {                
            case CollisionStatus::Not_Valid:
                return false;

            case CollisionStatus::Won:
                m_won = true;
                break;

            case CollisionStatus::Ogre:
                m_tiles.push_back(std::make_unique<Key>(tile->getLocation(), m_textures[load_Key]));
                [[fallthrough]];
            case CollisionStatus::Destroy:
                eraseObject(*tile);
                break;
            
            case CollisionStatus::Teleport:
                m_character[currChar]->setLocation(locateTeleport(*tile));
                return true;

            case CollisionStatus::OnTeleport:
                return true;
            }
        }
    }
    if(m_character[currChar]->isTp())
        m_character[currChar]->teleported();
    return true;
}

void Controller::eraseObject(StaticObject& staticObj)
{
    auto staticPtr = m_tiles.begin();
    for (; staticPtr != m_tiles.end(); staticPtr++)
    {
        if ((*staticPtr)->getLocation() == staticObj.getLocation())
        {
            m_tiles.erase(staticPtr);
            break;
        }
    }
}

bool Controller::locationAllowed(MovingObject& shape) 
{
    auto temp = shape.getSprite().getGlobalBounds();
    if (temp.width + temp.left > WINDOW_WIDTH || temp.left < 0 ||
        temp.height + temp.top > WINDOW_HEIGHT - BAR_SIZE || temp.top < 0)
        return false;

    return true;
}

sf::Vector2f Controller::locateTeleport(const StaticObject& teleport)
{
    // every teleport built in a vector, the friend of a teleport is hes neighbor in the vecotr,
    // if the position of a teleport in the array is odd hes friend in  index -1
    // if the index is even hes friend in index +1
    for (int i = 0; i < m_teleport.size(); ++i)
    {
        if (teleport.getLocation() == m_teleport[i])
        {
            if (i % 2 == 0)
                return m_teleport[++i];
            else
                return m_teleport[--i];
        }
    }
    return sf::Vector2f();
}

void Controller::readTeleports()
{
    for (auto& tile : m_tiles)
    {
        if (typeid(*tile) == typeid(Teleport))
            m_teleport.push_back(sf::Vector2f(tile->getLocation()));
    }
}

void Controller::setHalo()
{
    m_playerHalo.setOutlineColor(sf::Color((10, 20, 255, 100)));
    m_playerHalo.setOutlineThickness(4);
    m_playerHalo.setFillColor(sf::Color::Transparent);
    int sizeY, sizeX;
    sizeX = m_character[m_currChar]->getSprite().getScale().x * 100;
    sizeY = m_character[m_currChar]->getSprite().getScale().y * 100;
    m_playerHalo.setSize(sf::Vector2f(sizeX, sizeY));
    m_playerHalo.setPosition(m_character[m_currChar]->getLocation());
}

Controller::~Controller()
{
    for (int i = 0; i < m_character.size(); i++)
        m_character[i].release();
}