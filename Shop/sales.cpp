#include <iomanip>
#include "utils.h"
#include "sales.h"
#include "storage.h"
#include "users.h"

#include <iostream>
#include <ctime>
#include <windows.h>

size_t checkSize = 0;

int* idArrCheck = nullptr;
std::string* nameArrCheck = nullptr;
unsigned int* countArrCheck = nullptr;
double* priceArrCheck = nullptr;
double* totalPriceArrCheck = nullptr;

double cashIncome = 0.0;
double bankIncome = 0.0;
double cash = 30000;
void Selling()
{
	if (!isStorageCreated || storageSize == 0)
	{
		std::cout << "Склад пуст. Продажа невозможна.\n";
		Sleep(1500);
		return;
	}
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0, index = -1;
	double money = 0.0, totalSum = 0.0;
	bool isFirst = false;
	checkSize = 0;
	while (true)
	{


		ShowStorage();

		std::cout << "Введите ID товара для покупки или\"exit\" для завершения покупок: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			system("cls");
			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}
			double discount1 = VolumeDiscount(totalSum);
			double discount2 = TimeDiscount(totalSum);

			double totalDiscount = discount1 + discount2;
			double finalSum = totalSum - totalDiscount;

			std::cout << "\nСкидки:\n";
			if (discount1 > 0)
				std::cout << "Объёмная скидка: -" << discount1 << " руб.\n";
			if (discount2 > 0)
				std::cout << "Скидка по времени: -" << discount2 << " руб.\n";

			std::cout << "Итого скидка: -" << totalDiscount << " руб.\n";
			std::cout << "К оплате: " << finalSum << " руб.\n\n";

			totalSum = finalSum;


			PrintCheck(totalSum);
			std::cout << "\nПодтвердить покупку?\n1 - Да\n2 - Добавить еще товар\n3 - Отмена\nВвод: ";
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Введите способ оплаты\n1 - Наличными\n1 - Безнал\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "Введите кол-во наличных: ";
						Getline(chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stod(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "Нет возможности дакт сдачи, повторите попытку!\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши: " << money << "\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << " рублей\n";
								Sleep(2000);
								cash += totalSum;
								cash -= money - totalSum;
								cashIncome += totalSum;
								salesArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						std::cout << "Приложите карту\n\n";
						Sleep(1000);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Sleep(500);
							}
							std::cout << "\nОплата прошла успешно\n\nСпасибо за покупку!";
							bankIncome += totalSum;
							salesArr[currentId] += totalSum;
							system("cls");
							Sleep(1500);
							break;

						}
					}
					else if (choose == "Samsung")
					{
						std::cout << "Великий самсунг оплатил вам чек. Всего доброго\n";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}

				}
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";
				void StorageReturner();
				Sleep(1500);
				return;
			}
			else
			{
				Err();
				continue;
			}
			system("pause");
			delete[] idArrCheck;
			delete[] nameArrCheck;
			delete[] countArrCheck;
			delete[] priceArrCheck;
			delete[] totalPriceArrCheck;
			idArrCheck = nullptr;
			nameArrCheck = nullptr;
			countArrCheck = nullptr;
			priceArrCheck = nullptr;
			totalPriceArrCheck = nullptr;

			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}
		std::cout << "\nВведите кол-во товара или \"exit\" для завершения покупок: ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки товара: " << nameArr[id] << "\n\n";
			Sleep(1500);
			continue;
		}
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount) - 1;
			if (count < 1 || count > coutArr[id])
			{
				std::cout << "Ошибка кол-ва! Максимум: " << coutArr[id] << "\n\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}


		CheckArrPushback();
		if (isFirst == false)
		{
			isFirst = true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		coutArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар добавлен в чек\n\n";

		Sleep(1000);
	}
}
void PrintCheck(double& totalSum)
{
	std::cout << "№\t" << "ID\t" << std::left << std::setw(25) << "Название товара\t\t"
		<< "Цена за ед\t" << "Кол-во\n" << "Итого\n";
	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t"
			<< priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "\nИтого к оплате: " << totalSum << "\n\n";
}
double VolumeDiscount(double totalSum)
{
	if (totalSum >= 25000)
		return totalSum * 0.10; // 10%
	else if (totalSum >= 10000)
		return totalSum * 0.05; // 5%

	return 0.0;
}
double TimeDiscount(double totalSum)
{
	time_t now = time(nullptr);
	tm localTime{};
	localtime_s(&localTime, &now);

	int hour = localTime.tm_hour;

	// Счастливые часы: 12–14
	if (hour >= 12 && hour < 14)
		return totalSum * 0.07; // 7%

	return 0.0;
}
void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		coutArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;
	idArrCheck;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;
}
void ShowIncome()
{
	system("cls");
	std::cout << "Текущая прибыль за смену\n\n";
	std::cout << "Наличный рассчет: " << "\n";
	std::cout << "Безналичный расчет: " << bankIncome << "\n";
	std::cout << "Итого: " << bankIncome + cashIncome << "\n\n";
	std::cout << "Сумма ваших продаж: " << salesArr[currentId] << "\n\n";

	system("pause");
	system("cls");
}