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

void Getline(std::string& str);
void Err();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Start();


	return 0;
}



void Start()
{
	std::cout << "\n\n\nФпс до небес\n\n\n";

	if (Login())
	{
		if (currentStatus == currentStatus[0])
		{

		}
		else if (currentStatus == currentStatus[1])
		{

		}
		else if (currentStatus == currentStatus[2])
		{

		}

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
void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');



}
void Err()
{
	std::cout << "Некорректный ввод\n\n";

}