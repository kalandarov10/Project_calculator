#include <stdio.h>
#include <math.h> 
#include <cstdlib>


float epsolon = 0.0001;             //  условие остановки


float erlangB(float E, int m)       // вычисления erlangB
{
	float invB = 1.0;
	float erlB;

	for (int i = 0; i <= m; i++)
	{
		invB = 1.0 + invB * i / E;
	}

	erlB = 1.0 / invB;

	return erlB;
}


float extended_erlangB(float E0, int m, float prf, float epsolon) //итерационный расчет erlang B 
{
	float Bi = 0, Ai = 0, Ei1 = 0, r = 0;
	float diff = 99999;
	float Ei = E0;

	while (diff > epsolon)
	{
		
		Bi = erlangB(Ei, m);    //рассчет  erlangB

		
		Ai = Ei * Bi; // рассчитать вероятность блокирования вызова

		
		r = Ai * prf;  //рассчитать количество отозваний, r исходя из коэффициента отзыва, rf


		Ei1 = E0 + r; //рассчитать новый предложенный трафик

		// повтор
		diff = abs(Ei1 - Ei);  // условная остановка
		Ei = Ei1;

	}
	return Bi;
}

float loss_erlang(float B, float p)//Вероятность пропуска звонка
{
	float L = 0;
	return (B * (1 - p)) / (1 - (B * p));
}


