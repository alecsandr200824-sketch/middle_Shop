#pragma once
#include <string>

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Некоректный ввод\n";
		std::cout << "Ошибка размера числа. От 1 до 9 символов включительно\n\n";
		Sleep(1500);
		return false;

	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Некоректный ввод\n";
			std::cout << "Введенные данные не являются числом\n\n";
			Sleep(1500);
			return false;

		}
	}
	return true;
}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');



}
inline void Err()
{
	std::cout << "Некорректный ввод\n\n";

}

template<typename ArrType>
void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}