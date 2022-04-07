package cn.edu.scau.cmi.heguangsheng.singleton;

public class Chairman {
    private String name;
    private static Chairman chairman;

    private Chairman(String name){
        this.name = name;
    }

    public static  Chairman getInstance(String name){
        if(chairman == null && !name.equals(null)){
            chairman = new Chairman(name);
        }
        return chairman;
    }

    public String getName(){
        return this.name;
    }
    public void setName(String name){
        this.name = name;
    }
}
