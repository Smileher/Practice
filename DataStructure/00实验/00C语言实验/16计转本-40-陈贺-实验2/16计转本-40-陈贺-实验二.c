/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *C语言实验二
 *****************/
#include <stdio.h>
//递归实现
int Fbi_ch(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fbi_ch(n - 1) + Fbi_ch(n - 2);
}
int main(void)
{
    int i;
    printf("第1项是1\n");
    for (i = 2; i <= 20; i++)
        printf("第%d项是%d,与第%d项的比为%.4f\n", i, Fbi_ch(i), i - 1, (double)Fbi_ch(i) / Fbi_ch(i - 1));
    return 0;
}