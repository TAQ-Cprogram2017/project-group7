
#include<graphics.h>
#include<conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"



void start()//画背景
{
	int WIDTH = 700;
	int HEIGHT = 700;
	initgraph(WIDTH, HEIGHT);
	setbkcolor(RGB(229, 217, 185));
	//	start_1();
}


void output(int *pc[], int row, int col) //输出二维数组
{
	int i, j;
	for (i = 0; i<row; i++) {
		for (j = 0; j<col; j++)
			printf("%d ", pc[i][j]);
		printf("\n");
	}
}

void blank(int *pa[])//挖空白
{
	int i, j;
	for (i = 1; i<4; i++)
	{
		for (j = 1; j<4; j++)
		{

			if (pa[i - 1][j] == 0 && pa[i][j + 1] == 0 && pa[i + 1][j] == 0 && pa[i][j - 1] == 0)
				pa[i][j + 1] = 1;
		}

	}
	for (i = 0, j = 1; j<4; j++)
	{
		if (pa[i][j] != 0 && pa[i][j - 1] == 0 && pa[i][j + 1] == 0 && pa[i + 1][j] == 0)
			pa[i + 1][j] = 1;
	}

	for (i = 4, j = 1; j<4; j++)
	{
		if (pa[i][j] != 0 && pa[i][j - 1] == 0 && pa[i][j + 1] == 0 && pa[i - 1][j] == 0)
			pa[i - 1][j] = 1;
	}


	for (i = 1, j = 0; i<4; i++)
	{
		if (pa[i][j] != 0 && pa[i - 1][j] == 0 && pa[i + 1][j] == 0 && pa[i][j + 1] == 0)
			pa[i][j + 1] = 1;
	}


	for (i = 1, j = 4; i<4; i++)
	{
		if (pa[i][j] != 0 && pa[i - 1][j] == 0 && pa[i + 1][j] == 0 && pa[i][j - 1] == 0)
			pa[i][j - 1] = 1;
	}
	if (pa[0][2] == 0 && pa[1][1] == 0 && pa[2][0] == 0)
		pa[1][1] = 1;
	if (pa[0][2] == 0 && pa[1][3] == 0 && pa[2][4] == 0)
		pa[1][3] = 1;
	if (pa[2][0] == 0 && pa[3][1] == 0 && pa[4][2] == 0)
		pa[3][1] = 1;
	if (pa[2][4] == 0 && pa[3][3] == 0 && pa[4][2] == 0)
		pa[3][3] = 1;
	if (pa[0][1] == 0 && pa[1][0] == 0)
		pa[1][0] = 1;
	if (pa[0][3] == 0 && pa[2][4] == 0)
		pa[0][3] = 1;
	if (pa[3][0] == 0 && pa[4][1] == 0)
		pa[3][0] = 1;
	if (pa[3][4] == 0 && pa[4][3] == 0)
		pa[3][4] = 1;


}


void connect(int *pa[], int *pb[])//将二维数组a挖的空白填入完整b表
{
	int i, j;
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			if (pa[i][j] == 0)
				pb[i][j] = 0;
		}


	}
}

void copy(int *pb[], int *pd[])//复制表
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			pd[i][j] = pb[i][j];
		}
	}
}


void showtable1(int *pb[])//表库
{
	pb[0][0] = 3, pb[0][1] = 5, pb[0][2] = 1, pb[0][3] = 2, pb[0][4] = 4, pb[1][0] = 4, pb[1][1] = 1, pb[1][2] = 3, pb[1][3] = 5, pb[1][4] = 2, pb[2][0] = 2, pb[2][1] = 4, pb[2][2] = 5, pb[2][3] = 3, pb[2][4] = 1, pb[3][0] = 5, pb[3][1] = 2, pb[3][2] = 4, pb[3][3] = 1, pb[3][4] = 3, pb[4][0] = 1, pb[4][1] = 3, pb[4][2] = 2, pb[4][3] = 4, pb[4][4] = 5;

}


