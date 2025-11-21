#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <unordered_set>


size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор","Администратор","Сотрудник" };

std::string* loginArr = new std::string[userSize]{ "admin","user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0],userStatus[2] };
std::string currentStatus;

void ChangeAccount();

//--------------------------------------------------склад-------------------------------------------------------------

size_t storageSize = 10;
size_t maxItemSize = 299;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* coutArr = nullptr;
bool isStorageCreated = false;
std::unordered_set<char> specialSymbols;
//--------------------------------------------------служеб-------------------------------------------------------------
std::unordered_set<char> passSymbols;
bool isPassSetCreated = false;
bool isSetCreated = false;
void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
void Start();
bool Login();
bool CheckPass(const std::string& str);
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
void AddNewItem();
void ChandeName();
void DeleteItem();
void ShowUsers(int mode = 0);
void AddNewUser();
bool CheckLogin(const std::string& str);
void SetSpecialSymbols();
void ChangeAccount();
void SetPassSymbols();
void AddNewUser();
void ChangePass();
template<typename ArrType>
void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize);
//--------------------------------------------------------------------------------------------------------------------------




inline void Getline(std::string& str);
inline void Err();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	
	Start();
	delete[]loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[]idArr, nameArr, coutArr, priceArr;
	}
	return 0;
}

