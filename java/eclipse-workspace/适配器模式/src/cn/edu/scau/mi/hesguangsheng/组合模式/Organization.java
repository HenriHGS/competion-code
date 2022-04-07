package cn.edu.scau.mi.hesguangsheng.组合模式;

public interface Organization {
    String name = null;
    List<Organization> list = new ArrayList<>();
    void show(String level);
    List<Organization> getList();
    void add(Organization organization);
    void remove(Organization organization);
}
