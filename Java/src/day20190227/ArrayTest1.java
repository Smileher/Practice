package day20190227;

public class ArrayTest1 {
    public static void main(String[] args) {
        //声明一个用于存放班级成绩的整形数组oopScore
        //声明数组时不能指定长度
        int[] oopScore;
        //创建一个能够存储50个同学成绩的数组
        //new关键字 为对象分配存储空间(内存：栈内存、堆内存)
        oopScore = new int[50];
        //创建本学期所学课程的字符串数组courses,利用静态初始化该数组
        String[] courses = {"面向对象程序设计", "Java移动web开发", "xxxx", "yyyy"};
        //为oopScore数组的每个元素分配一个100以内的随机整数
        for (int i = 0; i < oopScore.length; i++) {
            oopScore[i] = (int) (Math.random() * 100);
            System.out.print(oopScore[i] + " ");
            if((i+1)%10==0) System.out.println();
        }
        //处理与分析
    }
}
