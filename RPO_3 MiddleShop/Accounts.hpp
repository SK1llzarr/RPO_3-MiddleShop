#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include "Service.hpp"

extern size_t userSize;
extern size_t currentId;
extern std::wstring currentStatus;


extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* statusArr;
extern size_t* userIdArr;

extern double* awardArr;
extern double* fineArr;

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern bool isSetCreated;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

void ShowUsers(int mode = 0);
void ChangeAccounts();

void CreateAccount();
void CreateSet();
bool CheckLogin(const std::wstring & login);
bool CheckPass(const std::wstring& pass);
#endif // !_ACCOUNT_HPP_
