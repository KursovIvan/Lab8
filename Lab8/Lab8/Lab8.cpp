#include <iostream>
#include <conio.h>
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Board.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	int figureType = 0;
	Figure* firstFigure = 0;
	Figure secondFigure;
	while (true)
	{
		std::cout << "Введите тип первой фигуры: "
			      << "\n\t1 - Ладья "
				  << "\n\t2 - Слон "
			      << "\n\t3 - Ферзь "
			      << "\n\t4 - Конь " << std::endl;
		std::cin >> figureType;
		if (std::cin.fail() || std::cin.peek() != '\n' || figureType > 4 || figureType < 1)
		{
			InvalidInput();
			continue;
		}
		break;
	}
	switch (figureType)
	{
	case 1:
	{
		firstFigure = new Rook;
		firstFigure->SetPosition('1', 0, 0);
		break;
	}
	case 2:
	{
		firstFigure = new Bishop;
		firstFigure->SetPosition('1', 0, 0);
		break;
	}
	case 3:
	{
		firstFigure = new Queen;
		firstFigure->SetPosition('1', 0, 0);
		break;
	}
	case 4:
	{
		firstFigure = new Knight;
		firstFigure->SetPosition('1', 0, 0);
		break;
	}
	}	
	if (firstFigure)
	{
		secondFigure.SetPosition('2', firstFigure->xInitial, firstFigure->yInitial);
		if (firstFigure->ColorMatch(secondFigure))
		{
			std::cout << "Клетки с фигурами одного цвета " << std::endl;
		}
		else
		{
			std::cout << "Клетки с фигурами разного цвета " << std::endl;
		}
		if (firstFigure->IsThreaten(secondFigure))
		{
			std::cout << "Первая фигура угрожает второй " << std::endl;
		}
		else
		{
			std::cout << "Первая фигура не угрожает второй " << std::endl;
			if (firstFigure->Move(secondFigure))
			{
				std::cout << "Первая фигура сможет достичь второй за два хода " << std::endl;
				std::cout << "Промежуточная клетка (" << firstFigure->xCurrent << "," << firstFigure->yCurrent << ") " << std::endl;
			}
			else
			{
				std::cout << "Первая фигура не сможет достичь второй за два хода " << std::endl;
			}
		}
	}
	Board board;
	board.SetBoard(firstFigure, &secondFigure);
	board.ShowInfo();
	_getch();
	return 0;
}