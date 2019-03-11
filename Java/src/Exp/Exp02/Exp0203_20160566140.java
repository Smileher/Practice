package Exp.Exp02;
/**
 * 班级：16计转本
 * 学号：20160566140
 * 姓名：陈贺
 * 实验时间：2019-3-9
 * 本程序的功能是：生成一定规律的2行4列的数组
 */
public class Exp0203_20160566140 {
    public static void main(String[] args) {
        int i, j;
        int[][] a = {{2, 3, 4}, {4, 6, 8}};
        int[][] b = {{1, 5, 2, 8}, {5, 9, 10, -3}, {2, 7, -5, -18}};
        int[][] c = new int[2][4];

        for (i = 0; i < 2; i++) {
            for (int k = 0; k < 4; k++) {
                c[i][k] = 0;
                for (j = 0; j < 3; j++) {
                    c[i][k] += a[i][j] * b[j][k];

                }
                System.out.print(c[i][k] + "\t");
            }
            System.out.println();
        }
    }
}
