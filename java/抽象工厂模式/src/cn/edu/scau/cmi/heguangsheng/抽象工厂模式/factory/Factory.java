package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory;

import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.Pad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.Phone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.Watch;

public interface Factory {
    Pad productPad();
    Phone productPhone();
    Watch productWatch();
}
