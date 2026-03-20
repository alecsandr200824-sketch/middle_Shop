#pragma once
#include <string>

// чек
extern size_t checkSize;

extern int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;

// деньги
extern double cash;
extern double cashIncome;
extern double bankIncome;

// функции
void Selling();
void PrintCheck(double& totalSum);
void CheckArrPushback();
void StorageReturner();
double VolumeDiscount(double totalSum);
double TimeDiscount(double totalSum);
void ShowIncome();