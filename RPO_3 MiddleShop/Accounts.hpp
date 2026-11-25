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

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;


void ChangeAccounts();

void CreateAccount();
void CreateSet();
bool CheckLogin(const std::wstring & login);
#endif // !_ACCOUNT_HPP_
