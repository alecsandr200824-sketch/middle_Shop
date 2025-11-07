#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>


size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор","Администратор","Сотрудник" };

std::string* loginArr = new std::string[userSize]{ "admin","user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0],userStatus[2] };
std::string currentStatus;

void Start();
bool Login();
void CreateStorage()
{
	const size_t staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
}
inline void Getline(std::string& str);
inline void Err();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Start();
	delete[]loginArr, passArr, statusArr;

	return 0;
}



void Start()
{
	std::string choose;
	std::cout << "\n\n\nФпс до небес\n\n\n";

	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите тип склада\n1 - Готовый\n2 - Новый\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					//готовый склад
					break;
				}
				else if (choose == "2")
				{
					//создать новый склад
					break;
				}
				else
				{
					Err();
				}
			}
			
		}
		else if (currentStatus == userStatus[1])
		{
			//готовый склад
		}
		else if (currentStatus == userStatus[2])
		{
			//готовый склад
		}

	}
	else
	{
		std::cout << "Завершение работы\n";
		Sleep(2000);
		system("cls");
	}

}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Введите логин";
		Getline(login);
		std::cout << "Введите пароль";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;


		}
		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "Пользователь: " << loginArr[0] << "\n\nДобро пожаловать!\n\n";
			std::cout << "Ваш статус: " << userStatus[0] << "\n\n";
			currentStatus = statusArr[0];
			return true;
		}
		for (size_t i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь: " << loginArr[0] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: сотрудник\n\n";
				return true;
			}

		}
		Err();
		Sleep(1500);
		system("cls");

	}
}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');



}
inline void Err()
{
	std::cout << "Некорректный ввод\n\n";

}