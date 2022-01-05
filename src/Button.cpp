#include "Button.h"

Button::Button()
{}

Button::Button(const sf::Vector2f& size, sf::String text, const sf::Vector2f& pos)
    : m_button(size), m_color(126, 214,223,255),
    m_font(sf::Font()), m_text(text)
{
    
    m_font.loadFromFile("C:/Windows/Fonts/Comic.ttf");
    m_button.setFillColor(m_color);

    auto location = sf::Vector2f(pos.x, pos.y + 10);

    m_button.setPosition(location);
    m_button.setOutlineColor(sf::Color(96, 163, 188));
    m_button.setOutlineThickness(3);
    m_button.setOrigin(sf::Vector2f(size.x/2, size.y/2));
}

void Button::draw(sf::RenderWindow& window)
{
    // text in middle of the button
    auto text = sf::Text(m_text, m_font);
    text.Bold;
    text.setOutlineColor(sf::Color(7, 153, 146,250));
    text.setOutlineThickness(2);
    text.setCharacterSize(30);
    text.setColor(sf::Color(199, 236, 238.255));
    text.setPosition(m_button.getPosition());

    auto textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);

    window.draw(m_button);
    window.draw(text);
}

bool Button::handleClick(const sf::Vector2f& location)
{
    if (m_button.getGlobalBounds().contains(location))
        return true;

    return false;
}

void Button::setString(sf::String text)
{
    m_text = text;
}

sf::String Button::getString() const
{
    return m_text;
}

void Button::setColor(sf::Color color)
{
    m_button.setFillColor(color);
}

void Button::setColor()
{
    m_button.setFillColor(m_color);
}

sf::FloatRect Button::getGlobalBounds() const
{
    return m_button.getGlobalBounds();
}