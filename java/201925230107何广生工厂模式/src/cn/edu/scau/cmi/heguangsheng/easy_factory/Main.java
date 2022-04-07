package cn.edu.scau.cmi.heguangsheng.简单工厂模式;

import cn.edu.scau.cmi.heguangsheng.简单工厂模式.factory.MeatFactory;
import cn.edu.scau.cmi.heguangsheng.简单工厂模式.meat.Meat;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        String type = null;
        do{
            System.out.println("请输入要生成的肉类：(以END结束)");
            type = cin.next();
            if(type.equals("END")) break;
            Meat meat = MeatFactory.getMeat(type);

            if(meat == null) {
                System.out.println("不在生产线中");
            }else {
                meat.getMeatInfo();
            }
        }while(true);
    }
}
