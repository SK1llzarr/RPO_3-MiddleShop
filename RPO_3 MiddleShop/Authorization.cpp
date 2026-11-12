#include "Authorization.hpp"
#include "Service.hpp"
void Start()
{
	while (true)
	{
		if (Login())
		{
			
			if (currentStatus == L"Superadmin")
			{

			}
			else if (currentStatus == L"admin")
			{

			}
			else if (currentStatus == L"User")
			{

			}
			else
			{
				std::wcerr << L"_CURRENT_STATIS_LOGIN_ERROR_";
			}
		}
		else
		{

		}
	}	
}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\n\n\t Добро пожаловать!";
		std::wcout << L"\n\n\t\t\t   Шестерочка";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";

		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"Добро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}