package day20190227;

import java.util.Scanner;

public class JavaTrain01 {
    public static void main(String[] args) {
        int courseCount = 0;
        double sumScore = 0;
        Scanner input = new Scanner(System.in);
        while (true) {
            System.out.println("请输入成绩：");
            double score = input.nextDouble();
            if (score > 100 || score < 0) {
                System.out.println("输入错误！");
                continue;
            } else {
                sumScore = sumScore + score;
                courseCount++;
            }
            System.out.println("是否继续输入成绩？（T继续Q退出）");
            String temp = input.next();
            if (temp.equals("T")) {
                continue;
            } else if (temp.equals("Q")) {
                System.out.println("正在退出");
                break;
            } else {
                System.out.println("输入有误");
                continue;
            }
        }
        System.out.println("课程数：" + courseCount + "平均成绩：" + sumScore / courseCount);
    }
}
