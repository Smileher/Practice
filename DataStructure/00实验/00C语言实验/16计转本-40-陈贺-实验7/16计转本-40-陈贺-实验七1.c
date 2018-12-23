/*****************
*班级：16计转本
*姓名：陈贺
*学号：20160566140
*C语言实验七1
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
struct Student *find( struct Student *head, long num )
{
	struct Student *p1;
	p1 = head;
	if ( head == NULL )
	{
		printf( "\n list null\n" );
		return(head);
	}
	while ( num != p1->num && p1->next != NULL )

		p1 = p1->next;
	if ( num == p1->num )
		return(p1);
}


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


struct Student *insert( struct Student *head, struct Student *stud )
{
	struct Student *p0, *p1, *p2;
	p1	= head;
	p0	= stud;
	if ( head == NULL )
	{
		head		= p0;
		p0->next	= NULL;
	}else  { while ( (p0->num > p1->num) && (p1->next != NULL) )
		 {
			 p2	= p1;
			 p1	= p1->next;
		 }
		 if ( p0->num <= p1->num )
		 {
			 if ( head = p1 )
				 head = p0;
			 else
				 p2->next = p0;
			 p0->next = p1;
		 }else  { p1->next	= p0;
			  p0->next	= NULL; } }
	return(head);
}


struct Student *del( struct Student *head, long num )
{
	struct Student *p1, *p2;
	p1 = head;
	if ( head == NULL )
	{
		printf( "\n list null\n" );
		return(head);
	}
	while ( num != p1->num && p1->next != NULL )
	{
		p2	= p1;
		p1	= p1->next;
	}
	if ( num == p1->num )
	{
		if ( head == p1 )
			head = p1->next;
		else
			p2->next = p1->next;
		printf( "delete:%d\n", num );
	}else
		printf( "%ld not been found", num );
	return(head);
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
	printf( "输入要查找的学号:\n" );
	long x;
	scanf( "%ld", &x );
	while ( x != 0 )
	{
		head = find( head, x );
		printf( "%ld %s %c %d %ld\n", head->num, head->name, head->sex, head->age, head->score );
		printf( "输入要查找的学号:\n" );
		scanf( "%ld", &x );
	}
	head = creat( stu, 3 );
	printf( "输入要删除的学号:\n" );
	long nu;
	scanf( "%ld", &nu );
	while ( nu != 0 )
	{
		head = del( head, nu );
		print( head );
		printf( "输入要删除的学号:\n" );
		scanf( "%ld", &nu );
	}
	printf( "输入插入的数据:\n" );
	struct Student *stude;
	stude = (struct Student *) malloc( LEN );
	scanf( "%ld %s %c %d %ld", &stude->num, &stude->name, &stude->sex, &stude->age, &stude->score );
	while ( stude->num != 0 )
	{
		head = insert( head, stude );
		print( head );
		printf( "输入插入的数据:\n" );
		stude = (struct Student *) malloc( LEN );
		scanf( "%ld %s %c %d %ld", &stude->num, &stude->name, &stude->sex, &stude->age, &stude->score );
	}
	return(0);
}