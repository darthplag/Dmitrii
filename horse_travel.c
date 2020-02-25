
#ifndef HORSE_TRAVEL_C
#define HORSE_TRAVEL_C
#define CRT_SECURE_NO_WARNINGS
#define ERR1 1 //ошибка при чтении
#include <stdio.h>
//Максимальное число вариантов хода коня на данном поле
#define Max_step 8
//Все ходы коня от поля begin в массив steps длинна строки - n ,колиество строк - m
void step(int begin, int n,int m, int steps[Max_step])
{
	int n2 = 2 * n, ost = begin % n;
	int numb_str = begin / n;
	if (begin > n2)//ходы вверх на 2
	{
		if (ost != 0)
			steps[0] = begin - n2 + 1;//влево на 1
		if (ost != 0 && ost < n - 2)
			steps[1] = begin - n2 + 3;//вправо на 1
	}
	if (begin > n)//ходы вверх на 1
	{
		if (ost > 2)
			steps[2] = begin - n - 1;//влево на 2
		if (ost != 0 && ost < n - 2)
			steps[3] = begin - n + 3;//вправо на 2
	}

	if (numb_str + 2 < m)//ходы вниз на 2
	{
		if (ost > 3 || (n > 3 && ost == 0)
			steps[4] = begin + n2 - 3;//влево на 1
		if (ost >= 2 || ost == 0)
			steps[5] = begin + n2 - 1;//вправо на 1
	}
	if (numb_str + 1 < m)//ходы вниз на 1
	{
		if ((n >= 4 && ost != 0) || ost >= 4)
			steps[6] = begin + n - 3;//влево на 2
		if (ost != 0)
			steps[7] = begin + n + 1;//вправо на 2
	}
}
//Поиск пути рекурсией
int find_way(int begin, int end, int n, int m, int* fild)
{
	int i,steps[Max_step], count = Max_step;
	for (i = 0; i < Max_step; i++)
		steps[i] = 0;
	step(begin, n, m, steps);
	for (i = 0; i < Max_step; i++)
		if (fild[steps[i]] == -1)
		{	
			fild[steps[i]] = begin;
			if (steps[i] == end)
				return 1;
			if (find_way(steps[i], end, n, m, fild))
				return 1;
		}	
	return 0;
}
//Вывод пути
void print_way(int begin, int end, int n, int m, int* fild)
{
	if (!find_way(end, begin, n, m, fild))
		printf("There is no way\n");
	else
	{
		while (begin != end)
		{
			printf("%d ", begin);
			begin = fild[begin];
		}
		printf("%d", end);
	}
}
//чтение вводимых данных
int scan(int *n, int* m, int *begin, int* end, int* trap1, int* trap2)
{
	int ok, mn;
	printf("\nВведите длину строки");
	ok = scanf("%d", n);
	if (!ok || *n <= 0)
	{
		printf("\nНеправильный ввод");
		return ERR1;
	}
	printf("\nВведите количество строк ");
	ok = scanf("%d", m);
	if (!ok || *m <= 0)
	{
		printf("\nНеправильный ввод");
		return ERR1;
	}
	mn = *m * *n;
	printf("\nВведите начальную и конечную позиции ");
	ok = scanf("%d%d", begin, end);
	if (!ok || *begin > mn || *end > mn)
	{
		printf("\nНеправильный ввод");
		return ERR1;
	}
	printf("\nВведите номера запретных клеток ");
	ok = scanf("%d%d", trap1, trap2);
	if (!ok || *trap1 > mn || *trap2 > mn)
	{
		printf("\nНеправильный ввод");
		return ERR1;
	}
	return 0;
}
#endif // !HORSE_TRAVEL_C