package cn.edu.scau.mi.hesguangsheng.组合模式;

import java.util.List;

public class Person implements Organization {
    public String name;
    public Person(String _name)
    {
        name = _name;
    }

    public void show(String level){
        System.out.println(level + name);
    }

    @Override
    public List<Organization> getList() {
        throw new UnsupportedOperationException();
    }

    @Override
    public void add(Organization organization) {
        throw new UnsupportedOperationException();
    }

    @Override
    public void remove(Organization organization) {
        throw new UnsupportedOperationException();
    }
}

