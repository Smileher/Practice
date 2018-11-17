/*
	匿名对象：就是没有名字的对象。
	
	匿名对象的应用场景：
		A:调用方法，仅仅只调用一次的时候。
			注意：调用多次的时候，不适合。
			那么，这种匿名调用有什么好处吗?
				有，匿名对象调用完毕就是垃圾。可以被垃圾回收器回收。
		B:匿名对象可以作为实际参数传递
*/
class Student {
	public void show() {
		System.out.println("我爱学习");
	}
}

class StudentDemo {
	public void method(Student s) {
		s.show();
	}
}

class NoNameDemo {
	public static void main(String[] args) {
		//带名字的调用
		Student s = new Student();
		s.show();
		s.show();
		System.out.println("--------------");
		
		//匿名对象
		//new Student();
		//匿名对象调用方法
		new Student().show();
		new Student().show(); //这里其实是重新创建了一个新的对象
		System.out.println("--------------");
		
		
		//匿名对象作为实际参数传递
		StudentDemo sd = new StudentDemo();
		//Student ss = new Student();
		//sd.method(ss); //这里的s是一个实际参数
		//匿名对象
		sd.method(new Student());
		
		//在来一个
		new StudentDemo().method(new Student());
 	}
}