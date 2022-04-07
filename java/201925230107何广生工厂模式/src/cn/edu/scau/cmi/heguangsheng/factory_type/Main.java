package cn.edu.scau.cmi.heguangsheng.factory_type;

import cn.edu.scau.cmi.heguangsheng.factory_type.factory.BeefMeatFactory;
import cn.edu.scau.cmi.heguangsheng.factory_type.factory.ChickenMeatFactory;
import cn.edu.scau.cmi.heguangsheng.factory_type.factory.PorkMeatFactory;
import cn.edu.scau.cmi.heguangsheng.factory_type.meat.Meat;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        String type = null;
        do{
            System.out.println("请输入要生成的肉类：(以END结束)");
            type = cin.next();
            if(type.equals("END")) {
                break;
            }
            Meat meat = null;
            if(type.equals("Pork")) {
                meat = new PorkMeatFactory().getMeat();
            }else if(type.equals("Chicken")){
                meat = new ChickenMeatFactory().getMeat();
            }else if(type.equals("Beef")){
                meat = new BeefMeatFactory().getMeat();
            }

            if(meat == null) {
                System.out.println("不在生产线中");
            }else {
                meat.getMeatInfo();
            }
        }while(true);
    }
}
