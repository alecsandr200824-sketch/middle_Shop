#include "utils.h"
#include <iostream>

bool IsNumber(const std::string& str)
{
    for (char c : str)
        if (!isdigit(c))
            return false;

    return true;
}

inline void Getline(std::string& str)
{
    std::getline(std::cin, str, '\n');



}

void Err()
{
    std::cout << "Некорректный ввод\n";
}
template<typename ArrType>

void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
    {
        dynamicArr[i] = staticArr[i];
    }
}