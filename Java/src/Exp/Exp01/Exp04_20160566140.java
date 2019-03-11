package Exp.Exp01;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-3
 * 本程序的功能是：在控制台输出菱形
 */

import java.util.Scanner;

public class Exp04_20160566140 {
    public static void main(String[] args) {
        System.out.println("请输入行数");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();

        while (a % 2 == 0) {
            System.out.println("请重新输入");
            a = sc.nextInt();
        }
        Show(a);
    }

    private static void Show(int a) {

        for (int i = 0; i <= (a + 1) / 2; i++) {
            for (int j = 0; j < (a + 1) / 2 - i; j++) {
                System.out.print(" ");
            }
            for (int k = 0; k < i * 2 - 1; k++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = (a + 1) / 2; i < a; i++) {
            for (int j = 0; j <= i - (a + 1) / 2; j++) {
                System.out.print(" ");
            }
            for (int k = 0; k < (a - i) * 2 - 1; k++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

}
