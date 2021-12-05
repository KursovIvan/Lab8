#pragma once
#include <iostream>
#include "Figure.h"

//класс шахматной доски
class Board
{
public:
	//выводит шахматную доску на экран
	void SetBoard(Figure* A, Figure* B)
	{
		PLOG_INFO << "Board.SetBoard() Started";
		std::cout << std::endl;
		for (int i = 0; i < boardSize + 1; i++)
		{
			for (int j = 0; j < boardSize + 1; j++)
			{
				if (i == 0)
				{
					std::cout << j << " ";
				}
				else if (j != boardSize)
				{
					if ((A->yInitial == boardSize + 1 - i) && (A->xInitial == j + 1))
					{
						std::cout << firstFig << " ";
					}
					else if ((B->yInitial == boardSize + 1 - i) && (B->xInitial == j + 1))
					{
						std::cout << secondFig << " ";
					}
					else if ((A->yCurrent == boardSize + 1 - i) && (A->xCurrent == j + 1))
					{
						std::cout << waypoint << " ";
					}
					else if ((i + j) % 2 == 1) 
					{
						std::cout << black << " ";
					}
					else std::cout << white << " ";
				}
			}
			if (i != boardSize)
			{
				std::cout << std::endl << boardSize - i << " ";
			}
		}
		PLOG_INFO << "Board.SetBoard() Completed";
	}
	//выводит информацию по значкам
	void ShowInfo()
	{
		PLOG_INFO << "Board.ShowInfo() Started";
		std::cout << std::endl << std::endl << black << " - черная клетка" << std::endl
			<< white << " - белая клетка" << std::endl
			<< firstFig << " - первая фигура" << std::endl
			<< secondFig << " - вторая фигура" << std::endl
			<< waypoint << " - промежуточная клетка";
		PLOG_INFO << "Board.ShowInfo() Completed";
	}
private:
	char black = 'B';
	char white = 'W';
	char firstFig = '&';
	char secondFig = '@';
	char waypoint = '#';
};