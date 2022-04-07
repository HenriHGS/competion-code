package cn.edu.scau.cmi.heguangsheng.factory_type.factory;

import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Cicken;
import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Meat;

public class ChickenMeatFactory implements MeatFactory{
    @Override
    public Meat getMeat() {
        return new Cicken();
    }
}
