package day20190306;

/**
 * 圆类
 * 单一职责原则
 */
public class Circle {
    //成员变量--实例成员
    int x, y; //圆心坐标
    double r;//圆的半径

    //构造方法
    Circle() {

    }

    //带有半径参数的构造方法
    Circle(double rad) {
        this.r = rad;
    }

    //带有圆心坐标和半径的构造方法
    Circle(int a, int b, double rad) {
        this.x = a;
        this.y = b;
        this.r = rad;
    }


    //通方法
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

    /**
     * 银行账户的Account类
     * 它包括成员变量account(账号，String类型)和balance(存款余额，double类型)
     * 成员方法有
     * depsoit(存款)、
     * withdraw(取款)
     * queryBalance(余额擦寻)
     */
    public static class Account {
        //成员变量
        String account; //账号
        double balance; //余额


        /**
         * 特点：
         * (1)构造方法没有返回值，也不能加void
         * (2)如果显示定义任何构造方法，系统默认会提供一个无参数的构造方法
         * (3)构造方法可以重载：方法名相同，方法参数、个数、顺序不同
         */

        public Account() {
            this("62000000000000", 5);
        }

        public Account(String account) {
            this.account = account;
            this.balance = 5;
        }

        public Account(String account, double balance) {
            this.account = account;
            this.balance = balance;
        }

        //成员方法
        void depsoit(double money) {
            balance += money;
        }

        /**
         * 取钱操作
         *
         * @param money 待输入取款的金额
         * @return true或false，如果余额足够，取款成功
         */
        boolean withdraw(double money) {
            if (balance < money) return false;
            balance -= money;
            return true;
        }

        /**
         * 查询余额
         *
         * @return
         */
        public double queryBalance() {
            return balance;
        }

        //方法的调用
        public boolean transferAccount(Account otherAccount, double money) {
            if (balance < money) return false;
            otherAccount.depsoit(money);
            return withdraw(money);
        }
    }
}
