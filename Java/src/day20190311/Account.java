package day20190311;

public class Account {
    String account;
    double balance;


    public Account() {
    }

    public Account(String account) {
        this.account = account;
    }

    public Account(String account, double balance) {
        this.account = account;
        this.balance = balance;
    }

    void depsoit(double money) {
        this.balance += money;
    }

    boolean withdraw(double money) {
        if (this.balance < money) {
            return false;
        } else {
            this.balance -= money;
            return true;
        }
    }

    public double queryBalance() {
        return this.balance;
    }

    boolean transferAccount(Account otherAccount, double money) {
        if (this.balance < money) {
            return false;
        } else {
            otherAccount.depsoit(money);
            return this.withdraw(money);
        }
    }
}
