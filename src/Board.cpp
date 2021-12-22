#include "Board.h"
#include <fstream>

Board::Board()
{

}

Board::Board(std::string fileName, sf::Vector2f location)
	: m_location(location)
{
	// open the level file
	std::ifstream m_file;
	m_file.open(fileName);

	if (!m_file)
	{
		std::cout << "Error! couldn't open file\n";
		exit(EXIT_FAILURE);
	}

	// read into the board from file
	std::string line;
	int row = 0, col;
	while (std::getline(m_file, line))
	{
		std::vector <char> rowToRead;
		col = 0;
		for (char& c : line)
		{
			//read row
			if (c != '\n')
				rowToRead.push_back(c);
			// add teleport again here <><><><><>
			col++;
		}
		row++;
		m_matrix.push_back(rowToRead);
	}
	m_file.close();
}



/*sf::Sprite Board::charToSprite(char c)
{
	switch (c)
	{
	case Throne:
		//return m_matrix[load_Throne].m_sprite;
		break;
	default:
		break;
	}
}
*/


/*int Board::getRowSize() const
{
	return m_matrix.size();
}
int Board::getColSize() const
{
	return m_matrix[0].size();
}
*/



