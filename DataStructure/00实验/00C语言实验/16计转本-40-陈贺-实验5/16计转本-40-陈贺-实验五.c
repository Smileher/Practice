/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *C����ʵ����
 *****************/
#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct student_CH
{
	char number[32];
	char name[32];
	char sex[32];
	double score[N];
} STU;
void average(STU *student_CH,double *avg)
{
	double sum;
	int i;
	sum = 0.0;
	for (i = 0; i < N; i++)
	{
		sum = sum + student_CH->score[i];
	}
    *avg=sum/N;
}
void highest(STU *student_CH,double *max)
{
	int i;
	*max = student_CH->score[0];
	for (i = 0; i < N; i++)
	{
		if (*max < student_CH->score[i])
			*max = student_CH->score[i];
	}
}
int main(void)
{
	STU *student_CH;
	int i;
    double avg;
	double max;
	student_CH = (STU *)malloc(sizeof(STU));
	printf("������ѧ�ţ�");
	scanf("%s", student_CH->number);
	printf("������������");
	scanf("%s", student_CH->name);
	printf("�������Ա�");
	scanf("%s", student_CH->sex);
	for (i = 0; i < N; i++)
	{
		printf("�������%d�ſγɼ���", i + 1);
		scanf("%lf", &student_CH->score[i]);
	}
    average(student_CH,&avg);
    highest(student_CH,&max);
	printf("%s��ƽ���ɼ�Ϊ��%.1lf", student_CH->name, avg);
	printf("\n%s����߳ɼ�Ϊ��%.1lf", student_CH->name, max);
	free(student_CH);
	return 0;
}
