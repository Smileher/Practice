/*
	我们曾经曰：起名字要做到见名知意。
	
	this:是当前类的对象引用。简单的记，它就代表当前类的一个对象。
	
		注意：谁调用这个方法，在该方法内部的this就代表谁。
		
	this的场景：
		解决局部变量隐藏成员变量
*/
//定义学生类
class Student {
	//姓名
	private String name;
	//年龄
	private int age;
	
	//姓名获取值
	public String getName() {
		return name;
	}
	
	//姓名设置值
	public void setName(String name) { //name = "林青霞";
		//name = name; //变量的使用规则：就近原则
		//这里是类名，目前还没有说过类似的用法，所以这个是有问题的
		//这里的调用只能通过对象名
		//这个对象如果存在，它应该代表的是Student的一个对象。
		//那么，谁能够代表当前类的对象呢? java就提供了一个关键字 this
		//Student.name = name;
		this.name = name;
	}
	
	//年龄获取值
	public int getAge() {
		return age;
	}
	
	//年龄赋值
	public void setAge(int age) {
		this.age = age;
	}
}

//测试类
class StudentTest {
	public static void main(String[] args) {
		//创建学生对象
		Student s = new Student();
		
		//给成员变量赋值
		s.setName("林青霞");
		s.setAge(27);
		//获取数据
		System.out.println(s.getName()+"---"+s.getAge());
	}
}