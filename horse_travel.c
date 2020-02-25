
#ifndef HORSE_TRAVEL_C
#define HORSE_TRAVEL_C
#define CRT_SECURE_NO_WARNINGS
#define ERR1 1 //������ ��� ������
#include <stdio.h>
//������������ ����� ��������� ���� ���� �� ������ ����
#define Max_step 8
//��� ���� ���� �� ���� begin � ������ steps ������ ������ - n ,��������� ����� - m
void step(int begin, int n,int m, int steps[Max_step])
{
	int n2 = 2 * n, ost = begin % n;
	int numb_str = begin / n;
	if (begin > n2)//���� ����� �� 2
	{
		if (ost != 0)
			steps[0] = begin - n2 + 1;//����� �� 1
		if (ost != 0 && ost < n - 2)
			steps[1] = begin - n2 + 3;//������ �� 1
	}
	if (begin > n)//���� ����� �� 1
	{
		if (ost > 2)
			steps[2] = begin - n - 1;//����� �� 2
		if (ost != 0 && ost < n - 2)
			steps[3] = begin - n + 3;//������ �� 2
	}

	if (numb_str + 2 < m)//���� ���� �� 2
	{
		if (ost > 3 || (n > 3 && ost == 0)
			steps[4] = begin + n2 - 3;//����� �� 1
		if (ost >= 2 || ost == 0)
			steps[5] = begin + n2 - 1;//������ �� 1
	}
	if (numb_str + 1 < m)//���� ���� �� 1
	{
		if ((n >= 4 && ost != 0) || ost >= 4)
			steps[6] = begin + n - 3;//����� �� 2
		if (ost != 0)
			steps[7] = begin + n + 1;//������ �� 2
	}
}
//����� ���� ���������
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
//����� ����
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
//������ �������� ������
int scan(int *n, int* m, int *begin, int* end, int* trap1, int* trap2)
{
	int ok, mn;
	printf("\n������� ����� ������");
	ok = scanf("%d", n);
	if (!ok || *n <= 0)
	{
		printf("\n������������ ����");
		return ERR1;
	}
	printf("\n������� ���������� ����� ");
	ok = scanf("%d", m);
	if (!ok || *m <= 0)
	{
		printf("\n������������ ����");
		return ERR1;
	}
	mn = *m * *n;
	printf("\n������� ��������� � �������� ������� ");
	ok = scanf("%d%d", begin, end);
	if (!ok || *begin > mn || *end > mn)
	{
		printf("\n������������ ����");
		return ERR1;
	}
	printf("\n������� ������ ��������� ������ ");
	ok = scanf("%d%d", trap1, trap2);
	if (!ok || *trap1 > mn || *trap2 > mn)
	{
		printf("\n������������ ����");
		return ERR1;
	}
	return 0;
}
#endif // !HORSE_TRAVEL_C