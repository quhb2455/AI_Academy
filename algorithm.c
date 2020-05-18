#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"team.h"


void input_file(team* t1)
{
	FILE* fo;
	int i;

	fopen_s(&fo, "team.txt", "w");

	for (i = 0; i < 6; i++)
	{
		fprintf(fo, "%d   %s   %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}


	fclose(fo);

}


void  input_info(team* t12)
{
	int i;

	for (i = 0; i < 6; i++)
	{
		printf("%d 번째 팀명 입력 : ", (i + 1));
		t12[i].num = i + 1;
		scanf_s("%s", t12[i].name, sizeof(t12[i].name));
		printf("회사명 입력 : ");
		scanf_s("%s", t12[i].comp, sizeof(t12[i].comp));
		printf("=======================\n");

	}

}

void print_info(team* t1)
{
	int chk;
	printf("번호로 정렬 시 1 입력, 팀명 정렬 시 2 입력, 회사명 정렬 시 3 입력  : ");
	scanf_s("%d", &chk);

	switch (chk)
	{
		// 번호로 정렬
	case 1:

		sort_nums(t1);

		break;

		// 팀명 정렬
	case 2:

		sort_name(t1);

		break;

		// 회사명 정렬
	case 3:

		sort_comp(t1);

		break;
	}
}


void sort_nums(team* t1)
{
	int i;
	printf("번호   팀명   회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}

	input_file(t1);
}

void sort_name(team* t)
{
	int i, j;
	team cmp[6];
	team tmp;

	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
	}

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)
			{
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;

			}
		}

	}

	printf("번호    팀명    회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}

void sort_comp(team* t)
{
	int i, j;
	team cmp[6];
	team tmp;



	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
	}

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (strcmp(cmp[j].comp, cmp[j + 1].comp) > 0)
			{

				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;


			}
		}

	}

	printf("번호    팀명    회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}