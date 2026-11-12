#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
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
}