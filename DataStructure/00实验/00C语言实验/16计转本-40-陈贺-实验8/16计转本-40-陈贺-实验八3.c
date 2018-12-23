/*****************
*班级：16计转本
*姓名：陈贺
*学号：20160566140
*C语言实验八3
*****************/
#include <stdio.h>
#include <stdlib.h>
struct S
{
	int	num;
	char name[20];
	int	score;
}s[3];
int	i;
int main(void)
{
	void save();
	void print();
	for ( i = 0; i < 3; i++ )
	{
		printf( "请输入第%d名学生的学号，姓名，成绩.\n", i + 1 );
		scanf( "%d%s%d", &s[i].num, &s[i].name, &s[i].score );
	}
	FILE *p = fopen( "file2.txt", "wb" );
	if ( p == NULL )
	{
		printf( "打开文件出错.\n" );
		exit( 0 );
	}
	FILE *po = fopen( "file3.txt", "wb" );
	if ( po == NULL )
	{
		printf( "打开文件出错.\n" );
		exit( 0 );
	}
	for ( i = 0; i < 3; i++ )
		fwrite( &s[i], sizeof(struct S), 1, p );
	for ( i = 0; i < 3; i += 2 )
	{
		fseek( p, 2 * sizeof(struct S), 0 );
		fread( &s[i], sizeof(struct S), 1, p );
		printf( "学号\t姓名\t成绩\n%d\t%s\t%d\n", s[i].num, s[i].name, s[i].score );
		fwrite( &s[i], sizeof(struct S), 1, po );
		if ( feof( p ) == 1 )
			break;
	}
	fclose(p);
	fclose(po);
	return 0;
}