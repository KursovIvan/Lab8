#pragma once
#include "Figure.h"

//����� �����
class Rook : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//��������� ��������� �� ������ �� ������ �� ����� 
		return ((this->xCurrent == A.xCurrent) || (this->yCurrent == A.yCurrent));
	}
	bool Move(Figure A) override
	{
		//���������� ���������� X �����, ����� ������ ������ �� ����� ������
		this->xCurrent = A.xCurrent;
		return true;
	}
};