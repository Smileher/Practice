/*****************
*�༶��16��ת��
*�������º�
*ѧ�ţ�20160566140
*C����ʵ���2
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
		printf( "�������%d��ѧ����ѧ�ţ��������ɼ�:\n", i + 1 );
		scanf( "%d %s %d", &student[i].num, &student[i].name, &student[i].grade );
	}
	FILE *fp;
	if ( (fp = fopen( "file2.txt", "w" ) ) == NULL )
		return;
	for ( j = 0; j < SIZE; j++ )
	{
		if ( fwrite( &student[j], sizeof(struct std), 1, fp ) != 1 )
			printf( "¼�����\n" );
	}
	fclose( fp );
}

void print()
{
	FILE *fp;
	struct std	p[SIZE];
	if ( (fp = fopen( "file2.txt", "r" ) ) == NULL )
		return;
	printf( "�ļ�������Ϊ��\n" );
	printf( "ѧ��\t����\t�ɼ�\t\n" );
    int i;
	for ( i = 0; i < SIZE; i++ )
	{
		if ( feof( fp ) )
		{
			fclose( fp );
			return;
		}
		if ( fread( &p[i], sizeof(struct std), 1, fp ) != 1 )
			printf( "��ȡʧ�ܣ�\n" );
		printf( "%d\t%s\t%d\t\n", p[i].num, p[i].name, p[i].grade );
	}
	fclose( fp );
}