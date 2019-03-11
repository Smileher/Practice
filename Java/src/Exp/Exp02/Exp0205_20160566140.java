package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：StringBuffer创建和StringBuffer常用方法的使用
 */
public class Exp0205_20160566140 {
    public static void main(String[] args) {
        String str = "Java和 JavaScript 虽有都有Java四个字，但它们是完完全全不同的两种东西，Java是由Sun 公司于1995年5月推出的，而JavaScript 是于1995年由Netscape公司设计实现而成的，由于Netscape公司与Sun公司合作，Netscape高层希望它看上去能够像Java，因此取名为JavaScript";
        String receive = "Java";
        StringBuffer stradd;
        stradd = new StringBuffer("Java和 JavaScript 虽有都有Java四个字，但它们是完完全全不同的两种东西，Java是由Sun 公司于1995年5月推出的，而JavaScript 是于1995年由Netscape公司设计实现而成的，由于Netscape公司与Sun公司合作，Netscape高层希望它看上去能够像Java，因此取名为JavaScript");
        int count = getCount(str, receive);
        System.out.printf("文中出现%s的次数为%d\n", receive, count);
        stradd = stradd.append(",Sun公司已被Oracle公司收购。");
        System.out.println(stradd);
    }

    public static int getCount(String maxString, String minString) {
        int count = 0;
        // 在大串中查找小串一次
        int index = maxString.indexOf(minString);
        // 计算出小串的长度
        int minStringLength = minString.length();
        // 如果返回值不是-1，说明小串在大串中是存在的。
        while (index != -1) {
            //计数
            count++;
            // 把查找过的数据给截取掉,重新赋值给大串
            maxString = maxString.substring(index + minStringLength);
            // 在新的大串中查找一次小串
            index = maxString.indexOf(minString);
        }
        return count;
    }

}
