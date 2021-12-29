#include "Controller.h"
#include <iostream>
int stepCounter;
bool key, won;

Controller::Controller()
    :m_board(), m_currChar(0)
{
    loadTextures();
   // m_board = Board(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Vector2f(0, 0), m_character, m_textures);
}

void Controller::run(sf::RenderWindow& window)
{
    m_board = Board(WINDOW_WIDTH, WINDOW_HEIGHT - BAR_SIZE, sf::Vector2f(0, 0), m_character, m_tiles, m_textures);
    sf::Event event;
    const sf::Time timerLimit = sf::seconds(0.2f);
    sf::Clock clock;
    while (window.isOpen()) {

        window.clear(sf::Color(179, 218, 255, 255));
        m_board.draw(window);
        window.display();

        while (window.pollEvent(event))
        {
            if (clock.getElapsedTime() > timerLimit)
                clock.restart();

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                //return
                window.close();
                break;
            }

            sf::Time deltaTime;
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    switchCharacter();

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Right);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Down);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Left);

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    m_character[m_currChar]->setDirection(sf::Keyboard::Up);

                if (!manageCollisions(deltaTime, clock))
                    m_character[m_currChar]->setLocation(m_character[m_currChar]->getLastLoc());

                if (m_won)
                    window.close();
            }
        }
        
    }
}

void Controller::switchCharacter()
{
    m_currChar = ++m_currChar % PLAYABLE;
}

void Controller::loadTextures()
{
    for (int i = 0; i < NUM_OF_PICS; i++)
        m_textures[i].loadFromFile(objectTextures[i]);
}

bool Controller::manageCollisions(sf::Time& deltaTime, sf::Clock& clock)
{
    m_character[m_currChar]->setLastLoc(m_character[m_currChar]->getLocation());
    deltaTime = clock.restart();
    m_character[m_currChar]->movePlayer(deltaTime);

    if (!locationAllowed(*m_character[m_currChar]))
        return false;

    for (auto& character : m_character)
    {
        if (m_character[m_currChar]->checkCollision(*character))  
            return false;
    }
    for (auto& tile : m_tiles )
    {
        if (tile != nullptr && m_character[m_currChar]->checkCollision(*tile))
        {
            m_character[m_currChar]->handleCollision(*tile);

            if (tile->getDispatch() == CollisionStatus::Destroy)
                eraseObject(*tile);

            else if (tile->getDispatch() == CollisionStatus::Not_Valid)
                return false;

            else if (tile->getDispatch() == CollisionStatus::Won)
            {
                m_won = true;
                return true;
            }
            /*else if (tile->getDispatch() == CollisionStatus::Teleport)
            {
                m_character[m_currChar]->setLocation(locateTeleport(*tile));
                return true;
            }*/
        }
    }
    return true;
}

Controller::~Controller()
{
    for (int i = 0; i < m_character.size(); i++)
        m_character[i].release();
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

void Controller::ChangeTile(StaticObject& staticObj)
{

}

bool Controller::locationAllowed(MovingObject& shape) 
{
    auto temp = shape.getSprite().getGlobalBounds();
    if (temp.width + temp.left > WINDOW_WIDTH || temp.left < 0) {
        return false;
    }
    if (temp.height + temp.top > WINDOW_HEIGHT - BAR_SIZE || temp.top < 0) {
        return false;
    }
    return true;
}
/*
sf::Vector2f Controller::locateTeleport(const StaticObject& teleport)
{
    // every teleport built in a vector, the friend of a teleport is hes neighbor in the vecotr,
    // if the position of a teleport in the array is odd hes friend in  index -1
    // if the index is even hes friend in index +1
    for (int i = 0; i < m_teleport.size(); ++i)
    {
            if (i % 2 == 0)
                return m_teleport[++i]->getLocation();
            else
                return m_teleport[--i]->getLocation();
    }
    return sf::Vector2f();
}

void Controller::readTeleports()
{
    for (auto& tile : m_tiles)
    {
        if (typeid(tile) == typeid(Teleport))
            m_teleport.push_back(tile);
    }
}*/