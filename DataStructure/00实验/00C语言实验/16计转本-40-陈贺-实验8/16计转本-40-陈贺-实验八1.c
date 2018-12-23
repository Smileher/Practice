/*****************
*班级：16计转本
*姓名：陈贺
*学号：20160566140
*C语言实验八1
*****************/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char in[100];
	printf( "请输入要录入的字符串：\n" );
	gets( in );
	FILE *fp;
	if ( (fp = fopen( "file1.txt", "w" ) ) == NULL )
		exit( 0 );
	fputs( in, fp );
	fputs( "\n", fp );
	fclose( fp );
	if ( (fp = fopen( "file1.txt", "r" ) ) == NULL )
		exit( 0 );
	char out[100];
	fgets( out, 100, fp );
	printf( "已结录入的信息为：\n" );
	printf( "%s", out );
	return 0;
}