#include "Menu.h"

Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save The King"), m_controller()
{
    for (int i = 0; i < 3; i++)
        m_buttons[i] = Button(sf::Vector2f(300, 80), m_texts[i], sf::Vector2f(800, 330 + i * 150));
    m_gameStart = m_need_help = false;
    m_help_bar = sf::RectangleShape(sf::Vector2f(1134, 735));
    m_help_bar.setPosition(sf::Vector2f(300, 50));
    m_help_bar.setOutlineThickness(3);
    m_help_bar.setOutlineColor(sf::Color::Black);
    auto texture = sf::Texture();
    texture.loadFromFile("help.png");

    m_help_bar.setTexture(&texture);
    auto bg_texture = sf::Texture();
    bg_texture.loadFromFile("bg.png");
    m_bg = sf::Sprite(bg_texture);
    run();
}

void Menu::run()
{
    bool need_help = false;
    while (m_window.isOpen())
    {
        if(m_gameStart)
            game();
        m_window.clear(sf::Color(179, 218, 255, 255));
        m_window.draw(m_bg);
        draw();
        if (m_need_help)
            m_window.draw(m_help_bar);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
                m_window.close();

            switch (event.type)
            {
            case sf::Event::MouseMoved:
            {
                auto loc = m_window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                handleHover(loc);
                break;
            }

            case sf::Event::MouseButtonPressed:
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    m_need_help = false;
                    handleButtons(location);
                    break;
                }
                break;
            }
        }
    }
}

void Menu::game()
{
    m_controller.run(m_window);
    m_gameStart = false;
}

void Menu::draw()
{
    for (int i = 0; i < MENU_BUTTONS; i++)
        m_buttons[i].draw(m_window);
}

void Menu::handleButtons(const sf::Vector2f& location)
{
    for (int i = 0; i < MENU_BUTTONS; i++)
    {
        if (m_buttons[i].handleClick(location)) // click on 
        {  
            switch (i)
            {
            case StartGame:
                m_gameStart = true;
                break;

            case Help:
                m_need_help = true;
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

void Menu::handleHover(const sf::Vector2f& location)
{
    m_buttons[m_lastHover].setColor();
    for (int i = 0; i < MENU_BUTTONS; i++)
    {
        if (m_buttons[i].getGlobalBounds().contains(location))
        {
            m_buttons[i].setColor(sf::Color(0, 137, 255));
            m_lastHover = i;
        }
    }
}