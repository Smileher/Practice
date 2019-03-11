package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：金额转换，阿拉伯数字的金额转换成中国传统的形式如：（￥1011）－>（一千零一拾一元整）输出
 */
import java.util.Scanner;

public class Exp0207_20160566140 {
    public static void main(String[] args) {

        String capNumber[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};     //capNumber[]存储大写数字汉字
        String unit[] = {"", "圆", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟"}; //unit[]存储每一个位数所对应的大写汉字单位  unit[0]="",方便对应。
        Scanner sc = new Scanner(System.in);                  //键盘录入数据
        System.out.println("请输入12位以内任意整数：");
        long num;
        //判断输入数据合理性
        while (true) {
            num = sc.nextLong();
            String line = num + "";
            if (line.length() > 12) {
                System.out.println("您输入的数据位数过大！请重输：");
            } else {
                break;
            }
        }
        int times = 0;                                      //记录除的次数
        long shang = 0;                                     //记录每一次的商
        long yushu = 0;                                     //记录每一次的余数
        String str = "";
        while (true) {
            shang = num / 10;                              //得到商
            yushu = num % 10;                              //得到余数
            if (shang == 0 && yushu == 0) {                  //当商和余数同时为0时退出循环
                break;
            } else {                                         //否则,将商重新赋值给num,继续循环
                num = shang;
            }
            times++;                                       //次数加1,得到每位数据
            str = capNumber[(int) yushu] + unit[times] + str;   //将大写数字汉字和大写单位连接赋值给str
        }                                                       //去除字符串中的0
        str = str.replaceAll("零[拾佰仟]", "零").replaceAll("零+亿", "亿").replaceAll("零{4}万", "")
                .replaceAll("零+万", "万").replaceAll("零+圆", "圆").replaceAll("零+", "零") + "整";
        System.out.println("阿拉伯数字转换成中国传统形式为: ");
        System.out.println(str);                            //输出字符串
    }
}
