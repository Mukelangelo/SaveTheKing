#include "Controller.h"

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
    m_board = Board(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Vector2f(0, 0), m_character, m_textures);
    sf::Event event;
    const sf::Time timerLimit = sf::seconds(0.2f);
    sf::Clock clock;
    while (window.isOpen()) {

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
                
                deltaTime = clock.restart();
                m_character[m_currChar]->movePlayer(deltaTime);
            }
        }
        window.clear(sf::Color(179, 218, 255, 255));
        m_board.draw(window);
        window.display();
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

bool Controller::handleCollisions()
{
    for (auto& character : m_character)
    {
        if (m_character[m_currChar]->checkCollision(*character))
            return true;
    }
    return false;
}

Controller::~Controller()
{
    for (int i = 0; i < m_character.size(); i++)
        m_character[i].release();
}