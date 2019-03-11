package day20190305;

import java.util.Scanner;

//题目要求：输入10个数，重复不计，依次输出
public class Exercise01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int array[] = new int[10];
        System.out.println("请输入：");
        for (int i = 0; i < 10; i++) {
            int inputNumber = input.nextInt();
            if (Repeat(inputNumber, array, i)) {
                array[i] = inputNumber;
                continue;
            } else {
                System.out.println("输入的数字重复,请再次输入：");
                i--;
            }
        }
        System.out.print("输入的数组为：");
        for (int j = 0; j < 10; j++) {
            System.out.print(array[j] + " ");
        }
    }

    private static boolean Repeat(int inputNumber, int[] array, int arrayLength) {
        for (int i = 0; i < arrayLength; i++)
            if (array[i] == inputNumber) return false;
        return true;

    }
}
