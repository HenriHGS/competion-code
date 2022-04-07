package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory;


import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.MiPad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.Pad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.MiPhone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.Phone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.MiWatch;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.Watch;

public class MiFactory implements Factory{
    @Override
    public Pad productPad() {
        return new MiPad();
    }

    @Override
    public Phone productPhone() {
        return new MiPhone();
    }

    @Override
    public Watch productWatch() {
        return new MiWatch();
    }
}
