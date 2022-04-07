package cn.edu.scau.cmi.heguangsheng.factory_type.factory;

import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Meat;
import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Pork;

public class PorkMeatFactory implements MeatFactory{
    @Override
    public Meat getMeat() {
        return new Pork();
    }
}
