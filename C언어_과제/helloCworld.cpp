#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


/* ����ü ����� �� ����Ʈ ���� �˰��� */

/* ID, �� ��, ȸ�� ���� ���� �׸����� �����Ͽ�
6���� �� ��� ȸ����� �Է¹ް�
�� �׸� ���� ���� �� �� �ֵ��� swith �Լ��� case ����
ID�� ������� printf
������ ���ĺ� �������� ������ ���� �� �� �� strcmp �Լ� �̿��Ͽ� �� 
ȸ��� ���� �����ϰ� ����*/

struct team {
	int num;	// �� ID
	char name[30];	// �� ��
	char comp[30];	// ȸ�� ��

};

//�Լ� ����
void sort_name(struct team* t);	//�Ű� ������ ����ü ������ 
void sort_comp(struct team* t);	


int main(void) {


	struct team t1[6];

	int i, chk;						//chk swith �Լ��� ���� ����

	for (i = 0; i < 6; i++)
	{
		printf("%d ��° ���� �Է� : ", (i + 1));	
		t1[i].num = i + 1;										// �Է¼������ �� ID ����
		scanf_s("%s", t1[i].name, sizeof(t1[i].name));
		printf("ȸ��� �Է� : ");
		scanf_s("%s", t1[i].comp, sizeof(t1[i].comp));
		printf("=======================\n");

	}
/*
	//���� ��
	//for (i = 0; i < 2; i++)
	printf("��ȣ   ����   ȸ���\n");
	for (i = 0; i < 6; i++)
	{

		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);			// �Է¼������ �̴ϱ� �ǻ� �� ID �� ����
	}*/


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

		sort_name(t1);					//sort_name �Լ� ȣ��

		break;

		// ȸ��� ����
	case 3:

		sort_comp(t1);					//sort_comp �Լ� ȣ��

		break;
	}




	return 0;

}


void sort_name(struct team* t)					//sort_name �Լ� ����
{
	int i, j;
	team cmp[6];								// ����ü �迭 ����
	team tmp;									// �ӽ� ����ü ����



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
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)			// > 0 �� ��� cmp[j]>com[j+1]
			{

				
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;            // ū ������ ���������� ��ġ ����>> �������� ���� 


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