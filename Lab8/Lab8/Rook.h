#pragma once
#include "Figure.h"

//класс ладьи
class Rook : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//проверяем находится ли фигура на прямой от ладьи 
		return ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent));
	}
	bool Move(Figure A) override
	{
		//уравниваем координату X ладьи, чтобы фигуры стояли на одной прямой
		this->xCurrent = A.xCurrent;
		return true;
	}
};