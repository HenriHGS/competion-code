package cn.edu.scau.mi.hesguangsheng.���ģʽ;

public interface Organization {
    String name = null;
    List<Organization> list = new ArrayList<>();
    void show(String level);
    List<Organization> getList();
    void add(Organization organization);
    void remove(Organization organization);
}
