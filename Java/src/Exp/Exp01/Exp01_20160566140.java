package Exp.Exp01;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-3
 * 本程序的功能是：根据利润提成计算企业发放的奖金
 */

import java.util.Scanner;

public class Exp01_20160566140 {
    public static void main(String[] args) {
        System.out.println("请输入当月的利润：");
        Scanner input = new Scanner(System.in);
        Double bonus = input.nextDouble();
        //利润低于或等于10万
        if (bonus <= 100000) {
            bonus = bonus * 0.1;
        }
        //利润高于10万元，低于20万元
        else if (bonus > 100000 && bonus <= 200000) {
            bonus = (bonus - 100000) * 0.075 + 100000 * 0.1;
        }
        //利润高于20万元，低于40万元
        else if (bonus > 200000 && bonus <= 400000) {
            bonus = (bonus - 200000) * 0.05 + 100000 * 0.075 + 100000 * 0.1;
        }
        //利润高于40万元，低于60万元
        else if (bonus > 400000 && bonus <= 600000) {
            bonus = (bonus - 400000) * 0.03 + 200000 * 0.05 + 100000 * 0.075 + 100000 * 0.1;
        }
        //利润高于60万元，低于100万元
        else if (bonus > 600000 && bonus <= 1000000) {
            bonus = (bonus - 600000) * 0.015 + 200000 * 0.03 + 200000 * 0.05 + 100000 * 0.075 + 100000 * 0.1;
        }
        //利润高于100万元
        else if (bonus > 1000000) {
            bonus = (bonus - 1000000) * 0.01 + 400000 * 0.015 + 200000 * 0.03 + 200000 * 0.05 + 100000 * 0.075 + 100000 * 0.1;
        }
        //其它情况
        else {
            System.out.println("输入错误!");
        }
        //输出
        System.out.println("应发放奖金总数为" + String.format("%.2f", bonus) + "元");

    }
}
