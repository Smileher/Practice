/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *C语言实验六
 *****************/
#include <stdio.h>
#include <string.h>
#define SN 2//学生数
#define N 5//课程数
//定义课程结构体类型【课程号、课程名、成绩】
typedef struct CLASS
{
    int number;
    char name[32];
    double score;
}CLASS;
//定义学生结构体类型【学号、姓名、5门课程】
typedef struct STU
{
    int number[32];
    char name[32];
    CLASS class[N];
}STU;
//定义学生信息输入函数，分别输入若干学生信息
void input(STU student[SN])
{
    int i,j;
    printf("***************欢迎使用成绩管理系统(By陈贺)*****************\n");
    printf("请分别输入这%d门课的课程信息(课程号和课程名,用空格隔开)\n",N);
    
    for(j=0;j<N;j++)
    {
    	printf("第%d门课:",j+1);
    	scanf("%d %s",&student[0].class[j].number,student[0].class[j].name);
    	for(i=0;i<SN;i++)
    	{
			student[i+1].class[j].number=student[i].class[j].number;
			strncpy(student[i+1].class[j].name,student[i].class[j].name,32);
		}
	   		//while(getchar()=='\n'); 
	}
	
	printf("\n请分别输入这%d位学生的信息(学号和姓名，用空格隔开)\n",SN);
    for(i=0;i<SN;i++)
    {
        printf("第%d位学生:",i+1);
        scanf("%d %s",&student[i].number,student[i].name);
        for(j=0;j<N;j++)
        {
            printf("%s的%s课的成绩:",student[i].name,student[i].class[j].name);
            scanf("%lf",&student[i].class[j].score);
        }
    }
    
}
//定义求每个学生的总成绩函数
void score(STU student[SN],double scoreALL[SN])
{
    int i,j;
    //scoreALL[SN] = {0.0};
    for(i=0;i<SN;i++)
    {
        for(j=0;j<N;j++)
        {
            scoreALL[i]=student[i].class[j].score;
        }
    }
}
//定义求每门课程平均成绩函数和学生平均成绩
void average(STU student[SN],double averageCLASS[N],double averageSTU[SN],double scoreALL[SN])
{
    int i,j;
    //averageCLASS[N]={0.0};
    //averageSTU[SN]={0.0};
    for(i=0;i<SN;i++)
    {
        averageSTU[i]=scoreALL[i]/SN;
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<SN;i++)
        {
            averageCLASS[j]=student[i].class[j].score;
        }
    }
}
int main(void)
{
    int i,j;
    STU student[SN];//定义学生数组存储
    double scoreALL[SN]={0.0};//每个学生的总成绩
    double averageCLASS[N]={0.0};//每门课程平均成绩
    double averageSTU[SN]={0.0};//学生平均成绩
    input(student);
    score(student,scoreALL);
    average(student,averageCLASS,averageSTU,scoreALL);
    printf("\n一共有%d个学生:\n",SN);
    for(i=0;i<SN;i++)
    {
    	printf("****************************************\n学生:%s\n",student[i].name);
        for(j=0;j<N;j++)
        {
            printf("%s课的成绩是%.2lf:\n",student[i].class[j].name,student[i].class[j].score);
        }
        printf("总成绩是:%.2lf,平均成绩是:%.2lf\n\n",scoreALL[i],averageSTU[i]);
    }
    printf("\n一共有%d门课:\n",N);
    for(j=0;j<N;j++)
    {
    	printf("%s这门课所有人的平均成绩是:%.2lf\n",student[0].class[j].name,averageCLASS[j]);
	}
    return 0;
}
