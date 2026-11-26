#include "Accounts.hpp"


size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;


std::wstring* loginArr = new std::wstring[userSize]{ L"admin",L"user", L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin",L"user", L"user2" };
std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin",L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

double* awardArr = new double [userSize] {0, 1, 2 };
double* fineArr = new double [userSize] {};

size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 15;
size_t minPass = 6;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

bool isSetCreated = false;

void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"ID\t" << L"Логин\t" << std::left << std::setw(maxLogin)
			<< L"\tПароль" << std::setw(maxPass) << L"\tРоль" << L"\tПродажи" << L"\t\tШтрафы" << L"\n\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::wcout << userIdArr[i] << L"\t" << std::left << std::setw(maxLogin)
				<< loginArr[i] << L"\t" << std::setw(maxPass) << passArr[i] << L"\t" << std::setw(12)
				<< statusArr[i] << L"\t" << awardArr[i] << std::fixed << std::setprecision(2) 
				<< L"\t\t" << fineArr[i] << L"\n";
		}
		system("pause");
	}
}


void ChangeAccounts()
{
	std::wstring choose;

	if (!isSetCreated)
	{
		CreateSet();
	}

	while (true)
	{
		system("cls");

		std::wcout << L"\n\n\t\t\t Редактор учетных записей\n\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать премии и штрафы сотрудников\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{
			CreateAccount();

		}
		else if (choose == L"2")
		{
			ShowUsers();
		}
		else if (choose == L"3")
		{
			
		}
		else if (choose == L"4")
		{
			
		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"0")
		{
			std::wcout << L"\nВыход из редактора склада\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}


void CreateAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;
	while (true)
	{
		while (true)
		{
			
		}
		
		while (true)
		{

		}
		
		while (true)
		{
			system("cls");
			std::wcout << L"Введите роль нового пользователь иди \"exit\ для выхода: ";
			std::wcout << L"1 - Сотрудник\n";
			std::wcout << L"2 - Администратор\n";
			std::wcout << L"Ввод: \n";
			Getline(chooseStatus);
			if (choose == L"exit" || choose == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			else if (choose == L"1")
			{
				chooseStatus = L"User";
				break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Для подтверждения введите пароль Супер Администратора: ";
				Getline(choose);
				if (choose == passArr[0])
				{
					chooseStatus = L"Admin";
					break;
				}
			}
			else
			{
				Err();
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Логин: " << chooseLogin << L"\n";
			std::wcout << L"Пароль: " << choosePass << L"\n";
			std::wcout << L"Роль: " << chooseStatus << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Отмена\n\nВвод: ";
			Getline(choose);
			if (choose == L"1")
			{
				std::wcout << L"Создание учетной записи";
				for (size_t i = 0; i < 5; i++)
				{
					Sleep(500);
					std::wcout << L" .";
				}
				Sleep(500);

				ArrPushBack(userIdArr, userSize);
				ArrPushBack(loginArr, userSize);
				ArrPushBack(passArr, userSize);
				ArrPushBack(statusArr, userSize);
				ArrPushBack(fineArr, userSize);
				ArrPushBack(awardArr, userSize);
				userSize++;
				userIdArr[userSize - 1] = userSize - 1;
				loginArr[userSize - 1] = chooseLogin;
				passArr[userSize - 1] = choosePass;
				statusArr[userSize - 1] = chooseStatus;
				fineArr[userSize - 1] = 0.0;
				awardArr[userSize - 1] = 0.0;

				std::wcout << L"\n\nУчетная запись создана\n";
				Sleep(1500);
				break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена создания новой учетной записи\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
	}
	


}
void CreateSet()
{
	for (wchar_t i = L'0'; i <= L'9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'A'; i <= L'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'a'; i <= L'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'!'; i <= L'~'; i++)
	{
		passSymbols.insert(i);
	}
	isSetCreated = true;
}

bool CheckLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin)
	{
		std::wcout << L"Ошибка длины логина! Допустимо от " << minLogin << L" до " 
			<< maxLogin << L"символов\n\n";
		Sleep(1500);
		return false;
	}

	if (!IsNotSame(login, loginArr, userSize))
	{
		std::wcout << L"Такой пользователь уже создан\n\n";
		Sleep(1500);
		return false;
	}
	int count = 0;
	for (size_t i = 0; i < login.size(); i++)
	{
		if (!loginSymbols.count(login[i]))
		{
			std::wcout << L"Некорректный символы в логине!\nДопустимые символы: A-Z, a-z, 0-9\n\n";
			Sleep(2000);
			return false;
		}
		if (std::iswdigit(login[i]) && count <= 4)
		{
			count++;
		}
	}
	if (count >= 4)
	{
		return true;
	}
	else
	{
		std::wcout << L"Слишком мало буквенных символов! Минимум 4 символа вернего или нижнего регистра\n\n";
		Sleep(1500);
		return false;
	}
}

bool CheckPass(const std::wstring& pass)
{
	if (pass.size() < minPass || pass.size() > maxPass)
	{
		std::wcout << L"Ошибка длины пароля! Допустимо от " << minPass << L" до "
			<< maxPass << L"символов\n\n";
		Sleep(1500);
		return false;
	}

	int symbolCount = 0, letterCount = 0, letterCapCount = 0, numberCount = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if (!passSymbols.count(pass[i]))
		{
			std::wcout << L"Некорректный символы в пароле!" <<
				 L"\nДопустимые символы : A - Z, a - z, 0 - 9 + спец. символы\n\n";
			Sleep(2000);
			return false;
		}
		if (std::iswdigit(pass[i]) && numberCount <= 2)
		{
			numberCount++;
		}
		else if (pass[i] >= L'A' && pass[i] <= L'Z' && letterCapCount <= 2)
		{
			letterCapCount++;
		}
		else if (pass[i] >= L'a' && pass[i] <= L'z' && letterCount <= 3)
		{
			letterCount++;
		}
		else
		{
			symbolCount++;
		}
	}
	if (symbolCount > 0 &&letterCount > 2 && letterCapCount > 0 && numberCount > 1)
	{
		return true;
	}
	else
	{
		std::wcout << L"Некорректный пароль! Минимальные требования: \n";
		std::wcout << L"Специальные символы - 1 и более\n";
		std::wcout << L"Нижний регистр букв - 3 и более\n";
		std::wcout << L"Верхний регистр букв - 1 и более\n";
		std::wcout << L"Цифры - 2 и более\n\n";
		Sleep(1500);
		return false;
	}
}