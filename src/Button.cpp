#include "Button.h"

Button::Button()
{}

Button::Button(const sf::Vector2f& size, sf::String text, const sf::Vector2f& pos)
    : m_button(size), m_color(126, 214,223,255),
    m_font(sf::Font()), m_text(text)
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    m_button.setFillColor(m_color);
    auto location = sf::Vector2f(pos.x, pos.y + 10);
    m_button.setPosition(location);
    m_button.setOutlineColor(sf::Color::White);
    m_button.setOutlineThickness(2);
    m_button.setOrigin(sf::Vector2f(size.x/2, size.y/2));
}

void Button::draw(sf::RenderWindow& window)
{
    // text in middle of the button
    auto text = sf::Text(m_text, m_font);
    text.setCharacterSize(20);
    text.setColor(sf::Color::White);

    //text.setPosition(m_button.getSize() / 2.0f + m_button.getPosition());

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
