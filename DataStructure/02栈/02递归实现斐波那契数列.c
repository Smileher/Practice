#include <stdio.h>
int Fbi(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fbi(n - 1) + Fbi(n - 2);
}
int main(void)
{
    int i;
    for (i = 1; i < 40; i++)
        printf("%d  ", Fbi(i));
    return 0;
}