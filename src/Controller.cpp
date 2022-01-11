#include "Controller.h"

Controller::Controller()
    :m_board(), m_currChar(0) , m_caption(), m_numOfGnomes(0)
{}

void Controller::run(sf::RenderWindow& window)
{
    Resources::instance().playSound(start_sound);
    m_board = Board(WINDOW_WIDTH, WINDOW_HEIGHT - BAR_SIZE, sf::Vector2f(0, 0));
    m_board.loadNextLevel(m_character, m_tiles);
    readTeleports();
    findGnome();

    sf::Event event;
    const sf::Time timerLimit = sf::seconds(0.1f);
    sf::Clock clock;
    sf::Time deltaTimePlayer, deltaTimeGnomes;

    m_caption.updateLevel();
    m_caption.updateTime(100);

    bool played_countdown = false;

    Resources::instance().playMusic();

    while (window.isOpen()) 
    {
        window.clear();
        m_board.resizeObjects(m_character, m_tiles);
        m_board.setHalo(m_character[m_currChar]);
        m_board.draw(window, m_character, m_tiles);
        m_caption.draw(window);
        window.display();

        if (m_caption.getTime() <= 4 && !played_countdown)
        {
            Resources::instance().playSound(countdown_sound);
            played_countdown = true;
        }

        if (m_caption.getTime() <= 0)
            return;

        while (window.pollEvent(event))
        {

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            { 
                if(!PauseMenu(window))
                    return;
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    switchCharacter();
                    if( m_character[m_currChar] == nullptr || typeid(*m_character[m_currChar]) == typeid(Gnome))
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
            }          

        }      
        
        if (clock.getElapsedTime() >= timerLimit)
            clock.restart();

        switch (event.type)
        {
        case sf::Event::KeyPressed:
            movementManger(m_currChar, deltaTimePlayer, clock);
            break;
        }

        for (int i = 0; i < m_gnomes.size(); i++)
            if(!movementManger(m_gnomes[i], deltaTimeGnomes, m_clocks[i]))
                m_character[m_gnomes[i]]->setDirection(sf::Keyboard::Up);
        
        if (m_won)
        {
            handleVictory(window);
            if(!m_board.loadNextLevel(m_character, m_tiles))
                return;
        }
    }
}

void Controller::handleVictory(sf::RenderWindow& window)
{
    clearLastLevel();
    window.clear();
    m_won = false;
    m_caption.updateLevel();
    m_caption.resetTime();
    m_caption.updateTime(200);
    readTeleports();
    findGnome();
}

bool Controller::movementManger(int currChar, sf::Time& deltaTime, sf::Clock& clock)
{
    m_character[currChar]->setLastLoc(m_character[currChar]->getLocation());
    deltaTime = clock.restart();
    m_character[currChar]->movePlayer(deltaTime);
    if (!manageCollisions(currChar))
    {
        m_character[currChar]->setLocation(m_character[currChar]->getLastLoc());
        return false;
    }
    return true;
}

void Controller::switchCharacter()
{
    m_currChar = ++m_currChar % (PLAYABLE + m_numOfGnomes); 
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
    m_numOfGnomes = m_gnomes.size();
}

bool Controller::manageCollisions(int currChar)
{
    if (!locationAllowed(*m_character[currChar]))
        return false;

    for (auto& character : m_character)
    {
        if (character != nullptr && m_character[currChar]->checkCollision(*character))  
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
                Resources::instance().playSound(victory_sound);
                m_won = true;
                break;

            case CollisionStatus::Ogre:
                Resources::instance().playSound(ogre_sound);
                m_tiles.push_back(std::make_unique<Key>(tile->getLocation(), *Resources::instance().getTexture('F')));
                [[fallthrough]];

            case CollisionStatus::Destroy:
                eraseObject(*tile);
                break;
            
            case CollisionStatus::Teleport:
                if (!m_character[currChar]->isTp())
                {
                    Resources::instance().playSound(teleport_sound);
                    auto newLoc = locateTeleport(*tile);
                    if (newLoc == sf::Vector2f(0, 0))
                        return true;
                    m_character[currChar]->setLocation(newLoc);
                    m_character[currChar]->teleported();
                }
                return true;

            case CollisionStatus::Gift:
                manageGifts(*tile);
                eraseObject(*tile);
                break;
            }
        }
    }
    if (m_character[currChar]->isTp())
    {
        m_character[currChar]->teleported();
        for (int i = 0; i < m_teleport.size(); i++)
            m_teleport[i].m_isUsed = false;
    }
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
        if (teleport.getLocation() == m_teleport[i].m_loc)
        {
            if (m_teleport[i].m_isUsed)
                return sf::Vector2f(0,0);

            if (i % 2 == 0)
            {
                m_teleport[i].m_isUsed = true;
                return m_teleport[++i].m_loc;
            }  
            else
            {
                m_teleport[i].m_isUsed = true;
                return m_teleport[--i].m_loc;
            }
        }
    }
    return sf::Vector2f();
}

void Controller::readTeleports()
{
    for (auto& tile : m_tiles)
    {
        if (typeid(*tile) == typeid(Teleport))
            m_teleport.push_back(TeleportInfo(tile->getLocation()));
    }
}

void Controller::clearLastLevel()
{
    m_character.clear();
    m_tiles.clear();
    m_gnomes.clear();
    m_teleport.clear();
}

void Controller::manageGifts(StaticObject& tile)
{
    Gift* giftPtr = dynamic_cast<Gift*> (&tile);
    switch(giftPtr->getType())
    {
    case GiftTypes::RemGnomes:
        eraseGnomes();
        break;

    case GiftTypes::TimeAdd:
        m_caption.updateTime(20);
        break;

    case GiftTypes::TimeDec:
        m_caption.updateTime(-20);
        break;
    }
}

void Controller::eraseGnomes()
{
    Resources::instance().playSound(gnome_sound);
    for (int i = 0; i < m_gnomes.size(); i++)
        m_character[m_gnomes[i]].release();
   
    m_gnomes.clear();
}

bool Controller::PauseMenu(sf::RenderWindow& window)
{
    sf::Clock clock;
    clock.restart();
    while (window.isOpen())
    {
        Resources::instance().drawPauseScreen(window);
        window.display();
        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_caption.updateTime(clock.getElapsedTime().asSeconds());
                return true;
            }
            
            switch (event.type)
            {
                
            case sf::Event::MouseButtonReleased:
                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

               if(event.mouseButton.button == sf::Mouse::Button::Left)
               {
                   auto buttonClicked = Resources::instance().HandleClick(location);

                   if (buttonClicked == Home)
                       return false;
                   else if (buttonClicked == Restart)
                   {
                       clearLastLevel();
                       window.clear();
                       m_caption.resetTime();
                       m_caption.updateTime(100);
                       m_board.RestartLevel(m_character, m_tiles);
                       readTeleports();
                       findGnome();
                       return true;
                   }
                   else if (buttonClicked != Music)
                   {
                       m_caption.updateTime(clock.getElapsedTime().asSeconds());
                       return true;
                   }
               }
            }
        }
    }
    m_caption.updateTime(clock.getElapsedTime().asSeconds());
    return true;
}