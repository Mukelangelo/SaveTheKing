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
				if (c != '\n')
					row.push_back(c);
			m_matrix.push_back(row);
		}
		m_cols = m_matrix[0].size();
		m_rows = m_matrix.size();
		buildTiles();
		m_file.close();
	}
}

void Board::buildTiles()
{
	int tileWidth = m_width / m_cols, tileHeight = m_height / m_rows;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			if (m_matrix[i][j] != ' ')
			{
				if (checkPlayable(m_matrix[i][j]))
				{
					m_character->push_back(std::make_unique< MovingObject >(
						sf::Vector2f(m_location.x + (j * tileWidth) + 25, m_location.y + (i * tileHeight) + 25),
						getTexture(m_matrix[i][j])));
				}
				else
				{
					m_tiles.push_back(std::make_unique< StaticObject >(
						sf::Vector2f(m_location.x + (j * tileWidth) + 25, m_location.y + (i * tileHeight) + 25),
						getTexture(m_matrix[i][j])));
				}
			}
		}
	}
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_character[0].size(); i++)
		m_character[0][i]->draw(window);
	for (int j = 0; j < m_tiles.size(); j++)
		m_tiles[j]->draw(window);
}

sf::Texture& Board::getTexture(char c)
{
	switch (c)
	{
	case 'K': return m_textures[load_King];
	case 'M': return m_textures[load_Mage];
	case 'W': return m_textures[load_Warrior];
	case 'T': return m_textures[load_Thief];
	case 'X': return m_textures[load_Teleport];
	case 'F': return m_textures[0];
	case '=': return m_textures[load_Wall];
	case '@': return m_textures[load_Throne];
	case '#': return m_textures[load_Gate];
	case '!': return m_textures[load_Orge];
	case '*': return m_textures[load_Fire];
	}
}

bool Board::checkPlayable(char c)
{
	return (c == 'K') || (c == 'M') || (c == 'W') || (c == 'T');
}