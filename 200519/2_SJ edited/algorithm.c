#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"team.h"
void test_open_file()
{
	FILE* fcsv;		// ���� ������ ����
	char info[100];		//���� ���ڿ� > ����,ȸ��,....�а����� �� ���� ���ڿ��ΰ���
	char* next_point;		// ��� �����ϴ°���
	char* cut;		//��� ���ϴ� ����

	int i = 1;			// ���ڿ�?
	int flag = 0;		// �� �ѹ� ������ ���� ���������ΰ�?


	if (fopen_s(&fcsv, "C:\\Users\\USER\\results\\ai.csv", "r") != 0)		// fcsv �ּҰ� ����Ű�� ������ �����ε� �װ� ""���丮�� ������ �б���� �����Ϸ��µ� �װ� 0�� �ƴҋ�? 
	{
		printf("���� ����");
		fclose(fcsv);			// ���� �����ص� �ݾƴ� ��
	}
	while (1)		//��� �ݺ�
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))		//���� �Է��� fcsv�� info�� NULL �����̸�
		{

			break;			//����
		}

		if (info[0] == '\"')				//ù ���ڰ� ��ǥ �ΰ��?
		{
			printf("asdaf");			//asdaf ����ض�
			while (1)				// �Ʒ��� �ݺ��ϴ� ���ȿ�?
			{
				if (info[i] == '"')		//����ǥ�� ���� �� >> ���� �� �ȿ� ,�ִ� ��� ""�� ���� �����ְ� �ǹǷ� �ν��ϰ� �ϱ� ���� ����
				{
					printf("1");			//1�� ����ض� >>��?
					break;			//����?
				}
				else if (info[i] == ',')		// �ƴϸ� ���� ��ǥ��ٸ� 
				{
					printf("2");			//2�� ����ϰ�
					info[i] = ' ';				// �����...? �ӿ� �̰� 
				}
				++i;			// i�� ������Ű�� while���� ���ư��پ�
			}
		}

		printf("%s", info);		//������ info�� �����


		
	}

	fclose(fcsv);		//���� ����

}
void csv_file(char directory[50])
{
	FILE* fcsv;
	char info[100];
	char* next_point;
	char* cut;
	
	int flag = 0;		// csv���� 0�࿡ �ִ� ���� ������� �ʱ� ���� .. 1��° ������� cut���
	int i =0; // �� �ȿ� ,�� ���� ��츦 ���� ���� ����

	
	if (fopen_s(&fcsv, directory, "r") != 0)
	{
		printf("���� ����");
		fclose(fcsv);
	}
	while (1)
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))
		{

			
			break;
		}
		++flag;

		
		
		while (1)
		{
			if (info[i] == '\"') // �ڿ� " , " ǥ�� ���
			{
				info[i] = '?';

				while (1)
				{
					if (info[i] == ',')
					{

						info[i] = ' ';
						
				
					}else if(info[i] == '"')
					{
						info[i] = '?';
						i = -2;
						break;
					}
					++i;
				}
			}

			if ((i == -1) || ( i == 99))
			{
				break;
			}
			++i;
		
		}
		i = 0;

		info[strlen(info) - 1] = '\0';
		
		cut = strtok_s(info, ",?", &next_point);
		//printf("%s", info);
		
		while (cut != NULL)
		{
			if (cut != NULL)
			{
				if (flag >= 2) 
				{
					printf("%s --- %d", cut,flag); //<< ������ ����

					

				}

				cut = strtok_s(next_point, ",?", &next_point);
				
			}

			printf("\n");
		}
		       
	}
	
	fclose(fcsv);

}
void output_file()
{
	FILE* fr;
	char str[30],*num,*name[30],*comp[30];
	char* slice = NULL;
	char* next_point = NULL;
	int flag = 0;
	fopen_s(&fr, "team.txt", "r");

	while (1)
	{
		if (fgets(str, sizeof(str), fr) == NULL)
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		printf("%s", str);

		slice = strtok_s(str, "   ", &next_point);
		flag = 0;
		while (slice != NULL)
		{
			if (slice != NULL)
			{
				//printf(" %s\n", slice); << ������ ����

				//3���� �и�����. num�� ������ ���ڷ� ��ȯ�ϱ�. name�̶� comp�� �迭�� �����ϴ��� �ϱ�.
				if (flag == 0) { num = slice; printf("=%c=", *num); }
				if (flag == 1) { *name = slice; printf("=%s=", *name); }
				if (flag == 2) { *comp = slice; printf("=%s=", *comp); }
				++flag;
				slice = strtok_s(NULL, "   ", &next_point);
			}
		}
		

	}
}


void input_file(team* t1)
{
	FILE* fo;
	int i;

	fopen_s(&fo, "team.txt", "a");


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
		printf("%d ��° ���� �Է� : ", (i + 1));
		t12[i].num = i + 1;
		scanf_s("%s", t12[i].name, sizeof(t12[i].name));
		printf("ȸ��� �Է� : ");
		scanf_s("%s", t12[i].comp, sizeof(t12[i].comp));
		printf("=======================\n");

	}

}
// ���Ǵ�� ¥�� ���ǹ�

void print_info(search_team *st)
{
	int chk;
	

	while (1)
	{
		printf("======1:���� �˻�======\n======2:ȸ�� �˻�======\n======3:�̸� �˻�======\n======4:�б� �˻�======5:�˻� ����======\n===================\n��	��:	");
	scanf_s("%d", &chk);
	switch (chk)
	{
		// ��ȣ�� ����
	case 1:

		sort_lead(st);

		break;

		// ���� ����
	case 2:

		sort_name(st);

		break;

		// ȸ��� ����
	case 3:

		sort_mail(st);

		break;
	case 4:

		sort_comp(st);

		break;
	}
	if (chk == 5)
	{
		break;
	}
	}
	
}


void sort_nums(team* t1)
{
	int i;
	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", t1[i].num, t1[i].name, t1[i].comp);
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
		for (j = 0; j < 5; j++)
		{
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)
			{
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;

			}
		}

	}

	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
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
		for (j = 0; j < 5; j++)
		{
			if (strcmp(cmp[j].comp, cmp[j + 1].comp) > 0)
			{

				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;


			}
		}

	}

	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}