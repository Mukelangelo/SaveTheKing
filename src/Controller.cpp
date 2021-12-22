#include "Controller.h"

int stepCounter;
bool key, won;

Controller::Controller(sf::RenderWindow& window)
:m_board() , m_window(&window)
{}

void Controller::run()
{    
    sf::Event event;
    while (m_window->isOpen()) {
        while (m_window->pollEvent(event))
        {
            m_window->clear(sf::Color(179, 218, 255, 255));
            m_window->display();

            // Window closed or escape key pressed: exit

            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window->close();
                break;
            }
            //float deltaTime = clock.restart().asSeconds();

            /* Move the player's paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                (m_character.getPosition().y - paddleSize.y / 2 > 5.f))
            {
                leftPaddle.move(0.f, -paddleSpeed * deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                (leftPaddle.getPosition().y + paddleSize.y / 2 < gameHeight - 5.f))
            {
                leftPaddle.move(0.f, paddleSpeed * deltaTime);
            }

            break;
            */
        }
    }

}

void Controller::loadTextures()
{
	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(objectTextures[i]);
}
