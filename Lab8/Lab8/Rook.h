﻿#pragma once
#include "Figure.h"

//класс ладьи
class Rook : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//проверяем находится ли фигура на прямой от ладьи 
		bool result = ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent));
		PLOG_INFO << "Is Threaten: " << result;
		return result;
	}
	bool Move(Figure A) override
	{
		//уравниваем координату X ладьи, чтобы фигуры стояли на одной прямой
		this->xCurrent = A.xCurrent;
		PLOG_INFO << "New Coordinates: x: " << xCurrent << " | y: " << yCurrent;
		return true;
	}
};