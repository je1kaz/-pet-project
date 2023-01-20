#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Race.h"
#include "Line.h"

void raceShow();
void lineShow();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0;
	while (choice != 3)
	{
		std::cout << std::endl;
		std::cout << "1.Перше завдання - Гонки(Демонстрація роботи)." << std::endl;
		std::cout << "2.Друге завдання - Пряма(Демонстрація роботи)." << std::endl;
		std::cout << "3.Вихід." << std::endl << std::endl;
		std::cout << "Ваш вибір: ";
		std::cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			std::cout << "Неправильний введення! Ваш вибір: ";
			std::cin >> choice;
		}
		switch (choice)
		{
		case 1:
			raceShow();
			break;
		case 2:
			lineShow();
			break;
		}
	}
}