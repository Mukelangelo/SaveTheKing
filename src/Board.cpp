#include "Board.h"

Board::Board()
	:m_rows(0), m_cols(0), m_height(0), m_width(0), m_location(sf::Vector2f())/*, m_character(), m_tiles()*/
{}

Board::Board(int width, int height, sf::Vector2f location)
	: m_height(height), m_width(width), m_location(location), m_rows(0), m_cols(0), m_bg(sf::Sprite())
{
	srand(time(NULL));

	m_file.open("levelList.txt", std::ios::in);
	if (!m_file)
		exit(EXIT_FAILURE);

	m_playerHalo.setOutlineColor(sf::Color((10, 20, 255, 100)));
	m_playerHalo.setOutlineThickness(4);
	m_playerHalo.setFillColor(sf::Color::Transparent);
}

void Board::buildTiles(std::vector < std::unique_ptr <MovingObject >>& vect,
					   std::vector < std::unique_ptr <StaticObject >>& tiles)
{
	int tileWidth = m_width / m_cols , tileHeight = m_height / m_rows ;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols ; j++)
		{
			if (m_matrix[i][j] != ' ')
			{
				auto locationVector = sf::Vector2f(m_location.x + j * (tileWidth) +3  , m_location.y + i * (tileHeight) +3 );
				createObject(m_matrix[i][j], locationVector, *Resources::instance().getTexture(m_matrix[i][j]), vect, tiles);
			}
		}
	}
}
void Board::resizeObjects(std::vector < std::unique_ptr <MovingObject >>& vect,
						  std::vector < std::unique_ptr <StaticObject >>& tiles)
{
	auto newHeight = m_height / m_rows;
	auto newWidth = m_width / m_cols ;

	for (auto& moveable : vect)
	{
		if(moveable)
			moveable->setSpriteScale(newWidth - 8.0, newHeight - 8.0);
	}

	for (auto& unmoveable : tiles)
	{
		unmoveable->setSpriteScale(newWidth,newHeight);
	}
}

void Board::draw(sf::RenderWindow& window,
				 const std::vector < std::unique_ptr <MovingObject >>& vect,
				 const std::vector < std::unique_ptr <StaticObject >>& tiles)
{
	m_bg.setTexture(*Resources::instance().getBackground(0));
	window.draw(m_bg);
	window.draw(m_playerHalo);
	
	// print the tiles
	for (int j = 0; j < tiles.size(); j++)
		if (tiles[j] != nullptr)
			tiles[j]->draw(window);

	// print the characters
	for (int i = 0; i < vect.size(); i++)
		if (vect[i] != nullptr)
			vect[i]->draw(window);


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

static std::unique_ptr<Gift> randomizeGift(const sf::Vector2f& vect, const sf::Texture& texture)
{
	static bool removedGnomes = false;
	while (1)
	{
		switch (rand() % 3)
		{
		case 0:
			return std::make_unique<TimeGift>(vect, texture);
		case 1:
			return std::make_unique<BadTimeGift>(vect, texture);
		case 2:
			if (!removedGnomes)
			{
				removedGnomes = true;
				return std::make_unique<RemoveGnomeGift>(vect, texture);	
			}
			break;
		}
	}
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
	case '%': return randomizeGift(vect,texture);
	}
	return nullptr;
}

void Board::createObject(char c, const sf::Vector2f& vect, const sf::Texture& texture,
						 std::vector < std::unique_ptr <MovingObject >>& chararcters,
						 std::vector < std::unique_ptr <StaticObject >>& tiles)
{
	std::unique_ptr<MovingObject> movable = createMovableObject(c, vect, texture);
	if (movable)
	{
		chararcters.push_back(std::move(movable));
		return;
	}
	else
	{
		std::unique_ptr<StaticObject> unmovable = createUnmovableObject(c, vect, texture);
		if (unmovable)
		{
			tiles.push_back(std::move(unmovable));
			return;
		}
	}
}

bool Board::loadNextLevel(std::vector < std::unique_ptr <MovingObject >>& vect,
						  std::vector < std::unique_ptr <StaticObject >>& tiles)
{
	m_matrix.clear();

	std::fstream levelFile;
	std::string line;
	if (std::getline(m_file, line))
	{
		levelFile.open(line, std::ios::in);
		if (levelFile)
		{
			while (std::getline(levelFile, line))
			{
				std::vector<char> row;
				for (char& c : line)
					if (c != '\n')
						row.push_back(c);
				m_matrix.push_back(row);
			}
			m_cols = m_matrix[0].size();
			m_rows = m_matrix.size();
			buildTiles(vect, tiles);
			levelFile.close();
			resizeObjects(vect, tiles);
			return true;
		}
	}
	return false;
}

void Board::setHalo(const std::unique_ptr < MovingObject >& player)
{
	int sizeY, sizeX;
	sizeX = player->getSprite().getScale().x * 100;
	sizeY = player->getSprite().getScale().y * 100;
	m_playerHalo.setSize(sf::Vector2f(sizeX, sizeY));
	m_playerHalo.setPosition(player->getLocation());
}