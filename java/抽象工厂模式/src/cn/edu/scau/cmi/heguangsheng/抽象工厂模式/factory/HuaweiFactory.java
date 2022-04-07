package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory;


import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.HuaweiPad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.Pad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.HuaweiPhone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.Phone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.HuaweiWatch;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.Watch;

public class HuaweiFactory implements Factory{
    @Override
    public Pad productPad() {
        return new HuaweiPad();
    }

    @Override
    public Phone productPhone() {
        return new HuaweiPhone();
    }

    @Override
    public Watch productWatch() {
        return new HuaweiWatch();
    }
}
