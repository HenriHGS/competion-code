package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory;

import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.ApplePad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.Pad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.ApplePhone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.Phone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.AppleWatch;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.Watch;

public class AppleFactory implements Factory{
    @Override
    public Pad productPad() {
        return new ApplePad();
    }

    @Override
    public Phone productPhone() {
        return new ApplePhone();
    }

    @Override
    public Watch productWatch() {
        return new AppleWatch();
    }
}
