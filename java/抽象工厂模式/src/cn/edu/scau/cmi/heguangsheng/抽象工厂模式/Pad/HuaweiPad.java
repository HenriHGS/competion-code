package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad;

public class HuaweiPad implements Pad{
    @Override
    public void operation() {
        System.out.println("你使用的是:华为平板");
    }
}
