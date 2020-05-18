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
		printf("%d 번째 팀명 입력 : ", (i + 1));
		t1[i].num = i + 1;
		scanf_s("%s", t1[i].name,sizeof(t1[i].name));
		printf("회사명 입력 : ");
		scanf_s("%s", t1[i].comp,sizeof(t1[i].comp));
		printf("=======================\n");

	}

	//정렬 전
	//for (i = 0; i < 2; i++)
	printf("번호   팀명   회사명\n");
	for (i = 0; i < 6; i++)
	{
		
		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}


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

		sort_name(t1);

		break;

	// 회사명 정렬
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
			if (strcmp(cmp[j].name, cmp[j+1].name) > 0)
			{
				
				                               // 큰 값을
					tmp = cmp[j];
					cmp[j] = cmp[j + 1];
					cmp[j + 1] = tmp;            // 다음 요소로 보냄
				
				
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