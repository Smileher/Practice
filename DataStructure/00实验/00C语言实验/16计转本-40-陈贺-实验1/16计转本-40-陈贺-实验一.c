/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *C����ʵ��һ
 *****************/
#include <stdio.h>
//�ж��Ƿ�������ĺ���
int faction_ch(int year_ch)
{
    if (year_ch % 4 == 0 && year_ch % 100 || year_ch % 400 == 0)
        return 1;
    else
        return 0;
}
//�����жϺ����ĺ���
int year_ch(int start_year_ch, int end_year_ch)
{
    int i, count_ch;
    i = start_year_ch;
    count_ch = 0;
    do
    {
        if (faction_ch(i))
        {
            printf("%d������\n", i);
            count_ch++;
        }
        i++;
    } while (i <= end_year_ch);
    if (count_ch)
        return 1;
    else
        return 0;
}
//������
int main(void)
{
    int start_year_ch, end_year_ch, result_ch;
    printf("��������ʼ��ݣ�");
    scanf("%d", &start_year_ch);
    printf("��������ֹ��ݣ�");
    scanf("%d", &end_year_ch);
    if (start_year_ch > end_year_ch || start_year_ch < 0 || end_year_ch < 0)
        printf("�������");
    else
    {
        printf("%d����%d��֮�䣺\n", start_year_ch, end_year_ch);
        result_ch = year_ch(start_year_ch, end_year_ch);
        if (!result_ch)
        {
            printf("������");
        }
    }
    return 0;
}