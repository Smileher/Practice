package day20190311;

import org.junit.Test;

public class AccountTest {
    @Test
    public void testAccount1() {
        //创建一个账号
        Account account1 = new Account();
        double balance = account1.queryBalance();
        System.out.println("余额=" + balance);
        account1.transferAccount(account1, 1000);
        balance = account1.queryBalance();
        System.out.println("余额=" + balance);
    }
}
