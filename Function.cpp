#include <stdio.h>
#include<iostream>
#include <locale>
#include<cmath>
#define PI 3.141592653589793238492643
using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian");

	double x, F, a, b;

	cout << "Вычисление значения функции\nАвтор : студент гр.РИ - 190008 Каландаров М.Ю. 2020 г." << endl; 

	cout << " Введите x = ";
	cin >> x;

	if (x > 1)
	{
		b = pow(x, 2);
		F = 0.5 * sin(PI * b);
		cout << F;
	}

	else if (x > 0 && x <= 1)
	{
		a = 5.5 * x;
		F = pow(a, 1. / 3) - x;
		cout << F;
	}

	else
	{
		F = 0;
		cout << F;
	}
}
