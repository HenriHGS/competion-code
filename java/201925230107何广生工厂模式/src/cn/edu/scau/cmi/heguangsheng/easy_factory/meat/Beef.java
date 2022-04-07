package cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat;

public class Beef implements Meat {
    @Override
    public void getMeatInfo() {
        System.out.println("生产牛肉");
        return;
    }
}
