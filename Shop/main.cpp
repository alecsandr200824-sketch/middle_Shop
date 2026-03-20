#include <iostream>
#include <windows.h>
#include "system.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    Start();

    return 0;
}