/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *ʵ��ʮ��ѡ�������㷨��ʵ��
 *****************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUM 20000
int heapSize = 0;
//��ȡ�����,�����ӡ�Ķ�
int *getRandNum(int n)
{
    int i;
    int *p;

    p = (int *)malloc(sizeof(int) * n);
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        p[i] = rand(); //�������Χ���޸����
    }
    return p;
}

int Left(int index)
{
    return ((index << 1) + 1);
}
int Right(int index)
{
    return ((index << 1) + 2);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(int array[], int index)
{
    int largest = 0;
    int left = Left(index);
    int right = Right(index);

    if ((left <= heapSize) && (array[left] > array[index]))
        largest = left;
    else
        largest = index;

    if ((right <= heapSize) && (array[right] > array[largest]))
        largest = right;

    if (largest != index)
    {
        swap(&array[largest], &array[index]);
        maxHeapify(array, largest);
    }
}
void buildMaxHeap(int array[], int length)
{
    int i;
    heapSize = length;
    for (i = (length >> 1); i >= 0; i--)
        maxHeapify(array, i);
}
void heap_sort(int array[], int length)
{
    int i;

    buildMaxHeap(array, (length - 1));
    for (i = (length - 1); i >= 1; i--)
    {
        swap(&array[0], &array[i]);
        heapSize--;
        maxHeapify(array, 0);
    }
}
void selection(int *src, int len)
{
    int i, j, k, temp;

    for (i = 0; i < len; i++)
    {
        for (j = i + 1, k = i; j < len; j++)
        {

            if (src[k] > src[j])
            {
                k = j;
            }
        }
        temp = src[i];
        src[i] = src[k];
        src[k] = temp;
    }
}
void display(int *src, int len)
{
    int i;

    for (i = 0; len > 0 && i < len; i++)
    {
        printf("%d ", src[i]);
    }
    printf("\n");
}
int main(void)
{
    int *data;
    int *data2;
    struct timeval begin, end;
    double selectTime, heapTime;
    data = getRandNum(NUM);
    data2 = (int *)malloc(sizeof(int) * NUM);
    memcpy(data2, data, sizeof(int) * NUM);
    //display(data, NUM);
    //printf("ѡ�������С�����\n");
    gettimeofday(&begin, NULL);
    selection(data, NUM);
    gettimeofday(&end, NULL);
    selectTime = end.tv_sec - begin.tv_sec + (end.tv_usec - begin.tv_usec) / 1000000.0;
    //display(data, NUM);
    //printf("�������С�����\n");
    gettimeofday(&begin, NULL);
    heap_sort(data2, NUM);
    gettimeofday(&end, NULL);
    heapTime = end.tv_sec - begin.tv_sec + (end.tv_usec - begin.tv_usec) / 1000000.0;
    //display(data2, NUM);
    printf("һ����%d������\nѡ�������ʱ= %lf��, �������ʱ=%lf��\n", NUM, selectTime, heapTime);
    free(data);
    free(data2);
    return 0;
}