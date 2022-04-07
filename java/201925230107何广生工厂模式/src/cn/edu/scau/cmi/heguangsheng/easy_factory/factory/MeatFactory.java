package cn.edu.scau.cmi.heguangsheng.简单工厂模式.factory;

import cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat.Beef;
import cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat.Cicken;
import cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat.Meat;
import cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat.Pork;

public class MeatFactory {
    public static Meat getMeat(String type){
        Meat meat = null;
        if(type.compareTo("Pork") == 0) {
            meat = new Pork();
        }else if(type.compareTo("Beef") == 0){
            meat = new Beef();
        }else if(type.compareTo("Chicken") == 0){
            meat = new Cicken();
        }
        return meat;
    }
}
