package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone;

public class ApplePhone implements Phone{
    @Override
    public void operation() {
        System.out.println("你使用的是:苹果手机");
    }
}
