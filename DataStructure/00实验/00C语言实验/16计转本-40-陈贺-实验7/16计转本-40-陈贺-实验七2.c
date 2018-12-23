/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *C语言实验七2
 *****************/
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
	long num;
	char name[20];
	char sex;
	int age;
	long score;
	struct Student *next;
};

struct Student *creat( struct Student *p, int x )
{
	int		n = 0;
	struct Student	*p1, *p2, *head;
	p1	= p2 = (struct Student *) malloc( LEN );
	head	= NULL;
	p1	= p;
	while ( n < x )
	{
		n = n + 1;
		if ( n == 1 )
			head = p1;
		else
			p2->next = p1;
		p2	= p1;
		p1	= (struct Student *) malloc( LEN );
		p1	= p + n;
	}
	p2->next = NULL;
	return(head);
}


void print( struct Student *head )
{
	struct Student *p;
	printf( "\nNow,These records are:\n" );
	p = head;
	if ( head != NULL )
		do
		{
			printf( "%ld %s %c %d %ld\n", p->num, p->name, p->sex, p->age, p->score );
			p = p->next;
		}
		while ( p != NULL );
}


int search( struct Student*head )
{
	struct Student *p1;
	p1 = head;
	if ( head == NULL )
	{
		printf( "\n list null\n" );
		return(0);
	}
	int n = 0;
	while ( p1 != NULL )
	{
		if ( p1->score > 60 )
			n = n + 1;
		p1 = p1->next;
	}
	printf( "优秀学生%d", n );

	return(0);
}


int main( void )
{
	struct Student	stu[3];
	int		i;
	printf( "enter the data:\n" );
	for ( i = 0; i < 3; i++ )
		scanf( "%ld %s %c %d %ld", &stu[i].num, &stu[i].name, &stu[i].sex, &stu[i].age, &stu[i].score );
	struct Student *head;
	head = creat( stu, 3 );
	print( head );
	int search( struct Student *head );
	search( head );


	return(0);
}


