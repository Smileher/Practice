package com.liuyi_02;

import com.liuyi_01.Jump;

/**
 * 这是具体的狗类
 * 
 * @author 风清扬
 * @version V1.0
 */
public class Dog extends Animal implements Jump {

	@Override
	public void jump() {
		System.out.println("会跳高的狗");
	}

	@Override
	public void eat() {
		System.out.println("狗吃肉");
	}

	@Override
	public void sleep() {
		System.out.println("狗站着睡觉");
	}

}
