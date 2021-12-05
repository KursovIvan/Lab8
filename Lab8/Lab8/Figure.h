#pragma once

const int boardSize = 8; //размер доски 

//функция выводит предупреждение о неверном вводе
void InvalidInput()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "Некорректный ввод " << std::endl;
	PLOG_ERROR << "Error";
}
//класс неопределенной шахматной фигуры
class Figure
{	
public:
	//ввод координат для фигуры
	void SetPosition(char num, int figure1x, int figure1y)
	{
		std::cout << "Фигура №" << num << ": " << std::endl;
		PLOG_INFO << "Figure № " << num;
		while (true)
		{
			for (int i = 0; i < 2; i++)
			{
				int temp = 0;
				while (true)
				{
					std::cout << "Введите координату " << (char)('X' + i) << " (натуральное число, не превышающее " << boardSize << ")" << std::endl;
					std::cin >> temp;
					PLOG_INFO << "Temporary Coordinate: " << temp;
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
					PLOG_INFO << "xInitial: " << xInitial;
					break;
				}
				case 1:
				{
					yInitial = temp;
					PLOG_INFO << "yInitial: " << yInitial;
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
				std::cout << "Эта клетка уже занята " << std::endl;
			}
		}
		xCurrent = xInitial;		
		yCurrent = yInitial;		
	}
	//функция проверяет цвета двух фигур на сходимость
	virtual bool ColorMatch(Figure A) 
	{
		bool result = ((this->xCurrent + this->yCurrent) % 2 == (A.xCurrent + A.yCurrent) % 2);
		PLOG_INFO << "Color Math: " << result;
		return result;
	};
	//возвращает true если данная фигура угрожает другой фигуре
	virtual bool IsThreaten(Figure A) 
	{
		return false;
	};
	//возвращает true если до другой фигуры можно дойти с помощью двух ходов
	virtual bool Move(Figure A) 
	{
		return false;
	};
	//начальные координаты
	int xInitial;
	int yInitial;
	//координаты новой позиции
	int xCurrent;
	int yCurrent;
};