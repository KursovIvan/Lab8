#pragma once
#include "Figure.h"
#include <math.h>

//����� ����
class Knight : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//��������� ��������� �� ������ � �� ����� �� 8 ��������� ��� ����� ���� �������
		return (((abs(this->xCurrent - A.xCurrent) == 2) && (abs(this->yCurrent - A.yCurrent) == 1))
				|| ((abs(this->xCurrent - A.xCurrent) == 1) && (abs(this->yCurrent - A.yCurrent) == 2)));
	}
	bool Move(Figure A) override
	{
		for (int i = 0; i < 8; i++)
		{
			//�������� ������ ����� ���� �� ����� �� ������� ��������� �����
			if ((this->xCurrent < boardSize + 1) && (this->yCurrent < boardSize + 1) && (this->xCurrent > 0) && (this->yCurrent > 0))
			{
				//���� ����� ��������� � ������ ������������, ������� ��� ���������� � ������ �����������
				if (this->IsThreaten(A))
				{
					return true;
				}
				this->xCurrent = this->xInitial;
				this->yCurrent = this->yInitial;
				if (i == 0)
				{
					this->xCurrent += 2;
					this->yCurrent += 1;
				}
				else if (i == 1)
				{
					this->xCurrent += 2;
					this->yCurrent -= 1;
				}
				else if (i == 2)
				{
					this->xCurrent += 1;
					this->yCurrent += 2;
				}
				else if (i == 3)
				{
					this->xCurrent += 1;
					this->yCurrent -= 2;
				}
				else if (i == 4)
				{
					this->xCurrent -= 2;
					this->yCurrent -= 1;
				}
				else if (i == 5)
				{
					this->xCurrent -= 2;
					this->yCurrent += 1;
				}
				else if (i == 6)
				{
					this->xCurrent -= 1;
					this->yCurrent -= 2;
				}
				else if (i == 7)
				{
					this->xCurrent -= 1;
					this->yCurrent += 2;
				}
			}
			else
			{
				this->xCurrent = this->xInitial;
				this->yCurrent = this->yInitial;
			}
		}
		return false;
	}
};
