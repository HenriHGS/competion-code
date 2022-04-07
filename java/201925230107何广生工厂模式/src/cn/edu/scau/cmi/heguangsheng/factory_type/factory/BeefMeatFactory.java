package cn.edu.scau.cmi.heguangsheng.factory_type.factory;

import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Beef;
import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Meat;

public class BeefMeatFactory implements MeatFactory{
    @Override
    public Meat getMeat() {
        return new Beef();
    }
}
