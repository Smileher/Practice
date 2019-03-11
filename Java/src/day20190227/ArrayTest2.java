package day20190227;

public class ArrayTest2 {
    public static void main(String[] args) {
        char[][] chars = new char[4][4];
        for (int row = 0; row < chars.length; row++) {
            for (int col = 0; col < chars[row].length; col++) {
                char c = (char) (65 + 26 * Math.random() + 32 * Math.random());
                chars[row][col]=c;
                System.out.print(chars[row][col]+" ");
            }
            System.out.println();
        }
    }
}
