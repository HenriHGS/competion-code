package cn.edu.scau.mi.hesguangsheng.组合模式;
import java.util.*;
import java.util.ArrayList;
import java.util.List;

public class Team implements Organization {
    public String name;
    private List<Organization> list = new ArrayList<>();
    public Team(String _name)
    {
        name = _name;
    }

    public List<Organization> getList() {
        return list;
    }

    public void add(Organization organization){
        list.add((organization));
    }

    public void remove(Organization organization){
        list.remove(organization);
    }

    public void show(String level) {
        System.out.println(level + name);
        for (Organization x : list){
            x.show(level + "-");
        }
    }
}

