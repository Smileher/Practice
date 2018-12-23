/*****************
 *班级：16计转本
 *姓名：陈贺
 *学号：20160566140
 *C语言实验一
 *****************/
#include <stdio.h>
//判断是否是闰年的函数
int faction_ch(int year_ch)
{
    if (year_ch % 4 == 0 && year_ch % 100 || year_ch % 400 == 0)
        return 1;
    else
        return 0;
}
//调用判断函数的函数
int year_ch(int start_year_ch, int end_year_ch)
{
    int i, count_ch;
    i = start_year_ch;
    count_ch = 0;
    do
    {
        if (faction_ch(i))
        {
            printf("%d是闰年\n", i);
            count_ch++;
        }
        i++;
    } while (i <= end_year_ch);
    if (count_ch)
        return 1;
    else
        return 0;
}
//主函数
int main(void)
{
    int start_year_ch, end_year_ch, result_ch;
    printf("请输入起始年份：");
    scanf("%d", &start_year_ch);
    printf("请输入终止年份：");
    scanf("%d", &end_year_ch);
    if (start_year_ch > end_year_ch || start_year_ch < 0 || end_year_ch < 0)
        printf("输入错误！");
    else
    {
        printf("%d年与%d年之间：\n", start_year_ch, end_year_ch);
        result_ch = year_ch(start_year_ch, end_year_ch);
        if (!result_ch)
        {
            printf("无闰年");
        }
    }
    return 0;
}