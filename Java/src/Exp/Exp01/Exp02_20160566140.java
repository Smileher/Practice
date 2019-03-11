package Exp.Exp01;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-3
 * 本程序的功能是：求s=a+aa+aaa+aaaa+aa...a的值
 */

import java.util.Scanner;

public class Exp02_20160566140 {
    public static void main(String[] args) {
        //声明一个变量
        Scanner input = new Scanner(System.in);
        System.out.println("请输入a的值1-9：");
        int n = input.nextInt();
        System.out.println("请输入次数：");
        int num = input.nextInt();
        //定义每次循环的中间变量用来计算每次的数
        double nums = 0.0;
        //总和
        double sum = 0.0;
        for (int i = 0; i < num; i++) {
            //每次的数加上N为新的n的值
            nums += n;
            //总和
            sum += nums;
            //n的值每次增加一位
            n = n * 10;
            //System.out.println("第" + i + "次的运算的数是:" + nums);
        }
        System.out.println("总和为：" + (int) sum);
    }
}
