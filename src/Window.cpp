#include "Window.h"

Window::Window()
	: m_window(sf::VideoMode(1600, 800), "Save The King")
{
    for (int i = 0; i < 3; i++)
        m_buttons[i] = Button(sf::Vector2f(300, 80), m_texts[i], sf::Vector2f(800, 250 + i * 150));
    run();
}

void Window::run()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color(179, 218, 255, 255));
        draw();
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

void Window::draw()
{
    for (int i = 0; i < 3; i++)
        m_buttons[i].draw(m_window);
}