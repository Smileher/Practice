package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：练习String创建和String常用方法的使用
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Exp0204_20160566140 {
    public static void main(String[] args) throws IOException {

        String school;
        BufferedReader str;
        str = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("请输入：My school is Xuzhou Institute Of Technology");
        school = str.readLine();

        System.out.println("字符串的长度为：" + school.length());

        System.out.println("字符串一个字符是：" + school.charAt(0) + "字符串的最后一个字符是：" + school.charAt(school.length() - 1));

        System.out.println("字符串的第一个单词为：" + school.substring(0, 2) + "\n字符串的最后一个单词为：" + school.substring(33, school.length()));

        System.out.println("”Xuzhou”在该字符串的起始位置为：" + school.indexOf("Xuzhou", 0));

        System.out.println("字符串转为大写字母为：" + school.toUpperCase());
    }


}
