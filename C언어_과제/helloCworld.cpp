#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


/* 구조체 기반의 팀 리스트 정렬 알고리즘 */

/* ID, 팀 명, 회사 명을 구별 항목으로 설정하여
6개의 팀 명과 회사명을 입력받고
각 항목 별로 정렬 할 수 있도록 swith 함수로 case 지정
ID는 순서대로 printf
팀명은 알파벳 오름차순 정렬을 위해 각 팀 명 strcmp 함수 이용하여 비교 
회사명 정렬 동일하게 적용*/

struct team {
	int num;	// 팀 ID
	char name[30];	// 팀 명
	char comp[30];	// 회사 명

};

//함수 선언
void sort_name(struct team* t);	//매개 변수로 구조체 포인터 
void sort_comp(struct team* t);	


int main(void) {


	struct team t1[6];

	int i, chk;						//chk swith 함수를 위한 변수

	for (i = 0; i < 6; i++)
	{
		printf("%d 번째 팀명 입력 : ", (i + 1));	
		t1[i].num = i + 1;										// 입력순서대로 팀 ID 지정
		scanf_s("%s", t1[i].name, sizeof(t1[i].name));
		printf("회사명 입력 : ");
		scanf_s("%s", t1[i].comp, sizeof(t1[i].comp));
		printf("=======================\n");

	}
/*
	//정렬 전
	//for (i = 0; i < 2; i++)
	printf("번호   팀명   회사명\n");
	for (i = 0; i < 6; i++)
	{

		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);			// 입력순서대로 이니까 실상 팀 ID 순 정렬
	}*/


	//정렬 후 -- 정렬 알고리즘 넣어서 출력.
	printf("번호로 정렬 시 1 입력, 팀명 정렬 시 2 입력, 회사명 정렬 시 3 입력  : ");
	scanf_s("%d", &chk);
	switch (chk)
	{
		// 번호로 정렬
	case 1:

		printf("번호   팀명   회사명\n");
		for (i = 0; i < 6; i++)
		{
			printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
		}

		break;

		// 팀명 정렬
	case 2:

		sort_name(t1);					//sort_name 함수 호출

		break;

		// 회사명 정렬
	case 3:

		sort_comp(t1);					//sort_comp 함수 호출

		break;
	}




	return 0;

}


void sort_name(struct team* t)					//sort_name 함수 정의
{
	int i, j;
	team cmp[6];								// 구조체 배열 선언
	team tmp;									// 임시 구조체 선언



	//cmp에 팀이름 모두 복사
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
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)			// > 0 인 경우 cmp[j]>com[j+1]
			{

				
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;            // 큰 변수를 오른쪽으로 위치 복사>> 오름차순 정렬 


			}
		}

	}

	printf("번호      팀명      회사명\n");
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



	//cmp에 팀이름 모두 복사
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

	printf("번호      팀명      회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}


}