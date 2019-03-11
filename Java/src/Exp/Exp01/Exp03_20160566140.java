package Exp.Exp01;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-3
 * 本程序的功能是：在控制台输出特定的图形
 */

import java.util.Scanner;

public class Exp03_20160566140 {
    public static void main(String[] args) {
        //声明一个变量
        Scanner input = new Scanner(System.in);
        int a;
        int rows = 0;
        while (true) {
            //输出总菜单
            System.out.println("【1】输入图形的行数  【2】打印哪个图形 【3】退出");
            a = input.nextInt();
            //判断
            switch (a) {
                case 1:
                    System.out.println("请输入图形行数");
                    rows = input.nextInt();
                    break;
                case 2:
                    //输出选择哪个图形的菜单
                    System.out.println("【1】图形一     【2】图形二     【3】图形三     【4】图形四");
                    int b = input.nextInt();
                    //进行选择哪个图形的判断
                    if (b == 1) graph1(rows);
                    if (b == 2) graph2(rows);
                    if (b == 3) graph3(rows);
                    if (b == 4) graph4(rows);
                    break;
                case 3:
                    System.exit(0);
            }
        }
    }

    //输出第一个图形
    private static void graph1(int rows) {
        int a = 0;
        for (int i = 1; i <= rows; i++) {
            a = a * 10 + i;
            System.out.println(a);
        }
    }

    //输出第二个图形
    private static void graph2(int rows) {
        int a = 0;
        for (int i = 1; i <= rows; i++) {
            a = a * 10 + i;
        }
        for (int i = 0; i < rows; i++) {
            System.out.println(a);
            a = a / 10;
        }
    }

    //输出第三个图形
    private static void graph3(int rows) {
        for (int i = 1; i <= rows; i++) {
            for (int j = 0; j <= rows - i - 1; j++) {
                System.out.print(" ");
            }
            for (int k = i; k >= 1; k--) {
                System.out.print(k);
            }
            System.out.println();
        }
    }

    //输出第四个图形
    private static void graph4(int rows) {
        int a = 0;
        for (int i = 1; i <= rows; i++) {
            a = a * 10 + i;
        }
        for (int i = 1; i <= rows; i++) {

            for (int j = 1; j < i; j++) {
                System.out.print(" ");
            }
            System.out.print(a);
            a = a / 10;
            System.out.println();
        }

    }
}
