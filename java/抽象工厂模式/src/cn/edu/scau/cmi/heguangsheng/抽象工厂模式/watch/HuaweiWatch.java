package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch;

public class HuaweiWatch implements Watch{
    @Override
    public void operation() {
        System.out.println("你使用的是：华为手表");
    }
}
