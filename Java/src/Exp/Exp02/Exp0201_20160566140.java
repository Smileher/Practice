package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：对二维数组的数值计算并输出
 */
import java.util.Random;

public class Exp0201_20160566140 {
    public static void main(String[] args) {
        int[][] intArray = new int[10][10];
        double doubleSum, doubleAvg, doubleMin, doubleMax;
        Random ra = new Random();
        //生成随机二维数组
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                //ra.nextInt(79)表示随机数在[0，79)之间 +21表示[21,99)
                intArray[i][j] = ra.nextInt(79) + 21;
            }
        }
        //1横向输出
        //输出标题sum avg min max
        System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t" + "  sum   avg   min   max");
        for (int i = 0; i < 6; i++) {
            //初始化doubleSum doubleAvg doubleMax doubleMin
            doubleSum = doubleAvg = doubleMax = 0;
            doubleMin = 100;
            System.out.print("          ");
            //运算doubleSum doubleAvg doubleMax doubleMin
            for (int j = 0; j < 6; j++) {
                System.out.print(String.format("%d    ", intArray[i][j]));
                doubleSum = doubleSum + intArray[i][j];
                doubleAvg = doubleSum / 6;
                if (intArray[i][j] < doubleMin) doubleMin = intArray[i][j];
                if (intArray[i][j] > doubleMax) doubleMax = intArray[i][j];
            }
            //输出doubleSum doubleAvg doubleMax doubleMin
            System.out.print("|" + String.format("%6.0f%6.1f%6.0f%6.0f", doubleSum, doubleAvg, doubleMin, doubleMax));
            System.out.println();
        }
        System.out.println("\t   —— —— —— —— —— —— —— —— —— —— —— —— ——");

        //2纵向输出
        double[] tempSum = new double[6];
        double[] tempAvg = new double[6];
        double[] tempMin = new double[6];
        double[] tempMax = new double[6];
        //sum
        for (int i = 0; i < 6; i++) {
            //初始化doubleSum
            doubleSum = doubleAvg = doubleMax = 0;
            doubleMin = 100;
            for (int j = 0; j < 6; j++) {
                doubleSum = doubleSum + intArray[j][i];
                if (intArray[j][i] < doubleMin) doubleMin = intArray[j][i];
                if (intArray[j][i] > doubleMax) doubleMax = intArray[j][i];
            }
            tempSum[i] = doubleSum;
            tempAvg[i] = doubleSum / 6;
            tempMin[i] = doubleMin;
            tempMax[i] = doubleMax;
        }
        //sum
        System.out.print("   sum    ");
        for (int i = 0; i < 6; i++) {
            System.out.print(String.format("%.0f   ", tempSum[i]));
        }
        System.out.println();
        //avg
        System.out.print("   avg    ");
        for (int i = 0; i < 6; i++) {
            System.out.print(String.format("%.1f  ", tempAvg[i]));
        }
        System.out.println();
        //min
        System.out.print("   min    ");
        for (int i = 0; i < 6; i++) {
            System.out.print(String.format("%.0f    ", tempMin[i]));
        }
        System.out.println();
        //max
        System.out.print("   max    ");
        for (int i = 0; i < 6; i++) {
            System.out.print(String.format("%.0f    ", tempMax[i]));
        }
    }
}
