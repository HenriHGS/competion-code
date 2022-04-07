package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone;

public class MiPhone implements Phone{
    @Override
    public void operation() {
        System.out.println("你使用的是:小米手机");
    }
}
