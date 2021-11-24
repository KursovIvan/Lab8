#pragma once

const int boardSize = 8; //������ ����� 

//������� ������� �������������� � �������� �����
void InvalidInput()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "������������ ���� " << std::endl;
}
//����� �������������� ��������� ������
class Figure
{	
public:
	//���� ��������� ��� ������
	void SetPosition(char num, int figure1x, int figure1y)
	{
		std::cout << "������ �" << num << ": " << std::endl;
		while (true)
		{
			for (int i = 0; i < 2; i++)
			{
				int temp = 0;
				while (true)
				{
					std::cout << "������� ���������� " << (char)('X' + i) << " (����������� �����, �� ����������� " << boardSize << ")" << std::endl;
					std::cin >> temp;
					if (std::cin.fail() || std::cin.peek() != '\n' || temp > boardSize || temp < 1)
					{
						InvalidInput();
						continue;
					}
					break;
				}
				switch (i)
				{
				case 0:
				{
					xInitial = temp;
					break;
				}
				case 1:
				{
					yInitial = temp;
					break;
				}
				}
			}
			if ((xInitial != figure1x) || (yInitial != figure1y))
			{
				break;
			}
			else
			{
				InvalidInput();
				std::cout << "��� ������ ��� ������ " << std::endl;
			}
		}
		xCurrent = xInitial;
		yCurrent = yInitial;
	}
	//������� ��������� ����� ���� ����� �� ����������
	virtual bool ColorMatch(Figure A) 
	{
		return ((this->xCurrent + this->yCurrent) % 2 == (A.xCurrent + A.yCurrent) % 2);
	};
	//���������� true ���� ������ ������ �������� ������ ������
	virtual bool IsThreaten(Figure A) 
	{
		return false;
	};
	//���������� true ���� �� ������ ������ ����� ����� � ������� ���� �����
	virtual bool Move(Figure A) 
	{
		return false;
	};
	//��������� ����������
	int xInitial;
	int yInitial;
	//���������� ����� �������
	int xCurrent;
	int yCurrent;
};