#pragma once
#include <string>
#include <unordered_set>
extern size_t userSize;
extern size_t staffCount;

extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;

extern double* salesArr;
extern unsigned int* userIdArr;

extern unsigned int currentId;
extern std::string currentStatus;

void AddNewUser();
void DeleteUser();
void ChangePass();
void ShowUsers(int mode = 0);
bool Login();
bool Logout();
void ChangeAccount();
bool CheckLogin(const std::string& str);

extern std::string userStatus[3];


extern std::unordered_set<char> specialSymbols;

extern bool isSetCreated;
extern bool isPassSetCreated;

void SetSpecialSymbols();
void SetPassSymbols();