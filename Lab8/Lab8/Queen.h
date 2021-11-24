#pragma once
#include "Figure.h"
#include <math.h>

//класс ферз€
class Queen : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//провер€ем находитьс€ ли фигура по любой диагонали или на пр€мой линии от ферз€
		return ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent) 
			    || ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A)));
	}
	bool Move(Figure A) override
	{
		//уравниваем координату X ферз€, чтобы фигуры сто€ли на одной пр€мой
		this->xCurrent = A.xCurrent;
		return true;
	}
};