/*****************
*班级：16计转本
*姓名：陈贺
*学号：20160566140
*C语言实验八2
*****************/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 2
struct std
{
	int num;
	char name[20];
	int grade;
}student[SIZE];

void save();
void print();

int main(void)
{
	save();
	print();
	return 0;
}

void save()
{
    int i,j;
	for ( i = 0; i < SIZE; i++ )
	{
		printf( "请输入第%d个学生的学号，姓名，成绩:\n", i + 1 );
		scanf( "%d %s %d", &student[i].num, &student[i].name, &student[i].grade );
	}
	FILE *fp;
	if ( (fp = fopen( "file2.txt", "w" ) ) == NULL )
		return;
	for ( j = 0; j < SIZE; j++ )
	{
		if ( fwrite( &student[j], sizeof(struct std), 1, fp ) != 1 )
			printf( "录入出错！\n" );
	}
	fclose( fp );
}

void print()
{
	FILE *fp;
	struct std	p[SIZE];
	if ( (fp = fopen( "file2.txt", "r" ) ) == NULL )
		return;
	printf( "文件中内容为：\n" );
	printf( "学号\t姓名\t成绩\t\n" );
    int i;
	for ( i = 0; i < SIZE; i++ )
	{
		if ( feof( fp ) )
		{
			fclose( fp );
			return;
		}
		if ( fread( &p[i], sizeof(struct std), 1, fp ) != 1 )
			printf( "读取失败！\n" );
		printf( "%d\t%s\t%d\t\n", p[i].num, p[i].name, p[i].grade );
	}
	fclose( fp );
}