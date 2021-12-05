#pragma once
#include "Figure.h"
#include <math.h>

//класс ферзя
class Queen : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//проверяем находиться ли фигура по любой диагонали или на прямой линии от ферзя
		bool result = ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent)
			|| ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A)));
		PLOG_INFO << "Is Threaten: " << result;
		return result;
	}
	bool Move(Figure A) override
	{
		//уравниваем координату X ферзя, чтобы фигуры стояли на одной прямой
		this->xCurrent = A.xCurrent;
		PLOG_INFO << "New Coordinates: x: " << xCurrent << " | y: " << yCurrent;
		return true;
	}
};