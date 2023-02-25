#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <cmath>
using namespace std;
void ne4et(int n)
{
	int M, ms, str, stl, i, lr = 1, far = n >> 1; 
	M = (n * (n * n + 1)) / 2;    
	ms = n + (n - 1);
	int** a = new int* [ms];
	for (i = 0; i < ms; i++)
		a[i] = new int[ms];
	for (str = 0; str < ms; str++)
		for (stl = 0; stl < ms; stl++)
			a[str][stl] = 0;
	str = n - 1;
	stl = 0;
	while (str < ms)
	{
		int f1 = str, f2 = stl;
		while (f2 < (stl + n))
		{
			a[f1][f2] = lr;
			if ((f1 > far) && (f2 < far))
				a[f1][f2 + n] = lr;
			if ((f1 > (n + far) - 1) && (f2 > far))
				a[f1 - n][f2] = lr;
			if ((f1 < far) && (f2 > far))
				a[f1 + n][f2] = lr;
			if ((f1 > far) && (f2 > (n + far) - 1))
				a[f1][f2 - n] = lr;
			f1--; f2++; lr++;
		}
		str++; stl++;
	}
	for (str = (n - 1) >> 1; str <= ms - far - 1; str++)
	{
		for (stl = (n - 1) >> 1; stl <= ms - far - 1; stl++)
			cout << "|" << a[str][stl] << "|";
		cout << "\n";
	}
}
void dailinet(int n)
{
	int str, stl, i, M, z = 0, kt = 0;
	M = (n * (n * n + 1)) / 2;
	int** a = new int* [n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	for (str = 0; str < n; str++)
		for (stl = 0; stl < n; stl++)
			cin >> a[str][stl];
	for (str = 0; str < n; str++)
	{
		for (stl = 0; stl < n; stl++)
			kt += a[str][stl];
		break;
	}
	for (str = 0; str < n; str++)
	{
		for (stl = 0; stl < n; stl++)
			z += a[str][stl];
		if (z != kt)
		{
			cout << "Квадрат не магический" << "\n";
			exit(1);
		}
		z = 0;
	}
	for (stl = 0; stl < n; stl++)
	{
		for (str = 0; str < n; str++)
			z += a[str][stl];
		if (z != kt)
		{
			cout << "Квадрат не магический" << "\n";
			exit(1);
		}
		z = 0;
	}
	cout << "Квадрат магический" << "\n";
	for (str = 0; str < n; str++)
	{
		for (stl = 0; stl < n; stl++)
			cout << "|" << a[str][stl] << "|";;
		cout << "\n";
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k1;
	do
	{
		cout << "Выберите операцию:" << "\n";
		cout << "Построить магический квадрат (N на N) - 1" << "\n";
		cout << "Проверить, является ли квадрат магическим - 2" << "\n";
		cout << "Для завершения - 0" << "\n";
		cin >> k1;
		switch (k1)
		{
		case 1:
		{
			cout << "Введите размер магического квадрата (N на N)" << "\n";
			cin >> n;
			if (n < 1)
				cout << "Введен некорректный размер магического квадрата";
			if (n % 2 == 1)
				ne4et(n);
			if (n % 2 == 0)
				cout << "Программа реализована только для квадратов нечетного порядка" << "\n";
			break;
		}
		case 2:
		{
			cout << "Введите размер магического квадрата (N на N)" << "\n";
			cin >> n;
			cout << "Введите магический квадрат" << "\n";
			dailinet(n);
			break;
		}
		case 0: 
			break;
		default:
		{
			cout << "Проверьте правильноть вводимых данных" << "\n";
			cout << "\n";
			break;
		}
		}
	} while (k1 != 0);
	return 0;
}