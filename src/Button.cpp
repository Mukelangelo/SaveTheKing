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

    m_buttonText = sf::Text(m_text, m_font);
    m_buttonText.Bold;
    m_buttonText.setOutlineColor(sf::Color(7, 153, 146, 250));
    m_buttonText.setOutlineThickness(2);
    m_buttonText.setCharacterSize(30);
    m_buttonText.setColor(sf::Color(199, 236, 238.255));
    m_buttonText.setPosition(m_button.getPosition());

    auto textRect = m_buttonText.getLocalBounds();
    m_buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);

}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_buttonText);
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