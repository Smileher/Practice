package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数
 */
import java.util.Scanner;

public class Exp0202_20160566140 {
    public static void main(String[] args) {
        int x, y;
        Scanner in = new Scanner(System.in);
        System.out.print("请输入x：");
        x = in.nextInt();
        int[] a = new int[x];
        System.out.print("输入位移个数y：(y<x)");
        y = in.nextInt();
        if (y > x)
            System.out.printf("输入有误!");
        else {
            System.out.printf("输入%d个数\n", x);
            for (int i = 0; i < x; i++) {
                a[i] = in.nextInt();
            }
            System.out.println("所输入的数组为： ");
            for (int i = 0; i < x; i++) {
                System.out.printf("%3d", a[i]);
            }
            System.out.println("\n移动y位后的元素为： ");
            int t, j;
            for (int i = 0; i < y; i++) {
                t = a[0];
                for (j = 0; j < x - 1; j++)
                    a[j] = a[j + 1];
                a[j] = t;
            }
            for (int i = 0; i < x; i++) {
                System.out.printf("%3d", a[i]);
            }


        }
    }

}
