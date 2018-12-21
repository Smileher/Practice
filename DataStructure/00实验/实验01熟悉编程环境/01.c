/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *实验一熟悉编程环境
 *****************/
#include <stdio.h>
#include <conio.h>

struct subject
{
    int subject_id;
    char subject_name[20];
    double subject_grades;
};

struct subject sub[10];

void input()
{
    int i;
    printf("please input:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d %s %lf", &sub[i].subject_id, &sub[i].subject_name, &sub[i].subject_grades);
    }
    printf("you just input:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d %s %lf\n", sub[i].subject_id, sub[i].subject_name, sub[i].subject_grades);
    }
}

void subject_max()
{
    int i, flag;
    double max = sub[0].subject_grades;
    for (i = 0; i < 10; i++)
    {
        if (sub[i].subject_grades > max)
            max = sub[i].subject_grades;
        flag = i;
    }
    printf("The high score of subject is %s %lf\n", sub[flag].subject_name, max);
}

void subject_average()
{
    int i;
    double average, sum = sub[0].subject_grades;
    for (i = 1; i < 10; i++)
    {
        sum += sub[i].subject_grades;
    }
    average = sum / 10;
    printf("subject's average is %lf\n", average);
}

void subjct_gtaverage()
{
    int i, flag;
    double average, sum = sub[0].subject_grades;
    for (i = 1; i < 10; i++)
    {
        sum += sub[i].subject_grades;
    }
    average = sum / 10;
    for (i = 0; i < 10; i++)
    {
        if (sub[i].subject_grades > average)
        {
            flag = i;
            printf("subject greater than average is %s %lf\n", sub[flag].subject_name, sub[flag].subject_grades);
        }
    }
}
int main(void)
{
    input();
    subject_max();
    subject_average();
    subjct_gtaverage();
    return 0;
}
