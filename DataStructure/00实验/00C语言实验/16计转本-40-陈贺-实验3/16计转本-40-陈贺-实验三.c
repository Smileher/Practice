/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *C����ʵ����
 *****************/
#include <stdio.h>
//�ݹ�ʵ��
int Fbi_ch(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fbi_ch(n - 1) + Fbi_ch(n - 2);
}
int main(void)
{
    int i;
    printf("��1����1\n");
    for (i = 2; i <= 20; i++)
        printf("��%d����%d,���%d��ı�Ϊ%.4f\n", i, Fbi_ch(i), i - 1, (double)Fbi_ch(i) / Fbi_ch(i - 1));
    return 0;
}
#include <stdio.h>
#define N 3
typedef struct student_CH
{
    char number[32];
    char name[32];
    char sex[32];
    double score[N];
} STU;
double average(STU student_CH)
{
    double sum;
    int i;
    sum = 0.0;
    for (i = 0; i < N; i++)
    {
        sum = sum + student_CH.score[i];
    }
    return (sum / N);
}
double highest(STU student_CH)
{
    double max;
    int i;
    max = student_CH.score[0];
    for (i = 0; i < N; i++)
    {
        if (max < student_CH.score[i])
            max = student_CH.score[i];
    }
    return max;
}
int main(void)
{
    STU student_CH;
    int i;
    printf("������ѧ�ţ�");
    scanf("%s", &student_CH.number);
    printf("������������");
    scanf("%s", &student_CH.name);
    printf("�������Ա�");
    scanf("%s", &student_CH.sex);
    for (i = 0; i < N; i++)
    {
        printf("�������%d�ſγɼ���", i + 1);
        scanf("%lf", &student_CH.score[i]);
    }
    printf("%s��ƽ���ɼ�Ϊ��%.1lf", student_CH.name, average(student_CH));
    printf("\n%s����߳ɼ�Ϊ��%.1lf", student_CH.name, highest(student_CH));
    return 0;
}