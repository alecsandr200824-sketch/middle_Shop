#pragma once
#include <string>

extern size_t storageSize;

extern unsigned int* idArr;
extern std::string* nameArr;
extern double* priceArr;
extern unsigned int* coutArr;
extern size_t storageSize;
extern size_t maxItemSize;

extern unsigned int* idArr;
extern std::string* nameArr;
extern double* priceArr;
extern unsigned int* coutArr;

extern bool isStorageCreated;
extern bool isStorageCreated;

void CreateStorage();
void CreateEmptyStorage();

void ShowStorage(int mode = 0);

void AddStorageItem();
void RemoveStorageItem();

void ChangeStorage();
void ChangePrice();

void AddNewItem();
void DeleteItem();
void ChandeName();

extern size_t storageSize;
extern size_t maxItemSize;

extern unsigned int* idArr;
extern std::string* nameArr;
extern double* priceArr;
extern unsigned int* coutArr;

extern bool isStorageCreated;