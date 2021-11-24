#pragma once
#include <iostream>
#include "Figure.h"

//����� ��������� �����
class Board
{
public:
	//������� ��������� ����� �� �����
	void SetBoard(Figure* A, Figure* B)
	{
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
	}
	//������� ���������� �� �������
	void ShowInfo()
	{
		std::cout << std::endl << std::endl << black << " - ������ ������" << std::endl
			<< white << " - ����� ������" << std::endl
			<< firstFig << " - ������ ������" << std::endl
			<< secondFig << " - ������ ������" << std::endl
			<< waypoint << " - ������������� ������";
	}
private:
	char black = 'B';
	char white = 'W';
	char firstFig = '&';
	char secondFig = '@';
	char waypoint = '#';
};