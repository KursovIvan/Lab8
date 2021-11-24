#pragma once
#include "Figure.h"
#include <math.h>

//����� �����
class Queen : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//��������� ���������� �� ������ �� ����� ��������� ��� �� ������ ����� �� �����
		return ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent) 
			    || ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A)));
	}
	bool Move(Figure A) override
	{
		//���������� ���������� X �����, ����� ������ ������ �� ����� ������
		this->xCurrent = A.xCurrent;
		return true;
	}
};