/*
	Math:类包含用于执行基本数学运算的方法
	
	由于Math类在java.lang包下，所以不需要导包。
	特点：
		没有构造方法，因为它的成员全部是静态的。
		
	掌握一个方法：
		获取随机数
		public static double random():返回带正号的 double 值，该值大于等于 0.0 且小于 1.0。
*/
class MathDemo {
	public static void main(String[] args) {
		//获取一个随机数
		//double d = Math.random();
		//System.out.println(d);
		
		//需求：我要获取一个1-100之间的随机数，肿么办?
		for(int x=0; x<100; x++) {
			int number = (int)(Math.random()*100)+1;
			System.out.println(number);
		}
	}
}