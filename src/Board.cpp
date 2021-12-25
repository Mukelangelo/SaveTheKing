#include "Board.h"

Board::Board()
	:m_rows(0), m_cols(0), m_height(0), m_width(0), m_location(sf::Vector2f()), m_character(), m_textures()
{}

Board::Board(int width, int height, sf::Vector2f location,
	std::vector < std::unique_ptr <MovingObject >>& vect, sf::Texture textures[])
	: m_height(height), m_width(width), m_location(location), m_rows(0), m_cols(0), m_character(&vect), m_textures(textures)
{
	m_file.open("Board.txt", std::ios::in);
	// check if a file exist and not empty
	// if exist and non empty, open it, if not ask user for board size
	if (m_file)
	{
		std::string line;
		while (std::getline(m_file, line))
		{
			std::vector<char> row;
			for (char& c : line)
				if (c != '\n')// && c != ' ')
					row.push_back(c);
			m_matrix.push_back(row);
		}
		m_rows = m_matrix[0].size();
		m_cols = m_matrix.size();
		buildTiles();
		m_file.close();
	}
	m_character->push_back(std::make_unique< King >(sf::Vector2f(1, 1), sf::Vector2f(2, 2), m_textures[load_King]));
	m_character->push_back(std::make_unique< Mage >(sf::Vector2f(200, 200), m_textures[load_Mage]));
	m_character->push_back(std::make_unique< Warrior >(sf::Vector2f(300, 200), m_textures[load_Warrior]));
	m_character->push_back(std::make_unique< Thief >(sf::Vector2f(400, 350), m_textures[load_Thief]));
}

void Board::buildTiles()
{
	int tileWidth = m_width / m_cols, tileHeight = m_height / m_rows;
	for (int i = 0; i < m_rows; i++)
	{
		std::vector<sf::Sprite> tileRow;
		for (int j = 0; j < m_cols; j++)
		{
			auto tile = sf::Sprite(m_textures[0]);
			tile.setPosition(sf::Vector2f(m_location.x + (j * tileWidth) + 25, m_location.y + (i * tileHeight) + 25));
			tileRow.push_back(tile);
		}
		m_tiles.push_back(tileRow);
	}
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_character[0].size(); i++)
		m_character[0][i]->draw(window);
	for (int i = 0; i < m_tiles.size(); i++)
	{
		for (int j = 0; j < m_tiles[i].size(); j++)
			window.draw(m_tiles[i][j]);
	}
}

