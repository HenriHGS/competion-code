package cn.edu.scau.cmi.heguangsheng.factory_type.meat;

public class Pork implements Meat {
    @Override
    public void getMeatInfo(){
        System.out.println("生产猪肉");
        return ;
    }
}
