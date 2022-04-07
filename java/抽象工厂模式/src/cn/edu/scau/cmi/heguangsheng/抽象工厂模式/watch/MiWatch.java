package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch;

public class MiWatch implements Watch{
    @Override
    public void operation() {
        System.out.println("你使用的是：小米手表");
    }
}
