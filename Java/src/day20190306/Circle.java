package day20190306;

/**
 * 圆类
 * 单一职责原则
 */
public class Circle {
    //成员变量--实例成员
    int x, y; //圆心坐标
    double r;//圆的半径

    //方法
    //(1)设置圆的相关属性
    //this表示当前对象
    void setProperty(int a, int b, double rad) {
        x = a;
        y = b;
        r = rad;
    }

    //(2)计算周长的功能
    private double getPerimeter() {
        return Math.PI * 2 * r;
    }

    //(3)计算面积的功能
    private double getArea() {
        return Math.PI * r * r;
    }

    //(4)输出圆的信息
    void showInfo() {
        System.out.println("坐标(" + x + "," + y + "),半径=" + r);
        System.out.println("周长：" + String.format("%.2f", getPerimeter()) + ",面积：" + String.format("%.2f", getArea()));
    }

    //把另一个圆类对象的坐标以及半径赋值给当前圆对象
    //方法的参数是一个对象

    //Java里只能传值
    // 但是如果把一个对象(circle1)传递，相当于把对象的地址传给形参
    //使得形参和实参指向同一个内存空间
    //和C语言中的传地址类似
    void setProperty(Circle c) {
        this.x = c.x;
        this.y = c.y;
        this.r = c.r;
    }

}
