#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct team {
	int num;
	char name[30];
	char comp[30];

};


void sort_name(struct team* t);
void sort_comp(struct team* t);


int main(void) {

	
	struct team t1[6];
	//struct team t1[2];
	
	int i,chk;
	
	
	//for (i = 0; i < 2; i++)
	for (i = 0; i < 6; i++)
	{
		printf("%d ��° ���� �Է� : ", (i + 1));
		t1[i].num = i + 1;
		scanf_s("%s", t1[i].name,sizeof(t1[i].name));
		printf("ȸ��� �Է� : ");
		scanf_s("%s", t1[i].comp,sizeof(t1[i].comp));
		printf("=======================\n");

	}

	//���� ��
	//for (i = 0; i < 2; i++)
	printf("��ȣ   ����   ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		
		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}


	//���� �� -- ���� �˰��� �־ ���.
	printf("��ȣ�� ���� �� 1 �Է�, ���� ���� �� 2 �Է�, ȸ��� ���� �� 3 �Է�  : ");
	scanf_s("%d", &chk);
	switch (chk)
	{
	// ��ȣ�� ����
	case 1:

		printf("��ȣ   ����   ȸ���\n");
		for (i = 0; i < 6; i++)
		{
			printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
		}

		break;

	// ���� ����
	case 2:

		sort_name(t1);

		break;

	// ȸ��� ����
	case 3:

		sort_comp(t1);

		break;
	}




	return 0;

}


void sort_name(struct team* t)
{
	int i, j;
	team cmp[6];
	team tmp;



	//cmp�� ���̸� ��� ����
	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
		//cmp2[i] = t[i];
	}

	//strcpy_s(max, sizeof(max), cmp[0].name);
	
	//printf("\n============%s==============\n", max);
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (strcmp(cmp[j].name, cmp[j+1].name) > 0)
			{
				
				                               // ū ����
					tmp = cmp[j];
					cmp[j] = cmp[j + 1];
					cmp[j + 1] = tmp;            // ���� ��ҷ� ����
				
				
			}
		}
		
	}

	printf("��ȣ      ����      ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

}

void sort_comp(struct team* t)
{
	int i, j;
	team cmp[6];
	team tmp;



	//cmp�� ���̸� ��� ����
	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
		//cmp2[i] = t[i];
	}

	//strcpy_s(max, sizeof(max), cmp[0].name);

	//printf("\n============%s==============\n", max);
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

	printf("��ȣ      ����      ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}


}