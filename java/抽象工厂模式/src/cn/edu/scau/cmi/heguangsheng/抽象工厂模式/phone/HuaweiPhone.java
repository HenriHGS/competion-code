package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone;

public class HuaweiPhone implements Phone{
    @Override
    public void operation() {
        System.out.println("你使用的是:华为手机");
    }
}
