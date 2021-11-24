#pragma once
#include "Figure.h"
#include <math.h>

//���� �����
class Bishop : public Figure
{
public:
	bool IsThreaten(Figure A) override
	{
		//��������� ���������� �� ������ �� ����� ��������� �� �����
		return ((abs(this->xCurrent - A.xCurrent) == abs(this->yCurrent - A.yCurrent)) && ColorMatch(A));
	}
	bool Move(Figure A) override
	{
		if (ColorMatch(A))
		{
			int i = 0;
			while (i < 4)
			{
				//�������� ������ ����� ���� �� ����� �� ������� ��������� �����
				if ((this->xCurrent < boardSize + 1) && (this->yCurrent < boardSize + 1) && (this->xCurrent > 0) && (this->yCurrent > 0))
				{	
					//������� ����� ���������� �� ����� �� ����������
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
		return false; //���� ���� ������ ���� ����� ����������, �� ���� �� ������ ����� �� ������ ������
	}
};