/*****************
*�༶��16��ת��
*�������º�
*ѧ�ţ�20160566140
*C����ʵ���1
*****************/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char in[100];
	printf( "������Ҫ¼����ַ�����\n" );
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
	printf( "�ѽ�¼�����ϢΪ��\n" );
	printf( "%s", out );
	return 0;
}