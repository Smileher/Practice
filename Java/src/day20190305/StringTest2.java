package day20190305;

public class StringTest2 {
    public static void main(String[] args) {
        String school = new String("My school is Xuzhou Institute Of Technology");
        System.out.println("字符串长度："+school.length());
        System.out.println("第一个字符："+school.substring(0,1)+"最后一个字符："+school.substring(42,43));

    }

}
