#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

size_t maxStorageSize = 5000;
size_t currentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Кола", L"Чипсы lays", L"Картошка", L"Огурцы", L"Бананы",
			L"Яблоки", L"Выпечка", L"Хлеб", L"Мясо(Свинина)", L"Энергетики",
		};
		size_t countArrStatic[staticSize]{ 14, 30, 9, 18, 23, 7, 22, 40, 10, 3 };
		double priceArrStatic[staticSize]{ 149.9, 210.1, 90.6, 200.2, 150.5,100.2,
		50.3, 70.7, 300.2, 149.5 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArrStatic, idArr, sizeSt);
		FillArray(nameArrStatic, nameArr, sizeSt);
		FillArray(countArrStatic, countArr, sizeSt);
		FillArray(priceArrStatic, priceArr, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}
		isStorageCreated = true;
	}
	else if (mode == 1)
	{
		//to do
	}
	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(1500);
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"\n\n\t\t\t Товары \n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");


	}
	else if (mode == 1)
	{
		system("cls");

		std::wcout << L"\n\n\t\t\t Пополнение товаров \n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного места " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	while (true)
	{
		ShowStorage(1);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"завершение операции пополения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0&& count > maxStorageSize - currentStorageSize)
					{
						//to do
					}
				}
			}
		}
	}
}