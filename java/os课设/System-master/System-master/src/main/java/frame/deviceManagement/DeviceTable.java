package frame.deviceManagement;

/**
 * @ClassName DeviceTable
 * @Description 设备分配表
 * @Author wlf
 * @Date 2020/10/20 18:28
 * @Version 1.0
 **/
public class DeviceTable {
    private String A1;
    private String B1;
    private String B2;
    private String C1;
    private String C2;

    public DeviceTable() {
        A1 = "设备空闲";
        B1 = "设备空闲";
        B2 = "设备空闲";
        C1 = "设备空闲";
        C2 = "设备空闲";
    }

    public String getA1() {
        return A1;
    }

    public void setA1(String a1) {
        A1 = a1;
    }

    public String getB1() {
        return B1;
    }

    public void setB1(String b1) {
        B1 = b1;
    }

    public String getB2() {
        return B2;
    }

    public void setB2(String b2) {
        B2 = b2;
    }

    public String getC1() {
        return C1;
    }

    public void setC1(String c1) {
        C1 = c1;
    }

    public String getC2() {
        return C2;
    }

    public void setC2(String c2) {
        C2 = c2;
    }

    @Override
    public String toString() {
        return "DeviceTable:\n" +
                "A='" + A1 + '\'' +
                "\nB='" + B1 + '\'' +
                "\nB='" + B2 + '\'' +
                "\nC='" + C1 + '\'' +
                "\nC='" + C2 + '\'' +
    }
}
