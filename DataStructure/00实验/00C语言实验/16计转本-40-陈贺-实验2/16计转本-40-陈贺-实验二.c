/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *C����ʵ���
 *****************/
#include <stdio.h>
//�ݹ�ʵ��
int Fbi_ch(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fbi_ch(n - 1) + Fbi_ch(n - 2);
}
int main(void)
{
    int i;
    printf("��1����1\n");
    for (i = 2; i <= 20; i++)
        printf("��%d����%d,���%d��ı�Ϊ%.4f\n", i, Fbi_ch(i), i - 1, (double)Fbi_ch(i) / Fbi_ch(i - 1));
    return 0;
}