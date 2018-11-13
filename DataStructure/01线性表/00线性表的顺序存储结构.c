/*
* 文件名：[线性表(顺序存储结构)]
* 作者：〈陈贺〉
* 描述：〈线性表(顺序存储结构)的一些常见基本操作的实现以及详细注释〉
* 日期：2018-10-16
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20  /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假设为int */
typedef int Status;     /* Status是函数的类型，其返回值是函数结果状态代码，如OK  */

typedef struct
{
	ElemType data[MAXSIZE]; /* 定义一个ElemTyoe类型的名称为data的数组，数组长度为MAXSIZE */
	int length;             /* 定义一个length变量作为线性表当前长度 */
}SqList;

/* 初始化顺序线性表 */
Status InitList(SqList *L)
{
	L->length = 0; /* 线性表的长度L->length赋值为0 */
	return OK;
}

/* 顺序表的建立 */
SqList Create(SqList L)
{
	int i;
	srand((unsigned)time(NULL)); /* 用系统当前时间初始化种子创建随机数 */
	for (i = 0; i < 10; i++)
	{
		L.data[i] = rand() % 100; /* 为线性表中的每一个元素赋随机值 */
		L.length++; /* 每赋值一次线性表的长度加1 */
	}
	return L; /* 函数Create为SqList类型，返回线性表L */
}

/* 初始条件：顺序线性表L已存在。*/
/* 操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{
	L->length = 0; /* L->length的长度赋值为0 */
	return OK;
}


/*初始条件：ListTraverse函数调用 */
/*操作结果：打印对应元素 */
Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L) */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L, int i, ElemType e) /* 线性表L，待插入的位置i，待插入的元素e */
{
	int k;
	if (L->length == MAXSIZE) /* 顺序线性表已满 */
		return ERROR;
	if (i < 1 || i>L->length + 1) /* i比第一位置小或者比最后一位置后一位置还要大 */
		return ERROR;

	if (i <= L->length) /* 待插入数据位置不在表尾 */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* k是线性表中最后一个元素 1 2 ★ 3 4 5 k=5 i=3 */
			L->data[k + 1] = L->data[k]; /* 将要插入位置之后的数据元素向后移动一位 */
	}
	L->data[i - 1] = e; /* 将新元素插入 */
	L->length++; /* 线性表长度加1 */

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i, ElemType *e) /* 线性表L，待删除元素的位置i，用于保存元素的*e */
{
	int k;
	if (L->length == 0) /* 线性表为空 */
		return ERROR;
	if (i < 1 || i>L->length) /* 删除位置不正确 */
		return ERROR;
	*e = L->data[i - 1]; /* 把待删除的元素的值赋给e */
	if (i < L->length) /* 如果删除不是最后位置 */
	{
		for (k = i; k < L->length; k++) /* 将删除位置后继元素前移 */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 1 || i>L.length) /* 如果线性表为空表或位置i小于1或位置i大于1 */
		return ERROR;
	*e = L.data[i - 1]; /* 把第i个元素（在data[]数组中是i-1的位置）的值赋给e */
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L的长度。 */
int ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{
	return (L.length == 0) ? TRUE : FALSE;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序，若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0) /* 如果线性表为空表 */
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e) /* 如果e的值与数组的第i个（线性表的第i+1个）元素相等 */
			break;
	}
	if (i >= L.length) /* 如果线性表中找不到与e相等的元素 */
		return 0;

	return i + 1; /* 数组的第i个元素等于线性表的第i+1个元素 */
}

int main()
{
	SqList L; /* 线性表 */
	ElemType e; /* 要操作的元素数值 */
	Status i; /* int i */
	int opp; /* 输入的操作步骤序号 */
	int k; /* int k */
	int pos; /* 要操作的元素位置 */
	ElemType value; /* 要操作的元素数值 */

	i = InitList(&L);
	printf("欢迎使用线性表程序(By ChenHe)\n");
	printf("线性表初始化成功，L.length=%d，请完成以下操作\n", L.length);
	printf("\n1.线性表赋值 \n2.遍历线性表 \n3.清空线性表 \n4.线性表插入 \n5.查找表中元素 \n6.判断元素是否在表中 \n7.删除某个元素 \n8.线性表长度\n9.线性表是否为空\n0.退出 \n请输入您要完成的操作(0-9)：\n");
	scanf("%d", &opp);
	while (opp != 1)
	{
		printf("请先输入1，为线性表赋值10个随机数字\n");
		scanf("%d", &opp);
	}
	while (opp != 0) {
		switch (opp) {

			//线性表赋值
		case 1:
			L = Create(L);
			printf("创建随机顺序表：L.data=");
			ListTraverse(L);
			printf("\n");
			break;

			//遍历线性表
		case 2:
			ListTraverse(L);
			printf("\n");
			break;

			//清空线性表
		case 3:
			i = ClearList(&L);
			printf("清空L后：L.length=%d\n", L.length);
			ListTraverse(L);
			printf("\n");
			break;

			//线性表插入
		case 4:
			printf("请输入插入元素位置：");
			scanf("%d", &pos);
			printf("请输入插入元素的值：");
			scanf("%d", &value);
			i = ListInsert(&L, pos, value);
			printf("插入完毕，现在线性表为：\n");
			ListTraverse(L);
			printf("\n");
			break;

			//查找表中元素
		case 5:
			printf("你要查找第几个元素？");
			scanf("%d", &pos);
			GetElem(L, pos, &e);
			printf("第%d个元素的值为：%d\n", pos, e);
			break;

			//判断元素是否在表中
		case 6:
			printf("输入你想知道是否在表中的数值：");
			scanf("%d", &e);
			k = LocateElem(L, e);
			// 这里假定随机数组中的元素互不重复
			if (k)
				printf("值为%d是表中的第%d个元素\n", e, k);
			else
				printf("没有值为%d的元素\n", e);
			break;

			//删除某个元素
		case 7:
			printf("要删除第几个元素？");
			scanf("%d", &pos);
			ListDelete(&L, pos, &e);
			printf("删除完毕，现在线性表为：\n");
			ListTraverse(L);
			printf("\n");
			break;

			//线性表长度
		case 8:
			k = ListLength(L);
			printf("线性表的长度为: %d \n", k);
			break;

			//线性表是否为空
		case 9:
			i = ListEmpty(L);
			if (i)
				printf("该线性表为空.\n");
			else
				printf("该线性表非空\n");
			break;
			//退出
		case 0:
			exit(0);
		default:
			printf("输入错误，请重新输入(0-9)\n");
		}
		printf("请继续输入您的操作(0-9):\n");
		scanf("%d", &opp);
	}
}
//By Smileher
