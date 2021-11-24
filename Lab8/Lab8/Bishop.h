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
		return ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A));
	}
	bool Move(Figure A) override
	{
		if (ColorMatch(A))
		{
			int i = 0;
			while (i < 4)
			{
				//проверка следит чтобы слон не вышел за пределы шахматной доски
				if ((this->xCurrent < boardSize + 1) && (this->yCurrent < boardSize + 1) && (this->xCurrent > 0) && (this->yCurrent > 0))
				{	
					//двигаем слона поочередно по одной из диагоналей
					if (this->IsThreaten(A))
					{
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
		return false; //если цвет клеток двух фигур отличается, то слон не сможет дойти до другой фигуры
	}
};