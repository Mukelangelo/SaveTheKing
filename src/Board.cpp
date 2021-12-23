#include "Board.h"
#include <fstream>

Board::Board()
{}

Board::Board(int height, int width, sf::Vector2f location)
	: m_height(height), m_width(width), m_location(location)
{
	//mybe should we do this?
	// m_height(WINDOW_HEIGHT) , m_width(WINDOW_WIDTH) 
	// for full screen board and remove parameters
	
	std::ifstream m_file;
	m_file.open("Board.txt", std::ios::in);
	// check if a file exist and not empty
	// if exist and non empty, open it, if not ask user for board size

	if (!m_file || m_file.peek() <= 0)
	{
		std::cout << "please enter row and col number for the board \n";
		std::cin >> m_rows >> m_cols;
		for (int i = 0; i < m_rows; i++)
		{
			std::vector<char> row;

			for (int j = 0; j < m_cols; j++)
				row.push_back(' ');
			m_matrix.push_back(row);
		}
	}
	else
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
		m_rows = m_matrix[0].size();
		m_cols = m_matrix.size();

	}
	loadTextures();
	//buildTiles();
	m_file.close();
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
		std::vector <MovingObject> name;

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

void Board::loadTextures()
{
	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(objectTextures[i]);
}


/*void Board::charToSprite(char c)
{
	switch (c)
	{
	case King:
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



