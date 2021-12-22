#include "Controller.h"

int stepCounter;
bool key, won;

Controller::Controller(sf::RenderWindow& window)
:m_board() , m_window(&window)
{
    loadTextures();
    m_character.push_back(std::make_unique< King >(sf::Vector2f(1, 1), sf::Vector2f(2, 2), m_textures[0]));
}

void Controller::run()
{    
    sf::Event event;
    const sf::Time bilbal = sf::seconds(0.2f);
    sf::Clock clock;
    while (m_window->isOpen()) {

        m_window->clear(sf::Color(179, 218, 255, 255));
        m_character[0]->draw((*m_window));
        m_window->display();

        while (m_window->pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if (clock.getElapsedTime() > bilbal)
            {
                clock.restart();
            }
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window->close();

                break;
            }
            sf::Time deltaTime;
 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                deltaTime = clock.restart();
                m_character[0]->setDirection(sf::Keyboard::Right);
                m_character[0]->movePlayer(deltaTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                deltaTime = clock.restart();
                m_character[0]->setDirection(sf::Keyboard::Down);
                m_character[0]->movePlayer(deltaTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                deltaTime = clock.restart();
                m_character[0]->setDirection(sf::Keyboard::Left);
                m_character[0]->movePlayer(deltaTime);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                deltaTime = clock.restart();
                m_character[0]->setDirection(sf::Keyboard::Up);
                m_character[0]->movePlayer(deltaTime);
            }  
        }
    }
}

void Controller::loadTextures()
{
	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(objectTextures[i]);
}
