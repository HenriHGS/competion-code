package cn.edu.scau.cmi.heguangsheng.multion;

import java.util.HashSet;
import java.util.Set;

public class Marshal {
    private static Set<Marshal> marshal = new HashSet<Marshal>();

    private static final int Quantity = 10;

    private String name;

    private Marshal(String name){
        this.name = name;
    }

    public static Set<Marshal> getInstance(String name){
        if(marshal.size() < Quantity){
            Marshal marshal0 = new Marshal(name);
            marshal.add(marshal0);
        }
        return marshal;
    }

    public String getName(){
        return this.name;
    }

    public void setName(String name){
        this.name = name;
    }
}
