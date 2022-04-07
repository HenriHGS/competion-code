package cn.edu.scau.cmi.heguangsheng.client;

import cn.edu.scau.cmi.heguangsheng.multion.Marshal;
import cn.edu.scau.cmi.heguangsheng.singleton.Chairman;
import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;

public class SingletonClient extends Application{

   private static void testSingleton(){
       System.out.println("输入你要创建的两个主席的名字");

       Scanner cin = new Scanner(System.in);

       String name1 = cin.nextLine();
       /* "毛泽东" */
       Chairman maozedong = Chairman.getInstance(name1);
       System.out.println("你实际输入的主席是：" + name1);
       System.out.println("你创建的主席是：" + maozedong.getName());
       System.out.println(maozedong);

       String name2 = cin.nextLine();
       Chairman liushaoqi = Chairman.getInstance(name2);
       /* "刘少奇" */
       System.out.println("你实际输入的主席是：" + name2);
       System.out.println("你创建的主席是：" + liushaoqi.getName());
       System.out.println(liushaoqi);

       if(maozedong == liushaoqi){
           System.out.println("一样");
       }else {
           System.out.println("不一样");
       }
   }
   private static void testMultiton(){
       Set<Marshal> marshals = new HashSet<Marshal>();

       Scanner cin = new Scanner(System.in);
       System.out.println("请输入10个大元帅：");
       String name;
       /* 朱德 彭德怀 刘伯承 陈毅  林彪 徐向前 聂荣臻 叶剑英 贺龙  罗荣桓 */
       for(int i = 1; i <= 10; i ++ ){
           name = cin.nextLine();
           marshals = Marshal.getInstance(name);
           System.out.println("你实际输入的元帅是：" + name);
           printAllMarshals(marshals);
       }
       System.out.println("在输入两个元帅，测试");
       for(int i = 1; i <= 2; i ++ ){
           name = cin.nextLine();
           marshals = Marshal.getInstance(name);
           System.out.println("你实际输入的元帅是：" + name);
           printAllMarshals(marshals);
       }
   }
   private static void printAllMarshals(Set<Marshal> marshals){
       System.out.print("当前的元帅：[");
       boolean first = true;
       for(Marshal marshal: marshals){
           if(!first) System.out.print(";");
           else first = false;
           System.out.print(marshal.getName());
       }
       System.out.println("]");
   }
    public static void main(String[] args) {
        testSingleton();
        testMultiton();
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        Button button = new Button("");
        primaryStage.show();
    }
}

