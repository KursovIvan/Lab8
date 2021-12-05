#pragma once
#include "Figure.h"
#include <math.h>

//клас слона
class Bishop : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//проверяем находиться ли фигура по любой диагонали от слона
		bool result = ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A));
		PLOG_INFO << "Is Threaten: " << result;
		return result;
	}
	bool Move(Figure A) override
	{
		PLOG_INFO << "Bishop.Move() Started";
		if (ColorMatch(A))
		{
			int i = 0;
			while (i < 4)
			{
				//проверка следит чтобы слон не вышел за пределы шахматной доски
				if ((this->xCurrent < boardSize + 1) && (this->yCurrent < boardSize + 1) && (this->xCurrent > 0) && (this->yCurrent > 0))
				{	
					PLOG_INFO << "New Temporary Coordinates: x: " << this->xCurrent << " | y: " << this->yCurrent;
					//двигаем слона поочередно по одной из диагоналей
					if (this->IsThreaten(A))
					{
						PLOG_INFO << " New coordinates: x: " << this->xCurrent << " | y: " << this->yCurrent;
						PLOG_INFO << "Bishop.Move() Completed With True";
						return true;
					}
					if (i == 0)
					{
						this->xCurrent--;
						this->yCurrent--;
					}
					else if (i == 1)
					{
						this->xCurrent++;
						this->yCurrent--;
					}
					else if (i == 2)
					{
						this->xCurrent++;
						this->yCurrent++;
					}
					else if (i == 3)
					{
						this->xCurrent--;
						this->yCurrent++;
					}						
				}
				else
				{
					this->xCurrent = this->xInitial;
					this->yCurrent = this->yInitial;
					i++;
				}
			}
		}
		PLOG_INFO << "Bishop.Move() Completed With False";
		return false; //если цвет клеток двух фигур отличается, то слон не сможет дойти до другой фигуры
	}
};