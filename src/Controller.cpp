#include "Controller.h"

int stepCounter;
bool key, won;

Controller::Controller(sf::RenderWindow& window)
    :m_board(), m_window(&window), m_currChar(0)
{
    loadTextures();
    m_board = Board(600, 600, sf::Vector2f(600, 100), m_character, m_textures);
}

void Controller::run()
{
    sf::Event event;
    const sf::Time bilbal = sf::seconds(0.2f);
    sf::Clock clock;
    while (m_window->isOpen()) {

        m_window->clear(sf::Color(179, 218, 255, 255));
        m_board.draw(*m_window);
        m_window->display();

        while (m_window->pollEvent(event))
        {
            if (clock.getElapsedTime() > bilbal)
                clock.restart();

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window->close();
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

Controller::~Controller()
{
    for (int i = 0; i < m_character.size(); i++)
        m_character[i].release();
}