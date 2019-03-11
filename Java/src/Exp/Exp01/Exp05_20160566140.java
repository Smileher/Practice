package Exp.Exp01;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-3
 * 本程序的功能是：校友录菜单
 */

import java.util.Scanner;

public class Exp05_20160566140 {
    public static void main(String[] args) {
        Show1();
    }
    //功能：显示校友录管理菜单并控制输入输出
    private static void Show1() {
        while (true) {
            System.out.println("------校友录管理菜单------");
            System.out.println("1.校友登陆 2.管理员登陆 3.退出");
            System.out.println("-----------------------");
            System.out.println("请输入数字（1、2、3）>>>");
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();
            switch (n) {
                case 1:
                    Show2();
                    break;
                case 3:
                    System.out.println("系统退出");
                    System.exit(0);
            }
        }
    }
    //功能：显示校友录功能菜单并控制输入输出
    private static void Show2() {

        while (true) {
            System.out.println("------校友录功能菜单------");
            System.out.println("1.找校友 2.校友相册 3.个人资料管理 4.退出");
            System.out.println("-----------------------");
            System.out.println("请输入数字（1、2、3、4）>>>");
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();
            switch (n) {
                case 4:
                    Show1();
                    break;
            }
        }
    }
}
