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
    bool help_opened = false;
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color(179, 218, 255, 255));
        draw();
        if (help_opened)
        {
            auto help_bar = sf::RectangleShape(sf::Vector2f(1134, 735));
            help_bar.setPosition(sf::Vector2f(300, 50));
            help_bar.setOutlineThickness(3);
            help_bar.setOutlineColor(sf::Color::Black);
            auto texture = sf::Texture();
            texture.loadFromFile("help.png");
            help_bar.setTexture(&texture);
            m_window.draw(help_bar);
        }
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonPressed:
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    help_opened = false;
                    handleButtons(location, help_opened);
                    break;
                }
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

void Window::handleButtons(const sf::Vector2f& location , bool& help_opened)
{
    for (int i = 0; i < MENU_BUTTONS; i++)
    {
        if (m_buttons[i].handleClick(location)) // click on 
        {  
            switch (i)
            {
            case StartGame:
                // run the game
                break;

            case Help:
                help_opened = true;
                break;

            case Exit:
                m_window.close();
                break;
            default:
                break;
            }
        }
    }
}

void Window::open_help()
{
    auto help_bar = sf::RectangleShape(sf::Vector2f(841 , 442));
    help_bar.setPosition(sf::Vector2f(100, 100));
    auto texture = sf::Texture();
    texture.loadFromFile("help.png");
    help_bar.setTexture(&texture);
}