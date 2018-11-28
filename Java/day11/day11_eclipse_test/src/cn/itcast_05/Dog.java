package cn.itcast_05;

/*
 * 是注解。
 * 这个注解的意思是说，我这个方法是重写父类的。
 * 如果和父类名出现了偏差就会报错。
 */
public class Dog extends Animal {

	@Override
	public void eat() {

	}

	public void sleep() {

	}

}
