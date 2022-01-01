#include "Board.h"

Board::Board()
	:m_rows(0), m_cols(0), m_height(0), m_width(0), m_location(sf::Vector2f()), m_character(), m_textures(), m_tiles()
{}

Board::Board(int width, int height, sf::Vector2f location,
	std::vector < std::unique_ptr <MovingObject >>& vect, 
	std::vector < std::unique_ptr <StaticObject >>& tiles
	,sf::Texture textures[])
	: m_height(height), m_width(width), m_location(location), m_rows(0), m_cols(0), m_character(&vect), m_textures(textures),
	  m_tiles(&tiles), m_texture(sf::Texture()), m_bg(sf::Sprite())
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
	m_texture.loadFromFile("gamebg.png");
	resizeObjects();
	//m_bg.setTexture(m_texture);
}

void Board::buildTiles()
{
	//auto size = float(m_height - 10) / ((m_rows > m_cols ? m_rows : m_cols) + 1);
	int tileWidth = m_width / m_cols , tileHeight = m_height / m_rows ;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols ; j++)
		{
			if (m_matrix[i][j] != ' ')
			{
				auto locationVector = sf::Vector2f(m_location.x + j * (tileWidth) + 5 , m_location.y + i * (tileHeight) + 5 );
				createObject(m_matrix[i][j], locationVector, getTexture(m_matrix[i][j]));
			}
		}
	}
}

void Board::resizeObjects()
{
	auto newHeight = m_height / m_rows;
	auto newWidth = m_width / m_cols ;

	for (auto& moveable : *m_character)
	{
		moveable->setSpriteScale(newWidth - 5.0, newHeight - 5.0);
	}

	for (auto& unmoveable : *m_tiles)
	{
		unmoveable->setSpriteScale(newWidth,newHeight);
	}
}

void Board::draw(sf::RenderWindow& window)
{
	m_bg.setTexture(m_texture);
	window.draw(m_bg);

	// print the characters
	for (int i = 0; i < m_character[0].size(); i++)
		if (m_character[0][i] != nullptr)
			m_character[0][i]->draw(window);

	// print the tiles
	for (int j = 0; j < m_tiles[0].size(); j++)
		if(m_tiles[0][j] != nullptr)
			m_tiles[0][j]->draw(window);
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
	case 'F': return m_textures[load_Key];
	case '=': return m_textures[load_Wall];
	case '@': return m_textures[load_Throne];
	case '#': return m_textures[load_Gate];
	case '!': return m_textures[load_Orge];
	case '*': return m_textures[load_Fire];
	case '^': return m_textures[load_Gnome];
	}
}

static std::unique_ptr<MovingObject> createMovableObject(char c, const sf::Vector2f& vect, const sf::Texture& texture)
{
	switch (c)
	{
	case 'K': return std::make_unique<King>(vect, texture);
	case 'M': return std::make_unique<Mage>(vect, texture);
	case 'W': return std::make_unique<Warrior>(vect, texture);
	case 'T': return std::make_unique<Thief>(vect, texture);
	case '^': return std::make_unique<Gnome>(vect, texture);
	}
	return nullptr;
}

static std::unique_ptr<StaticObject> createUnmovableObject(char c, const sf::Vector2f& vect, const sf::Texture& texture)
{
	switch (c)
	{
	case 'X': return std::make_unique<Teleport>(vect, texture);
	case 'F': return std::make_unique<Key>(vect, texture);
	case '=': return std::make_unique<Wall>(vect, texture);
	case '@': return std::make_unique<Throne>(vect, texture);
	case '#': return std::make_unique<Gate>(vect, texture);
	case '!': return std::make_unique<Ogre>(vect, texture);
	case '*': return std::make_unique<Fire>(vect, texture);
	}
	return nullptr;
}

void Board::createObject(char c, const sf::Vector2f& vect, const sf::Texture& texture)
{
	std::unique_ptr<MovingObject> movable = createMovableObject(c, vect, texture);
	if (movable)
	{
		m_character->push_back(std::move(movable));
		return;
	}
	else
	{
		std::unique_ptr<StaticObject> unmovable = createUnmovableObject(c, vect, texture);
		if (unmovable)
		{
			m_tiles->push_back(std::move(unmovable));
			return;
		}
		exit(EXIT_FAILURE);
	}
}