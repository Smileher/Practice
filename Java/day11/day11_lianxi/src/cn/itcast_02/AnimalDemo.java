package cn.itcast_02;

import com.liuyi_02.Animal;
import com.liuyi_02.Cat;
import com.liuyi_02.Dog;

public class AnimalDemo {
	public static void main(String[] args) {
		// 抽象类不能实例化
		// Animal a = new Animal();

		Animal a = new Cat();
		a.eat();
		a.sleep();

		System.out.println("----------");

		a = new Dog();
		a.eat();
		a.sleep();

		System.out.println("----------");

		// 想使用跳高功能
		Dog d = (Dog) a;
		d.eat();
		d.sleep();
		d.jump();
	}
}
