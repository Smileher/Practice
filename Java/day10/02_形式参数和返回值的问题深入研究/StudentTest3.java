/*
	链式编程。
		每次调用完毕方法后，返回的是一个对象。
*/
class Student {
	public void study() {
		System.out.println("Good Good Study,Day Day Up");
	}
}

class StudentDemo {
	public Student getStudent() {
		return new Student();
	}
}

class StudentTest3 {
	public static void main(String[] args) {
		//如何调用的呢?
		StudentDemo sd = new StudentDemo();
		//Student s = sd.getStudent();
		//s.study();
		
		//大家注意了
		sd.getStudent().study();
	}
}