package cn.edu.scau.cmi.heguangsheng.factory_type.meat;

public class Beef implements Meat {
    @Override
    public void getMeatInfo() {
        System.out.println("生产牛肉");
        return;
    }
}
