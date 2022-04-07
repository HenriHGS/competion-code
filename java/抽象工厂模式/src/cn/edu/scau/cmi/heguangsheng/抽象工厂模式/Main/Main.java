package cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Main;

import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.Pad.Pad;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory.AppleFactory;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory.Factory;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory.HuaweiFactory;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.factory.MiFactory;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.phone.Phone;
import cn.edu.scau.cmi.heguangsheng.抽象工厂模式.watch.Watch;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        System.out.println("请输入要使用的 产品 和 厂家：" + '\n' + "eg: Watch Apple (以END结束输入)" );
        String productName, productFactory;
        Scanner cin = new Scanner(System.in);
        while(true){
            productName = cin.next();
            if(productName.equals("END")) break;
            productFactory = cin.next();
            if(productFactory.equals("END")) break;

            Factory factory = null;
            if(productFactory.equals("Apple")){
                factory = new AppleFactory();

            }else if(productFactory.equals("Mi")){
                factory = new MiFactory();
            }else if( productFactory.equals("Huawei") ){
                factory = new HuaweiFactory();
            }
            if(productName.equals("Pad")){
                Pad pad = factory.productPad();
                pad.operation();
            }else if(productName.equals("Phone")){
                Phone phone = factory.productPhone();
                phone.operation();
            }else if(productName.equals("Watch")){
                Watch watch = factory.productWatch();
                watch.operation();
            }
        }
    }
}
/* 测试
Watch Apple
Phone Apple
Pad Apple
Watch Mi
Phone Mi
Pad Mi
Watch Huawei
Phone Huawei
Pad Huawei
END
 */