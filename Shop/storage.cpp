#include <iomanip>
#include "utils.h"
#include "users.h"
#include "storage.h"
#include <iostream>
#include <windows.h>

size_t storageSize = 10;
size_t maxItemSize = 299;

unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* coutArr = nullptr;
size_t storageSize = 10;
size_t maxItemSize = 299;

unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
double* priceArr = nullptr;
unsigned int* coutArr = nullptr;

bool isStorageCreated = false;
bool isStorageCreated = false;

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
void CreateEmptyStorage()
{
	// если склад уже был — чистим память
	if (isStorageCreated)
	{
		delete[] idArr;
		delete[] nameArr;
		delete[] coutArr;
		delete[] priceArr;
	}

	storageSize = 0;

	idArr = nullptr;
	nameArr = nullptr;
	coutArr = nullptr;
	priceArr = nullptr;

	isStorageCreated = true;

	std::cout << "Новый склад успешно создан (пустой)\n";
	Sleep(1500);
}
void ShowStorage(int mode)
{

	if (!isStorageCreated || storageSize == 0)
	{
		std::cout << "Склад пуст.\n";
		Sleep(1500);
		system("cls");
		return;
	}

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
void AddStorageItem()
{
	if (!isStorageCreated || storageSize == 0)
	{
		std::cout << "Склад пуст. Сначала добавьте товары.\n";
		Sleep(1500);
		return;
	}

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
	if (!isStorageCreated || storageSize == 0)
	{
		std::cout << "Склад пуст. Списание невозможно.\n";
		Sleep(1500);
		return;
	}

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
void ChangeStorage()
{
	if (!isStorageCreated)
	{
		std::cout << "Склад не создан.\n";
		Sleep(1500);
		return;
	}
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
void ChangePrice()
{
	if (!isStorageCreated || storageSize == 0)
	{
		std::cout << "Склад пуст. Нет товаров для изменения цены.\n";
		Sleep(1500);
		return;
	}

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
				double* priceArrTemp = new double[storageSize];
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

