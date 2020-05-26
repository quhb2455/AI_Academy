#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"team.h"
void test_open_file()
{
	FILE* fcsv;		// 파일 포인터 선언
	char info[100];		//인포 문자열 > 조장,회사,....학과까지 한 행의 문자열인가유
	char* next_point;		// 어디서 연결하는거지
	char* cut;		//어디서 컷하는 거지

	int i = 1;			// 문자열?
	int flag = 0;		// 행 넘버 지정을 위한 변수선언인가?


	if (fopen_s(&fcsv, "C:\\Users\\USER\\results\\ai.csv", "r") != 0)		// fcsv 주소가 가르키는 변인은 파일인데 그건 ""디렉토리에 있으니 읽기모드로 오픈하려는데 그게 0이 아닐떄? 
	{
		printf("열기 실패");
		fclose(fcsv);			// 열기 실패해도 닫아는 줌
	}
	while (1)		//계속 반복
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))		//만일 입력이 fcsv의 info가 NULL 상태이면
		{

			break;			//멈춤
		}

		if (info[0] == '\"')				//첫 문자가 쉼표 인경우?
		{
			printf("asdaf");			//asdaf 출력해라
			while (1)				// 아랫거 반본하는 동안에?
			{
				if (info[i] == '"')		//따옴표가 나올 때 >> 엑셀 셀 안에 ,있는 경우 ""로 셀이 묶여있게 되므로 인식하게 하기 위해 설정
				{
					printf("1");			//1을 출력해라 >>왜?
					break;			//멈춤?
				}
				else if (info[i] == ',')		// 아니면 만일 쉼표뜬다면 
				{
					printf("2");			//2를 출력하고
					info[i] = ' ';				// 비워라...? 머여 이거 
				}
				++i;			// i를 증가시키고 while문은 돌아간다아
			}
		}

		printf("%s", info);		//정리된 info를 출력함


		
	}

	fclose(fcsv);		//문서 닫음

}
void csv_file(char directory[50])
{
	FILE* fcsv;
	char info[100];
	char* next_point;
	char* cut;
	
	int flag = 0;		// csv파일 0행에 있는 줄을 출력하지 않기 위해 .. 1번째 실행부터 cut출력
	int i =0; // 셀 안에 ,가 들어가는 경우를 위한 변수 선언

	
	if (fopen_s(&fcsv, directory, "r") != 0)
	{
		printf("열기 실패");
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
			if (info[i] == '\"') // 뒤에 " , " 표시 출력
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
					printf("%s --- %d", cut,flag); //<< 지우지 말기

					

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
				//printf(" %s\n", slice); << 지우지 말기

				//3개로 분리했음. num에 받은걸 숫자로 변환하기. name이랑 comp는 배열에 저장하던가 하기.
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
		printf("%d 번째 팀명 입력 : ", (i + 1));
		t12[i].num = i + 1;
		scanf_s("%s", t12[i].name, sizeof(t12[i].name));
		printf("회사명 입력 : ");
		scanf_s("%s", t12[i].comp, sizeof(t12[i].comp));
		printf("=======================\n");

	}

}
// 임의대로 짜본 조건문

void print_info(search_team *st)
{
	int chk;
	

	while (1)
	{
		printf("======1:조장 검색======\n======2:회사 검색======\n======3:이름 검색======\n======4:학교 검색======5:검색 종료======\n===================\n입	력:	");
	scanf_s("%d", &chk);
	switch (chk)
	{
		// 번호로 정렬
	case 1:

		sort_lead(st);

		break;

		// 팀명 정렬
	case 2:

		sort_name(st);

		break;

		// 회사명 정렬
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
	printf("번호		   팀명			  회사명\n");
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

	printf("번호		   팀명			  회사명\n");
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

	printf("번호		   팀명			  회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}