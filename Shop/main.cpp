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

//--------------------------------------------------склад-------------------------------------------------------------

size_t storageSize = 0;
size_t maxItemSize = 299;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* coutArr = nullptr;
bool isStorageCreated = false;
//--------------------------------------------------служеб-------------------------------------------------------------
void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
void Start();
bool Login();
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
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
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
			std::cout << "1 - Добавить новый товар\n";
			std::cout << "2 - Изменить название товара\n";
			std::cout << "3 - Удалить товар\n";
			std::cout << "4 - Выход из редактора склада\n";
			Getline(choose);
			if (choose == "1")
			{

			}
			else if (choose == "2")
			{

			}
			else if (choose == "3")
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
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t"
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
		if (choose == "1")
		{



		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}

		else if (choose == "6")
		{

		}

		else if (choose == "7")
		{

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
					CreateStorage();
					system("cls");
					ShowSuperAdminMenu();
					break;
				}
				else if (choose == "2")
				{
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
