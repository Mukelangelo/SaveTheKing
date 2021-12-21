#include "Window.h"

Window::Window()
	: m_window(sf::VideoMode(1600, 800), "Save The King")
{
    run();
}

void Window::run()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color(179, 218, 255, 255));
        m_board.drawMenu(m_window);
       // draw(m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
    }
}