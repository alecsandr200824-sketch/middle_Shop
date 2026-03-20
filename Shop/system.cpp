#include "utils.h"
#include "system.h"
#include "users.h"
#include "storage.h"
#include "sales.h"

#include <iostream>
#include <windows.h>

void Start()
{
	std::string choose;
	std::cout << "\n\n\nФпс до небес\n\n\n";
	while (true)
	{
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
							CreateEmptyStorage();
							system("cls");
							ShowSuperAdminMenu();
							break;
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
				ShowAdminMenu();
			}
			else if (currentStatus == userStatus[2])
			{
				if (isStorageCreated == false)
				{
					CreateStorage();
				}
				system("cls");
				ShowAdminMenu();
				break;
			}

		}
		else if (currentStatus == userStatus[0] && currentStatus == userStatus[1])
		{
			system("cls");
			std::cout << "Итоговая прибыль за смену: " << cashIncome + bankIncome;
			std::cout << "\n\n\tЗавершение работы\n";
			Sleep(2000);
			system("cls");
			break;
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
		if (choose == "1")
		{

			Selling();

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
			ChangeStorage();
		}

		else if (choose == "7")
		{
			ChangeAccount();
		}

		else if (choose == "8")
		{
			ShowIncome();
		}

		else if (choose == "0")
		{
			if (Logout() == true)
			{
				break;
			}

		}
		else
		{
			Err();
		}

	}


}
void ShowAdminMenu()
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

			Selling();

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


		else if (choose == "5")
		{
			ChangeStorage();
		}

		else if (choose == "6")
		{
			ChangeAccount();
		}

		else if (choose == "7")
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
void ShowuserMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		if (choose == "1")
		{

			Selling();

		}
		else if (choose == "2")
		{
			ShowStorage();
		}

		else if (choose == "3")
		{
			ShowIncome();
		}

		else if (choose == "0")
		{
			if (Logout() == true)
			{
				break;
			}

		}
		else
		{
			Err();
		}

	}


}