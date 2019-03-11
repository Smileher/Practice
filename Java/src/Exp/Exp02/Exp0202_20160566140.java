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
        //n为位数 m为移动的数
        int n, m;
        Scanner input = new Scanner(System.in);
        //输入位数n并初始化数组a[n]
        System.out.print("请输入数组元素的个数n：");
        n = input.nextInt();
        int[] a = new int[n];
        //输入移动的个数m
        System.out.print("请输入位移个数m：(m<n)");
        m = input.nextInt();
        //判断 如果m>n
        if (m > n)
            System.out.print("输入有误!");
            //否则
        else {
            System.out.printf("输入%d个数\n", n);
            //输入数组元素
            for (int i = 0; i < n; i++) {
                a[i] = input.nextInt();
            }
            //输出原始数组
            System.out.println("所输入的数组为： ");
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }

            System.out.println("\n移动m位后的元素为： ");
            int temp, j;
            //移动数组
            for (int i = 0; i < m; i++) {
                temp = a[0];
                for (j = 0; j < n - 1; j++)
                    a[j] = a[j + 1];
                a[j] = temp;
            }
            //输出移动后的数组
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
                //System.out.println(String.format("%5d",a[i]));
            }
            //System.out.println(Arrays.toString(a));
        }
    }

}
