package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：编写一个截取字符串的函数，输入为一个字符串和字节数，输出为按字节截取的字符串，
 *               但要保证汉字不被截取半个，如“我ABC”，4，应该截取“我AB”，
 *               输入“我ABC汉DEF”，6，应该输出“我ABC”，而不是“我ABC+汉的半个”。
 */
public class Exp0206_20160566140 {
    public static void main(String[] args) {
        String srcStr1 = "我ABC";
        String srcStr2 = "我ABC汉DEF";

        splitString(srcStr1, 4);
        splitString(srcStr2, 6);
    }

    public static void splitString(String src, int len) {
        int byteNum = 0;

        if (null == src) {
            System.out.println("The source String is null!");
            return;
        }

        byteNum = src.length();
        byte bt[] = src.getBytes(); // 将String转换成byte字节数组

        if (len > byteNum) {
            len = byteNum;
        }

        // 判断是否出现了截半，截半的话字节对于的ASC码是小于0的值
        if (bt[len] < 0) {
            String subStrx = new String(bt, 0, --len);
            System.out.println("subStrx==" + subStrx);
        } else {
            String subStrx = new String(bt, 0, len);
            System.out.println("subStrx==" + subStrx);
        }
    }

}