void showtable2(int *pb[])
{
	pb[0][0] = 5, pb[0][1] = 2, pb[0][2] = 1, pb[0][3] = 4, pb[0][4] = 3, pb[1][0] = 3, pb[1][1] = 4, pb[1][2] = 2, pb[1][3] = 5, pb[1][4] = 1, pb[2][0] = 4, pb[2][1] = 5, pb[2][2] = 3, pb[2][3] = 1, pb[2][4] = 2, pb[3][0] = 2, pb[3][1] = 1, pb[3][2] = 5, pb[3][3] = 3, pb[3][4] = 4, pb[4][0] = 1, pb[4][1] = 3, pb[4][2] = 4, pb[4][3] = 2, pb[4][4] = 5;

}


void showtable3(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 4, pb[0][2] = 1, pb[0][3] = 3, pb[0][4] = 5, pb[1][0] = 1, pb[1][1] = 2, pb[1][2] = 4, pb[1][3] = 5, pb[1][4] = 3,
		pb[2][0] = 4, pb[2][1] = 3, pb[2][2] = 5, pb[2][3] = 1, pb[2][4] = 2, pb[3][0] = 5, pb[3][1] = 1, pb[3][2] = 3, pb[3][3] = 2, pb[3][4] = 4, pb[4][0] = 3, pb[4][1] = 5, pb[4][2] = 2, pb[4][3] = 4, pb[4][4] = 1;

}


void showtable4(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 1, pb[0][2] = 4, pb[0][3] = 3, pb[0][4] = 5, pb[1][0] = 3, pb[1][1] = 5, pb[1][2] = 1, pb[1][3] = 4, pb[1][4] = 2,
		pb[2][0] = 4, pb[2][1] = 3, pb[2][2] = 5, pb[2][3] = 2, pb[2][4] = 1, pb[3][0] = 5, pb[3][1] = 4, pb[3][2] = 2, pb[3][3] = 1, pb[3][4] = 3, pb[4][0] = 1, pb[4][1] = 2, pb[4][2] = 3, pb[4][3] = 5, pb[4][4] = 4;

}


void showtable5(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 5, pb[0][2] = 3, pb[0][3] = 1, pb[0][4] = 4, pb[1][0] = 5, pb[1][1] = 3, pb[1][2] = 4, pb[1][3] = 2, pb[1][4] = 1,
		pb[2][0] = 1, pb[2][1] = 4, pb[2][2] = 2, pb[2][3] = 5, pb[2][4] = 3, pb[3][0] = 4, pb[3][1] = 2, pb[3][2] = 1, pb[3][3] = 3, pb[3][4] = 5, pb[4][0] = 3, pb[4][1] = 1, pb[4][2] = 4, pb[4][3] = 4, pb[4][4] = 2;

}


void showtable6(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 1, pb[0][2] = 2, pb[0][3] = 5, pb[0][4] = 4, pb[1][0] = 2, pb[1][1] = 3, pb[1][2] = 4, pb[1][3] = 4, pb[1][4] = 1,
		pb[2][0] = 5, pb[2][1] = 2, pb[2][2] = 4, pb[2][3] = 1, pb[2][4] = 3, pb[3][0] = 1, pb[3][1] = 4, pb[3][2] = 3, pb[3][3] = 2, pb[3][4] = 5, pb[4][0] = 4, pb[4][1] = 5, pb[4][2] = 1, pb[4][3] = 3, pb[4][4] = 2;

}


void showtable7(int *pb[])
{
	pb[0][0] = 4, pb[0][1] = 5, pb[0][2] = 2, pb[0][3] = 3, pb[0][4] = 1, pb[1][0] = 3, pb[1][1] = 2, pb[1][2] = 4, pb[1][3] = 1, pb[1][4] = 5,
		pb[2][0] = 2, pb[2][1] = 3, pb[2][2] = 1, pb[2][3] = 5, pb[2][4] = 4, pb[3][0] = 5, pb[3][1] = 1, pb[3][2] = 3, pb[3][3] = 4, pb[3][4] = 2, pb[4][0] = 1, pb[4][1] = 4, pb[4][2] = 5, pb[4][3] = 2, pb[4][4] = 3;

}


