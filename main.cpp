#include<graphics.h>
#include<conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#define M 5
#define N 5



void main()
{

	int a[5][5], i, j, n, b[5][5], d[5][5], x, c[5][5], sum, number;
	int *pa[5], *pb[5], *pd[5], *pc[5];
	unsigned int seed;
	for (i = 0; i<5; i++)
		pa[i] = a[i];
	for (i = 0; i<5; i++)
		pb[i] = b[i];
	for (i = 0; i<5; i++)
		pd[i] = d[i];
	for (i = 0; i<5; i++)
		pc[i] = c[i];
	//scanf("%d",&seed);
	//srand(seed);//
	srand(time(0));
	number = (rand() % 26 + 1);



	//�������
	do
	{
		for (i = 0; i<M; i++)
			for (j = 0; j<N; j++)
				a[i][j] = (rand() % 4);
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 0)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 1;
			}

		}
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 1)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 0;
			}

		}
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 2)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 0;
			}
		}

		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 0)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 1;
			}

		}

		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 3)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 0;
			}

		}
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 0)
					if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])


						a[i][j] = 1;
			}

		}
		n = 0;
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (a[i][j] == 0)
					n = n + 1;
			}

		}

		seed = seed + 1;
	} while (n<7);//�ڿղ����Ϲ���������
	selecttable(number, pb);
	//full(pb);

	blank(pa);
	connect(pa, pb);
	copy(pb, pd);
	for (i = 0; i < M; i++)//���հ�λ������
	{
		for (j = 0; j < N; j++)
		{
			if (d[i][j] == 0)
				do
				{
					x = rand() % 4;
					d[i][j] = d[x][j];
				} while (x == i || d[x][j] == 0);//b����0����ȫ�ı�a��ֻ����ı�c�ǲ����õı�d�����ظ���ı�
		}
	}
	copy(pd, pc);

	start();

	start_1(pc);
	draw(pc);

	do {
		scanf("%d%d", &i, &j);//��ʼ����
		if (c[i - 1][j - 1] != 0)
			c[i - 1][j - 1] = 0;
		else
			c[i - 1][j - 1] = b[i - 1][j - 1];
		system("cls");

		draw(pc);

		for (i = 0, sum = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
			{
				if (c[i][j] == b[i][j])
					sum = sum + 1;

			}
		}




	} while (sum != 25);
	system("cls");
	win();


}
