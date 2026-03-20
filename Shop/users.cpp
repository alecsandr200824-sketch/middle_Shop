#include "storage.h"
#include "utils.h"
#include "users.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

size_t userSize = 3;
size_t staffCount = 1;

std::string* loginArr = new std::string[userSize]{ "admin","adminOne","user" };
std::string* passArr = new std::string[userSize]{ "admin","adminOne","user" };
std::string* statusArr = new std::string[userSize]{ "Супер администратор","Администратор","Сотрудник" };

double* salesArr = new double[userSize] {0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3};

unsigned int currentId = 0;
std::string currentStatus;

std::unordered_set<char> specialSymbols;

bool isSetCreated = false;
bool isPassSetCreated = false;
void AddNewUser()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit = true;
	while (true)
	{

		while (true)
		{
			system("cls");
			std::cout << "\nВведите логин нового пользователя или \"exit\" для выхода: ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Отмена добавления нового пользователя!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы a-z, A-z, 0-9\n\n";
				Sleep(1500);
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\nВведите пароль нового пользователя или \"exit\" для выхода: ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Отмена добавления нового пользователя!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы a-z, A-z, 0-9\n\n";
				Sleep(1500);
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\nВведите пароль нового пользователя или \"exit\" для выхода: ";
			std::cout << "1 - Администратор\n2 - Сотрудник\nВвод: ";
			Getline(newPass);
			if (newPass == "exit")
			{
				Getline(choose);
				if (choose == "exit")
				{
					std::cout << "Отмена добавления нового пользователя!\n";
				}
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}
		while (exit)
		{
			std::cout << "Пользователь: " << newLogin << "\n";
			std::cout << "Роль: " << newRole << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				userSize++;
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				double* salesArrTemp = new double[userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];
				FillArr(loginArrTemp, loginArr, userSize);
				FillArr(passArrTemp, passArr, userSize);
				FillArr(statusArrTemp, statusArr, userSize);
				FillArr(salesArrTemp, salesArr, userSize);
				FillArr(userIdArrTemp, userIdArr, userSize);
				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;

				std::swap(loginArrTemp, loginArr);
				std::swap(passArrTemp, passArr);
				std::swap(statusArrTemp, statusArr);
				std::swap(salesArrTemp, salesArr);
				std::swap(userIdArrTemp, userIdArr);
				delete[] loginArrTemp, passArrTemp, statusArrTemp, salesArrTemp, userIdArrTemp;
				std::cout << "Идёт подготовка...";
				Sleep(2000);
				std::cout << "Пользователь успешно добавлен!\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}

		}
		if (exit == false)
		{
			break;
		}
	}
}
void DeleteUser()
{
	std::string chooseNumber, choose, checkPass;
	int userNumber = 0;
	int isAdmin = 0;
	while (true)
	{

		if (currentStatus == userStatus[0])
		{
			if (userSize < 2)
			{
				std::cout << "Нет допустимых пользователей для удаления\n";
				Sleep(1500);
				return;
			}
			ShowUsers();
			isAdmin = 1;
		}
		else if (currentStatus == userStatus[1])
		{
			if (staffCount < 1)
			{
				std::cout << "Нет доступных пользователей для удаления\n";
				Sleep(1500);
				return;
			}
		}


		ShowUsers();
		isAdmin = 1;

		std::cout << "\nВведите номер пользователя для удаления \"exit\" для выхода: ";
		Getline(choose);

		if (choose == "exit")
		{
			std::cout << "Отмена изменения пользователя!\n";
			Sleep(1500);
			break;
		}


		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);

			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);

			}
			for (size_t i = isAdmin; i < userSize; i++)
			{
				if (i == userNumber)
				{
					system("cls");

					if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
					{
						std::cout << "Нельзя удалять администратора\n";
						Sleep(1500);
						break;
					}

					std::cout << "Удалить пользователя: " << loginArr[i] << "\n\n";
					std::cout << "Для подтверждения введите пароль супер админа или \"exit\" для выхода: ";
					Getline(choose);

					if (choose == "exit")
					{
						std::cout << "Отмена изменения пользователя!\n";
						Sleep(1500);
						break;
					}
					else if (checkPass == passArr[0])
					{
						userSize--;
						if (statusArr[userNumber] == userStatus[2])
						{
							staffCount--;
						}
						std::string* loginArrTemp = new std::string[userSize];
						std::string* passArrTemp = new std::string[userSize];
						std::string* statusArrTemp = new std::string[userSize];
						double* salesArrTemp = new double[userSize];
						unsigned int* userIdArrTemp = new unsigned int[userSize];
						for (size_t i = 0, c = 0; i < userSize; i++, c++)
						{
							if (userNumber == c)
							{
								c++;
							}
							loginArrTemp[i] = loginArr[c];
							passArrTemp[i] = passArr[c];
							statusArrTemp[i] = statusArr[c];
							salesArrTemp[i] = salesArr[c];
							userIdArrTemp[i] = userIdArr[c];

						}
						std::swap(loginArrTemp, loginArr);
						std::swap(passArrTemp, passArr);
						std::swap(statusArrTemp, statusArr);
						std::swap(salesArrTemp, salesArr);
						std::swap(userIdArrTemp, userIdArr);

						delete[] loginArrTemp, passArrTemp, statusArrTemp;
						std::cout << "Идёт подготовка...";
						Sleep(2000);
						std::cout << "Пользователь успешно удален!\n\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Некорректный пароль\n";
						Sleep(1500);
						i--;
					}

				}
			}

		}
	}
}
void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	int isAdmin = 0;
	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}

		std::cout << "\nВведите пользователя или \"exit\" для выхода: ";
		Getline(choose);

		if (choose == "exit")
		{
			std::cout << "Отмена изменения пароля!\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);


			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			if (currentStatus == userStatus[1] && statusArr[userNumber] == userStatus[1])
			{
				std::cout << "Нельзя менять ппароли Администраторам\n";
				Sleep(1500);
				break;
			}
			for (size_t i = 0; i < userSize; i++)
			{
				if (i == userNumber)
				{
					system("cls");
					std::cout << "Введите новый пароль для пользователя " << loginArr[i] << ": ";
					Getline(newPass1);
					std::cout << "Подтвердите новый пароль для пользователя " << loginArr[i] << ": ";
					Getline(newPass2);
					if (newPass1 == newPass2)
					{
						passArr[i] = newPass1;
						std::cout << "Успешно\n";
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "Повторите попытку\n";
						Sleep(1500);
						i--;
					}
				}
			}


		}
	}
}
void ShowUsers(int mode)
{
	if (mode == 0)
	{

		system("cls");
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t" << passArr[i]
				<< "\t\t\t" << statusArr[i] << "\n";
		}
		Sleep(2000);
	}
	else if (mode == 1)
	{
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t" << passArr[i]
				<< "\t\t\t" << statusArr[i] << "\n";
		}

	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Введите логин: ";
		Getline(login);
		std::cout << "Введите пароль: ";
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
			currentId = userIdArr[0];
			return true;
		}
		for (size_t i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь: " << loginArr[0] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: сотрудник\n\n";
				currentStatus = statusArr[i];
				currentId = userIdArr[i];
				return true;
			}

		}
		Err();
		Sleep(1500);
		system("cls");

	}
}
bool Logout()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "Для подтверждения выхода из пользователя введите ваш пароль или \"exit\" для возврата в меню.";
		Getline(choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err();
		}
	}
}
void ChangeAccount()
{
	std::string choose;
	if (isSetCreated = false)
	{
		SetSpecialSymbols();
	}
	if (isPassSetCreated == false)
	{
		SetPassSymbols();
	}
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "0 - Выход из редактора аккаунтов\n";
		std::cout << "Ввод: ";
		Getline(choose);
		if (choose == "1" && storageSize > 1)
		{
			AddNewUser();
		}
		else if (choose == "2" && storageSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && storageSize > 0)
		{
			ChangePass();
		}
		else if (choose == "4" && storageSize > 0)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{

		}
		else
		{
			Err();
		}


	}
}
bool CheckLogin(const std::string& str)
{
	if (str.size() < 5 || str.size() >= 20)
	{
		std::cout << "Недопустимая длинна логинаю От 5 до 20\n";
		Sleep(1500);
		return false;
	}

	for (char sym : str)
	{
		if (!specialSymbols.count(sym))
		{
			std::cout << "Некорректные символы в логине!\n\n";
			Sleep(1500);
			return false;
		}
	}
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "Имя уже занято\n\n";
			Sleep(1500);
			return false;
		}
	}
}
void SetSpecialSymbols()
{
	for (char i = '0'; i <= '9'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = '0'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = '0'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	isSetCreated = true;
}
void SetPassSymbols()
{
	for (char i = '!'; i <= '&'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = '('; i <= '+'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = '/'; i <= '~'; i++)
	{
		specialSymbols.insert(i);
	}
	isPassSetCreated = true;
}
std::string userStatus[3]
{
	"Супер администратор",
	"Администратор",
	"Сотрудник"
};