void showtable8(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 4, pb[0][2] = 1, pb[0][3] = 5, pb[0][4] = 3, pb[1][0] = 1, pb[1][1] = 5, pb[1][2] = 3, pb[1][3] = 4, pb[1][4] = 2,
		pb[2][0] = 5, pb[2][1] = 1, pb[2][2] = 2, pb[2][3] = 3, pb[2][4] = 4, pb[3][0] = 3, pb[3][1] = 2, pb[3][2] = 4, pb[3][3] = 1, pb[3][4] = 5, pb[4][0] = 4, pb[4][1] = 3, pb[4][2] = 5, pb[4][3] = 2, pb[4][4] = 1;

}


void showtable9(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 1, pb[0][2] = 5, pb[0][3] = 2, pb[0][4] = 4, pb[1][0] = 4, pb[1][1] = 2, pb[1][2] = 1, pb[1][3] = 5, pb[1][4] = 3,
		pb[2][0] = 1, pb[2][1] = 5, pb[2][2] = 3, pb[2][3] = 4, pb[2][4] = 2, pb[3][0] = 5, pb[3][1] = 4, pb[3][2] = 2, pb[3][3] = 3, pb[3][4] = 1, pb[4][0] = 2, pb[4][1] = 3, pb[4][2] = 4, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable10(int *pb[])
{
	pb[0][0] = 4, pb[0][1] = 3, pb[0][2] = 5, pb[0][3] = 2, pb[0][4] = 1, pb[1][0] = 2, pb[1][1] = 1, pb[1][2] = 3, pb[1][3] = 5, pb[1][4] = 4,
		pb[2][0] = 2, pb[2][1] = 1, pb[2][2] = 3, pb[2][3] = 5, pb[2][4] = 4, pb[3][0] = 5, pb[3][1] = 2, pb[3][2] = 1, pb[3][3] = 4, pb[3][4] = 3, pb[4][0] = 3, pb[4][1] = 4, pb[4][2] = 2, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable11(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 3, pb[0][2] = 1, pb[0][3] = 4, pb[0][4] = 5, pb[1][0] = 5, pb[1][1] = 1, pb[1][2] = 4, pb[1][3] = 2, pb[1][4] = 3,
		pb[2][0] = 4, pb[2][1] = 2, pb[2][2] = 5, pb[2][3] = 3, pb[2][4] = 1, pb[3][0] = 3, pb[3][1] = 5, pb[3][2] = 2, pb[3][3] = 1, pb[3][4] = 4, pb[4][0] = 1, pb[4][1] = 4, pb[4][2] = 3, pb[4][3] = 5, pb[4][4] = 2;

}


void showtable12(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 2, pb[0][2] = 5, pb[0][3] = 4, pb[0][4] = 1, pb[1][0] = 2, pb[1][1] = 1, pb[1][2] = 3, pb[1][3] = 5, pb[1][4] = 4,
		pb[2][0] = 5, pb[2][1] = 4, pb[2][2] = 1, pb[2][3] = 3, pb[2][4] = 2, pb[3][0] = 1, pb[3][1] = 5, pb[3][2] = 4, pb[3][3] = 2, pb[3][4] = 3, pb[4][0] = 4, pb[4][1] = 3, pb[4][2] = 2, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable13(int *pb[])
{
	pb[0][0] = 2, pb[0][1] = 1, pb[0][2] = 3, pb[0][3] = 5, pb[0][4] = 4, pb[1][0] = 5, pb[1][1] = 3, pb[1][2] = 1, pb[1][3] = 4, pb[1][4] = 2,
		pb[2][0] = 4, pb[2][1] = 5, pb[2][2] = 2, pb[2][3] = 1, pb[2][4] = 3, pb[3][0] = 3, pb[3][1] = 4, pb[3][2] = 5, pb[3][3] = 2, pb[3][4] = 1, pb[4][0] = 1, pb[4][1] = 2, pb[4][2] = 4, pb[4][3] = 3, pb[4][4] = 5;

}


void showtable14(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 1, pb[0][2] = 2, pb[0][3] = 4, pb[0][4] = 5, pb[1][0] = 1, pb[1][1] = 4, pb[1][2] = 5, pb[1][3] = 3, pb[1][4] = 2,
		pb[2][0] = 5, pb[2][1] = 2, pb[2][2] = 3, pb[2][3] = 1, pb[2][4] = 4, pb[3][0] = 2, pb[3][1] = 3, pb[3][2] = 4, pb[3][3] = 5, pb[3][4] = 1, pb[4][0] = 4, pb[4][1] = 5, pb[4][2] = 1, pb[4][3] = 2, pb[4][4] = 3;

}


void showtable15(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 4, pb[0][2] = 2, pb[0][3] = 5, pb[0][4] = 1, pb[1][0] = 5, pb[1][1] = 1, pb[1][2] = 3, pb[1][3] = 4, pb[1][4] = 2,
		pb[2][0] = 1, pb[2][1] = 3, pb[2][2] = 5, pb[2][3] = 2, pb[2][4] = 4, pb[3][0] = 4, pb[3][1] = 2, pb[3][2] = 1, pb[3][3] = 3, pb[3][4] = 5, pb[4][0] = 2, pb[4][1] = 5, pb[4][2] = 4, pb[4][3] = 1, pb[4][4] = 3;

}


void showtable16(int *pb[])
{
	pb[0][0] = 4, pb[0][1] = 3, pb[0][2] = 1, pb[0][3] = 5, pb[0][4] = 2, pb[1][0] = 5, pb[1][1] = 4, pb[1][2] = 2, pb[1][3] = 1, pb[1][4] = 3,
		pb[2][0] = 3, pb[2][1] = 2, pb[2][2] = 5, pb[2][3] = 4, pb[2][4] = 1, pb[3][0] = 2, pb[3][1] = 1, pb[3][2] = 4, pb[3][3] = 3, pb[3][4] = 5, pb[4][0] = 1, pb[4][1] = 5, pb[4][2] = 3, pb[4][3] = 2, pb[4][4] = 4;

}


void showtable17(int *pb[])
{
	pb[0][0] = 3, pb[0][1] = 5, pb[0][2] = 2, pb[0][3] = 1, pb[0][4] = 4, pb[1][0] = 3, pb[1][1] = 4, pb[1][2] = 2, pb[1][3] = 5, pb[1][4] = 1,
		pb[2][0] = 4, pb[2][1] = 2, pb[2][2] = 1, pb[2][3] = 3, pb[2][4] = 5, pb[3][0] = 2, pb[3][1] = 4, pb[3][2] = 3, pb[3][3] = 5, pb[3][4] = 1, pb[4][0] = 5, pb[4][1] = 1, pb[4][2] = 4, pb[4][3] = 2, pb[4][4] = 3;

}


void showtable18(int *pb[])
{
	pb[0][0] = 4, pb[0][1] = 5, pb[0][2] = 1, pb[0][3] = 3, pb[0][4] = 2, pb[1][0] = 1, pb[1][1] = 4, pb[1][2] = 3, pb[1][3] = 2, pb[1][4] = 5,
		pb[2][0] = 5, pb[2][1] = 2, pb[2][2] = 4, pb[2][3] = 1, pb[2][4] = 3, pb[3][0] = 3, pb[3][1] = 1, pb[3][2] = 2, pb[3][3] = 5, pb[3][4] = 4, pb[4][0] = 2, pb[4][1] = 3, pb[4][2] = 5, pb[4][3] = 4, pb[4][4] = 1;

}


void showtable19(int *pb[])
{

	pb[0][0] = 3, pb[0][1] = 2, pb[0][2] = 4, pb[0][3] = 1, pb[0][4] = 5, pb[1][0] = 5, pb[1][1] = 1, pb[1][2] = 2, pb[1][3] = 4, pb[1][4] = 3, pb[2][0] = 2, pb[2][1] = 4, pb[2][2] = 5, pb[2][3] = 3, pb[2][4] = 1, pb[3][0] = 1, pb[3][1] = 5, pb[3][2] = 3, pb[3][3] = 2, pb[3][4] = 4, pb[4][0] = 4, pb[4][1] = 3, pb[4][2] = 1, pb[4][3] = 5, pb[4][4] = 2;

}


void showtable20(int *pb[])
{

	pb[0][0] = 3, pb[0][1] = 4, pb[0][2] = 1, pb[0][3] = 5, pb[0][4] = 2, pb[1][0] = 2, pb[1][1] = 1, pb[1][2] = 5, pb[1][3] = 3, pb[1][4] = 4, pb[2][0] = 1, pb[2][1] = 5, pb[2][2] = 4, pb[2][3] = 2, pb[2][4] = 3, pb[3][0] = 5, pb[3][1] = 3, pb[3][2] = 2, pb[3][3] = 4, pb[3][4] = 1, pb[4][0] = 4, pb[4][1] = 2, pb[4][2] = 3, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable21(int *pb[])
{


	pb[0][0] = 3, pb[0][1] = 4, pb[0][2] = 1, pb[0][3] = 5, pb[0][4] = 2, pb[1][0] = 2, pb[1][1] = 1, pb[1][2] = 5, pb[1][3] = 3, pb[1][4] = 4, pb[2][0] = 1, pb[2][1] = 5, pb[2][2] = 4, pb[2][3] = 2, pb[2][4] = 3, pb[3][0] = 5, pb[3][1] = 3, pb[3][2] = 2, pb[3][3] = 4, pb[3][4] = 1, pb[4][0] = 4, pb[4][1] = 2, pb[4][2] = 3, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable22(int *pb[])
{

	pb[0][0] = 1, pb[0][1] = 3, pb[0][2] = 4, pb[0][3] = 5, pb[0][4] = 2, pb[1][0] = 3, pb[1][1] = 5, pb[1][2] = 2, pb[1][3] = 1, pb[1][4] = 4, pb[2][0] = 2, pb[2][1] = 4, pb[2][2] = 1, pb[2][3] = 3, pb[2][4] = 5, pb[3][0] = 4, pb[3][1] = 1, pb[3][2] = 5, pb[3][3] = 2, pb[3][4] = 3, pb[4][0] = 5, pb[4][1] = 2, pb[4][2] = 3, pb[4][3] = 4, pb[4][4] = 1;

}


void showtable23(int *pb[])
{


	pb[0][0] = 4, pb[0][1] = 1, pb[0][2] = 2, pb[0][3] = 3, pb[0][4] = 5, pb[1][0] = 3, pb[1][1] = 2, pb[1][2] = 5, pb[1][3] = 4, pb[1][4] = 1, pb[2][0] = 5, pb[2][1] = 4, pb[2][2] = 3, pb[2][3] = 1, pb[2][4] = 2, pb[3][0] = 2, pb[3][1] = 3, pb[3][2] = 1, pb[3][3] = 5, pb[3][4] = 4, pb[4][0] = 1, pb[4][1] = 5, pb[4][2] = 4, pb[4][3] = 2, pb[4][4] = 3;

}


void showtable24(int *pb[])
{


	pb[0][0] = 2, pb[0][1] = 1, pb[0][2] = 5, pb[0][3] = 3, pb[0][4] = 4, pb[1][0] = 5, pb[1][1] = 3, pb[1][2] = 2, pb[1][3] = 4, pb[1][4] = 1, pb[2][0] = 1, pb[2][1] = 5, pb[2][2] = 4, pb[2][3] = 2, pb[2][4] = 3, pb[3][0] = 3, pb[3][1] = 4, pb[3][2] = 1, pb[3][3] = 5, pb[3][4] = 2, pb[4][0] = 4, pb[4][1] = 2, pb[4][2] = 3, pb[4][3] = 1, pb[4][4] = 5;

}


void showtable25(int *pb[])
{


	pb[0][0] = 5, pb[0][1] = 1, pb[0][2] = 3, pb[0][3] = 2, pb[0][4] = 4, pb[1][0] = 1, pb[1][1] = 2, pb[1][2] = 4, pb[1][3] = 5, pb[1][4] = 3, pb[2][0] = 2, pb[2][1] = 4, pb[2][2] = 1, pb[2][3] = 3, pb[2][4] = 5, pb[3][0] = 4, pb[3][1] = 3, pb[3][2] = 5, pb[3][3] = 1, pb[3][4] = 2, pb[4][0] = 3, pb[4][1] = 5, pb[4][2] = 2, pb[4][3] = 4, pb[4][4] = 1;

}


void showtable26(int *pb[])
{


	pb[0][0] = 5, pb[0][1] = 3, pb[0][2] = 2, pb[0][3] = 4, pb[0][4] = 1, pb[1][0] = 4, pb[1][1] = 4, pb[1][2] = 3, pb[1][3] = 1, pb[1][4] = 5, pb[2][0] = 3, pb[2][1] = 4, pb[2][2] = 1, pb[2][3] = 5, pb[2][4] = 2, pb[3][0] = 1, pb[3][1] = 5, pb[3][2] = 4, pb[3][3] = 2, pb[3][4] = 3, pb[4][0] = 2, pb[4][1] = 1, pb[4][2] = 5, pb[4][3] = 3, pb[4][4] = 4;

}


void selecttable(int number, int *pb[])//选择表
{
	if (number == 1)	showtable1(pb);
	else if (number == 2)	showtable2(pb);
	else if (number == 3) showtable3(pb);
	else if (number == 4) showtable4(pb);
	else if (number == 5) showtable5(pb);
	else if (number == 6) showtable6(pb);
	else if (number == 7) showtable7(pb);
	else if (number == 8) showtable8(pb);
	else if (number == 9) showtable9(pb);
	else if (number == 10) showtable10(pb);
	else if (number == 11) showtable11(pb);
	else if (number == 12) showtable12(pb);
	else if (number == 13) showtable13(pb);
	else if (number == 14) showtable14(pb);
	else if (number == 15) showtable15(pb);
	else if (number == 16) showtable16(pb);
	else if (number == 17) showtable17(pb);
	else if (number == 18) showtable18(pb);
	else if (number == 19) showtable19(pb);
	else if (number == 20) showtable20(pb);
	else if (number == 21) showtable21(pb);
	else if (number == 22) showtable22(pb);
	else if (number == 23) showtable23(pb);
	else if (number == 24) showtable24(pb);
	else if (number == 25) showtable25(pb);
	else if (number == 26) showtable26(pb);
}


void game_clear(int *pc[])//清屏
{
	int i, j;
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<4; j++)
		{
			pc[j][i] = 0;
		}
	}
}


void draw(int *pc[])//调取图像生成图像版二维数组
{
	int i, j;
	start();

	IMAGE img0, img00, img1, img11, img2, img22, img3, img33, img4, img44, img5, img55;

	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)

		{


			if (pc[i][j] == 0)
			{
				loadimage(&img0, "pic\\0.jpg");
				putimage(i * 140, j * 140, &img0);
			}
			else if (pc[i][j] == 1)
			{
				loadimage(&img1, "pic\\1.jpg");
				putimage(i * 140, j * 140, &img1);
			}
			else if (pc[i][j] == 2)
			{
				loadimage(&img2, "pic\\2.jpg");
				putimage(i * 140, j * 140, &img2);
			}
			else if (pc[i][j] == 3)
			{
				loadimage(&img3, "pic\\3.jpg");
				putimage(i * 140, j * 140, &img3);
			}
			else if (pc[i][j] == 4)
			{
				loadimage(&img4, "pic\\4.jpg");
				putimage(i * 140, j * 140, &img4);
			}
			else if (pc[i][j] == 5)
			{
				loadimage(&img5, "pic\\5.jpg");
				putimage(i * 140, j * 140, &img5);
			}
		}

	}
	getch();
}



void start_1(int *pc[])
{
	int WIDTH = 700;
	int HEIGHT = 700;
	cleardevice();
	setbkcolor(RGB(229, 217, 185));
	settextcolor(RGB(122, 0, 0));
	setfont(150, 0, "Microsoft JhengHei");
	RECT r1 = { 0, 0, WIDTH, HEIGHT / 2 + 100 };
	drawtext("孤独的数字", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfont(50, 0, "微软雅黑");
	RECT r2 = { WIDTH / 2 - 90,HEIGHT / 2,WIDTH / 2 + 90,HEIGHT / 2 + 60 };
	drawtext("开始游戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { WIDTH / 2 - 90,HEIGHT / 2 + 60,WIDTH / 2 + 90,HEIGHT / 2 + 120 };
	drawtext("游戏介绍", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { WIDTH / 2 - 90,HEIGHT / 2 + 120,WIDTH / 2 + 90,HEIGHT / 2 + 180 };
	drawtext("操作说明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = { WIDTH / 2 - 90,HEIGHT / 2 + 180,WIDTH / 2 + 90,HEIGHT / 2 + 240 };
	drawtext("退出游戏", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	MOUSEMSG m;//鼠标点击位置的判断
	while (1)
	{
		BeginBatchDraw();
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if (m.x>WIDTH / 2 - 90 && m.x<WIDTH / 2 + 90 && m.y>HEIGHT / 2 && m.y<HEIGHT / 2 + 60)//开始游戏
			{
				draw(pc);
				break;
			}
			else if (m.x>WIDTH / 2 - 90 && m.x<WIDTH / 2 + 90 && m.y>HEIGHT / 2 + 60 && m.y<HEIGHT / 2 + 120)
			{
				start_2();
				break;
			}
			else if (m.x>WIDTH / 2 - 90 && m.x<WIDTH / 2 + 90 && m.y>HEIGHT / 2 + 120 && m.y<HEIGHT / 2 + 180)
			{
				start_3();
				break;
			}
			else if (m.x>WIDTH / 2 - 90 && m.x<WIDTH / 2 + 90 && m.y>HEIGHT / 2 + 180 && m.y<HEIGHT / 2 + 240)//游戏介绍
			{
				exit(0);
			}
			break;
		}
	}
	getch();
}


void start_2()//游戏介绍
{
	int*pc[5];
	int WIDTH = 700;
	int HEIGHT = 700;
	cleardevice();
	RECT C2 = { 60,60,640,640 };
	drawtext("\n\n\n\n　　游戏介绍：将每行每列相同的数字删去一个，做到每行每列没有相同的数字，并且去掉的数字不能将这个界面分开。\n\n\n\n", &C2, DT_WORDBREAK);


	RECT R1 = { WIDTH - WIDTH + 2,HEIGHT - 200,WIDTH - 2,HEIGHT - 2 };
	drawtext("返回", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while (1)//返回键的设置
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (m.x>WIDTH - WIDTH + 2 && m.x<WIDTH - 2 && m.y>HEIGHT - 200 && m.y<HEIGHT - 2)
				start_1(pc);
		}
	}
}

void start_3()//操作说明
{
	int*pc[5];
	int WIDTH = 700;
	int HEIGHT = 700;
	cleardevice();
	RECT C3 = { 60,60,640,640 };
	drawtext("\n\n\n操作说明：使用数字键+回车键+数字键选择数字的横纵坐标，来消去某个数字或者撤销消去操作。", &C3, DT_WORDBREAK);

	RECT R1 = { WIDTH - WIDTH + 2,HEIGHT - 200,WIDTH - 2,HEIGHT - 2 };
	drawtext("返回", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while (1)//返回键的设置
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (m.x>WIDTH - WIDTH + 2 && m.x<WIDTH - 2 && m.y>HEIGHT - 200 && m.y<HEIGHT - 2)
				start_1(pc);
		}
	}
}


void win()//赢之后画面
{
	int WIDTH = 700;
	int HEIGHT = 700;
	COLORREF ref;
	int r, g, b;
	int x, y;
	char *yes, *no, *win;
	initgraph(WIDTH, HEIGHT);
	setbkcolor(RGB(229, 217, 185));
	cleardevice();


	BeginBatchDraw();
	for (x = 0; x<700; x++)
	{
		for (y = 0; y<900; y++)
		{
			ref = getpixel(x, y);
			r = GetRValue(ref);
			g = GetGValue(ref);
			b = GetBValue(ref);
			putpixel(x, y, RGB(r*0.5, g*0.5, b*0.5));
		}
	}

	FlushBatchDraw();
	EndBatchDraw();
	yes = "YES";
	no = "NO";
	win = "YOU WIN !";
	for (x = 0; x<10; x++)//显示win的多彩色
	{
		settextcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		settextstyle(100, 50, NULL);
		outtextxy(50, 50, win);
		Sleep(100);
	}


	getch();
}