void ChangePrice()
{
	std::string chooseId, choosePrice, choose;
	unsigned int id = 0;
	double newPrice;
	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода";
		Getline(chooseId);
		if (chooseId == "exit")
		{

			std::cout << "Отмена операции изменения цены!\n";
			Sleep(1500);
			system("cls");
			break;

		}
		std::cout << "Введите новую цену для товара";
		Getline(choosePrice);

		if (IsNumber(chooseId) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseId) - 1;
			newPrice = std::stoi(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0 || newPrice > 10000000)
			{
				std::cout << "Некорректный id или цена\nМаксимальная цена - " << 10000000 << "\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< coutArr[id] << " ---> " << coutArr[id] + newPrice << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					coutArr[id] += newPrice;
					std::cout << "Цена успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;


				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены!\n";
					Sleep(1500);
					system("cls");
				}
				else
				{
					Err();
				}
			}


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
bool CheckPass(const std::string& str)
{
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Ошибка длинны пароля\n";
		Sleep(1500);
		return false;
	}
	int numCount = 0, symCount = 0;
	std::unordered_set<char> specialPassSym{ '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\"', '\'', ',', '.', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']' };
	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Некорректный пароль\n";
			Sleep(1500);
			return false;
		}
		if (std::isdigit(sym))
		{
			numCount++;
		}
		if (specialPassSym.count(sym))
		{
			symCount++;
		}
	}

	if (numCount > 2 && symCount > 3)
	{
		return true;
	}
	else
	{
		std::cout << "Минимум 3 символа и 3 цифры\n";
		return false;
	}
}
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
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];

				FillArr(loginArrTemp, loginArr, userSize);
				FillArr(passArrTemp, passArr, userSize);
				FillArr(statusArrTemp, statusArr, userSize);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;

				std::swap(loginArrTemp, loginArr);
				std::swap(passArrTemp, passArr);
				std::swap(statusArrTemp, statusArr);
				delete[] loginArrTemp, passArrTemp, statusArrTemp;
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
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
			std::cout << "1 - Добавить новый товар\n";
			std::cout << "2 - Изменить название товара\n";
			std::cout << "3 - Удалить товар\n";
			std::cout << "0 - Выход из редактора склада\n";
			Getline(choose);
			if (choose == "1" && storageSize > 0)
			{
				AddNewItem();
			}
			else if (choose == "2" && storageSize > 0)
			{
				ChandeName();
			}
			else if (choose == "3" && storageSize > 0)
			{
				DeleteItem();
			}
			else if (choose == "4" && storageSize > 0)
			{

			}
			else
			{
				Err();
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
		Sleep(2000);
	}
}
void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0, count = 0.0;
	bool exit = true;
	while (true)
	{


		while (true)
		{
			system("cls");

			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n\n";

			std::cout << "Введите название нового товара: ";
			Getline(newName);

			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 50)
			{
				std::cout << "Максимальная длина название 50 символов\n";
				Sleep(1500);

			}
			else
			{
				break;
			}
		}
		while (exit)
		{
			std::cout << "Введите кол-во нового товара: ";
			Getline(newCount);

			if (newCount == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > maxItemSize)
				{
					std::cout << "Ошибка максимального размера товара. Не более " << maxItemSize << " ед.\n\n";

				}
				else
				{
					break;
				}

			}

		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n\n";
			std::cout << "Введите цену нового товара: ";
			Getline(newPrice);

			if (newPrice == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 10000000)
				{
					std::cout << "Ошибка максимальной цены. Не более " << 10000000 << " ед.\n\n";
					Sleep(1500);
				}
				else
				{
					break;
				}

			}

		}
		if (exit)
		{
			std::cout << "Новый товар: " << newName << "\nКол-во: " << count << "\nЦена: " << price << "/n/n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
			Getline(choose);

			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double *priceArrTemp = new double[storageSize];
				FillArr(idArrTemp, idArr, storageSize - 1);
				FillArr(nameArrTemp, nameArr, storageSize - 1);
				FillArr(countArrTemp, coutArr, storageSize - 1);
				FillArr(priceArrTemp, priceArr, storageSize - 1);
				
				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newPrice;
				priceArrTemp[storageSize - 1] = price;
				countArrTemp[storageSize - 1] = count;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(coutArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);
				
				delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Идёт подготовка...";
				Sleep(2000);
				std::cout << "Товар успешно добавлен!\n\n";
				Sleep(1500);
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n\n";
				Sleep(1500);
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

	system("pause");
	//storageSize++;
	//unsigned int* idArrTemp = new unsigned int[storageSize];
}
void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Операция удаления товара прервана!\n\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(chooseId)) 
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Удаляемый товар: " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];
					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = coutArr[c];
						priceArrTemp[i] = priceArr[c];
					}
					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(coutArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идёт подготовка...";
					Sleep(2000);
					std::cout << "Товар успешно добавлен!\n\n";
					Sleep(1500);
					break;
				}
			}
		}
	}


}
void ChandeName() 
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "Введите ID товара или \"exit\"ждя выхода: ";
		Getline(chooseId);

		if (chooseId == "exit")
		{
			std::cout << "Операция смены названия прервана!\n\n";
			Sleep(1500);
			break;
		}

		std::cout << "\tВведите название нового товара: ";

		Getline(newName);

		
		if (newName.size() <= 0 || newName.size() >= 50 || newName == "exit")
		{
			std::cout << "Максимальная длина название 50 символов\n";
			Sleep(1500);

		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "\n" << std::left << std::setw(25)
					<< nameArr[id] << " ---> " << newName << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Изменение названия успешно завершено\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
			
		}
	}
}
void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
		}
		else
		{
			ShowUsers();
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
			
			
			if (userNumber < 0 || userNumber > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			for (size_t i = 0; i < userSize; i++)
			{
				if (i == userNumber)
				{
					std::cout << "Введите новый пароль для пользователя " << loginArr[i] << ": ";
					Getline(newPass1);
					std::cout << "Подтвердите новый пароль для пользователя " << loginArr[i] << ": ";
					Getline(newPass2);
				}
			}
			

		}
	}
}
void CreateStorage()
{
	const size_t staticSize = 10;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"i5 14600kf", "rtx 5040", "ryzen 7 2700", "gt 1030", "rx 580", "i9 9900kf", "ryzen 7 7800x3d", "rtx 3080ti", "i7 7700k", "rx9070"



	};
	double price[staticSize]{ 15000, 3000, 5000, 1490.99, 3599, 12999, 28000, 40000, 7777, 25000 };
	unsigned int count[staticSize]{ 50,45,3,100,150,15,500,1,7,1000 };

	if (isStorageCreated)
	{
		delete[]idArr, nameArr, coutArr, priceArr;
	}

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	coutArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreated = true;

	FillArr(idArr, id, storageSize);
	FillArr(nameArr, name, storageSize);
	FillArr(coutArr, count, storageSize);
	FillArr(priceArr, price, storageSize);
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
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t"
			<< "Цена\t" << "Кол-во\n";
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
				<< priceArr[i] << "\t" << coutArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t" << "\n"
			<< "Кол-во\n";
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
				<< "\t" << coutArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t"
			<< "Цена\t\n";
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
				<< priceArr[i] << "\t" << "\n";
		}
		system("pause");
		system("cls");

	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t"
			<< "Цена\t\n";
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
			
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
			
		}
		else if (choose == "4" && storageSize > 0)
		{

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
void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода";
		Getline(chooseId);
		if (chooseId == "exit")
		{

			std::cout << "Отмена операции пополнения склада!\n";
			Sleep(1500);
			system("cls");
			break;

		}
		std::cout << "Введите кол-во товара для пополнения";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 299)
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во - " << maxItemSize << "\n\n";
				Sleep(1500);

			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< coutArr[id] << " ---> " << coutArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					coutArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;


				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения!\n";
					Sleep(1500);
					system("cls");
				}
				else
				{
					Err();
				}
			}
		
		
		}

		
	}

}
void RemoveStorageItem()
{
	
	
		std::string chooseId, chooseCount, choose;
		unsigned int id = 0, count = 0;
		while (true)
		{
			system("cls");
			ShowStorage(1);
			std::cout << "Введите ID товара или \"exit\" для выхода";
			Getline(chooseId);
			if (chooseId == "exit")
			{

				std::cout << "Отмена операции списания товара!\n";
				Sleep(1500);
				system("cls");
				break;

			}
			std::cout << "Введите кол-во товара для списания";
			Getline(chooseCount);

			if (IsNumber(chooseId) && IsNumber(chooseCount))
			{
				id = std::stoi(chooseId) - 1;
				count = std::stoi(chooseCount);

				if (id < 0 || id > storageSize - 1 || count < 0 || count > coutArr[id])
				{
					std::cout << "Некорректный id или кол-во\nМаксимальное кол-во - " << coutArr[id] << "\n\n";
					Sleep(1500);

				}
				else
				{
					std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
						<< coutArr[id] << " ---> " << coutArr[id] + count << "\n\n";
					std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						coutArr[id] += count;
						std::cout << "Товар успешно списан\n\n";
						Sleep(1500);
						system("cls");
						break;


					}
					else if (choose == "2")
					{
						std::cout << "Отмена списания!\n";
						Sleep(1500);
						system("cls");
					}
					else
					{
						Err();
					}
				}


			}


		}

	
}
void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редактировать персонал\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		if (choose == "1" && storageSize > 0)
		{



		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}

		else if (choose == "6")
		{
			ChangeStorage();
		}

		else if (choose == "7")
		{
			ShowUsers();
		}

		else if (choose == "8")
		{

		}

		else if (choose == "0")
		{
			break;
		}
		else
		{
			Err();
		}
		
	}


}
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
void Start()
{
	std::string choose;
	std::cout << "\n\n\nФпс до небес\n\n\n";

	if (Login())
	{
		system("cls");
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите тип склада\n1 - Готовый\n2 - Новый\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					if (isStorageCreated == false)
					{
						CreateStorage();
					}
					
					system("cls");
					ShowSuperAdminMenu();
					break;
				}
				else if (choose == "2")
				{
					if (isStorageCreated == false)
					{
						
					}
					//создать новый склад
					ShowSuperAdminMenu();
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
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
		}
		else if (currentStatus == userStatus[2])
		{
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
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

template<typename ArrType>
void FillArr(ArrType* dynamicArr, ArrType* staticArr, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
