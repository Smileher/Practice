package day20190306;

import junit.framework.Assert;
import junit.framework.TestCase;

public class CircleTest extends TestCase {
    //测试创建类对象
    public void testCreateObject() {
        //创建对象
        Circle circle1 = new Circle();
        //对象成员的访问
        circle1.x = 10;
        circle1.y = 20;
        circle1.r = 10;
        //期望circel1.x的值为10 如果结果是10则通过,否则报错
        Assert.assertEquals(10, circle1.x);
        System.out.println("坐标(" + circle1.x + "," + circle1.y + "),半径=" + circle1.r);
        Circle circle2 = new Circle();
        circle2.x = 10;
        circle2.y = 20;
        circle2.r = 100;
        System.out.println("坐标(" + circle2.x + "," + circle2.y + "),半径=" + circle2.r);
    }

    public void testCircleMethod1() {
        //创建对象
        Circle circle1 = new Circle();//构造函数
        //方法的调用 对象名.方法名（实际参数）
        circle1.setProperty(10, 20, 10);
        circle1.showInfo();

        Circle circle2 = new Circle();//构造函数
        //方法的调用 对象名，方法名（实际参数）
        circle2.setProperty(100, 200, 100);
        circle2.showInfo();
    }

    public void testCircleMethod2() {
        //创建对象
        Circle circle1 = new Circle();//构造函数
        //方法的调用 对象名.方法名（实际参数）
        circle1.setProperty(10, 20, 10);
        circle1.showInfo();

        Circle circle3 = new Circle();//构造函数
        //Java里只能传值
        // 但是如果把一个对象(circle1)传递，相当于把对象的地址传给形参
        //使得形参和实参指向同一个内存空间
        //和C语言中的传地址类似
        circle3.setProperty(circle1);
        circle3.showInfo();

    }
}
