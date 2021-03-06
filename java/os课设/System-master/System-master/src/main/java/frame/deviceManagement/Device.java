package frame.deviceManagement;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * @ClassName Device
 * @Description 设备
 * @Author wlf
 * @Date 2020/10/19 0:05
 * @Version 1.0
 **/
public class Device {
      /* A、B、C三种独占型设备，A设备1个，B设备2个，C设备2个。 */
      private int returnIndexA1 = 1;
      private int returnIndexB1 = 2;
      private int returnIndexB2 = 3;
      private int returnIndexC1 = 4;
      private int returnIndexC2 = 5;
      private int c;
      /* 同一设备的实体被认为是相同的 */
      private LinkedList<DeviceWaitQueue> blockA ;
      private LinkedList<DeviceWaitQueue> blockB ;
      private LinkedList<DeviceWaitQueue> blockC ;
      private DeviceTable deviceTable;
      DeviceWaitQueue deviceWaitQueueA;
      DeviceWaitQueue deviceWaitQueueB;
      DeviceWaitQueue deviceWaitQueueC;
    public Device() {
        this.blockA = new LinkedList<DeviceWaitQueue>();
        this.blockB = new LinkedList<DeviceWaitQueue>();
        this.blockC = new LinkedList<DeviceWaitQueue>();
        this.deviceTable = new DeviceTable();
    }
    /**
     * @Description 申请A设备
     * @param Uid
     * @param time
     * @param size
     */
    public int getDeviceA(String Uid, int time, int size ){
         deviceWaitQueueA =new DeviceWaitQueue(Uid,size,time);
        if (deviceTable.getA1().equals("设备空闲") ){
            deviceTable.setA1(Uid);
            c = returnIndexA1;
            returnIndexA1 = 9;
            return c;
        }
        else {
            blockA.add(deviceWaitQueueA);
            return 9;
        }

    }
    /**
     * @Description 释放A设备
     * @param Uid
     */
    public int[] removeDeviceA(String Uid){
        int[] re =new int[2];
        if (Uid.equals(deviceTable.getA1())){
            deviceTable.setA1("设备空闲");
            if(!blockA.isEmpty()) {
                re[0] = 1;
                re[1] = gerFirstNodeA();
                return re;
            }
            returnIndexA1 = 1;
            return null;
        }else
            return null;
    }

    /**
     * @Description 获取等待队列第一个节点
     */
    public int gerFirstNodeA(){
        deviceWaitQueueA = blockA.removeFirst();
        getDeviceA(deviceWaitQueueA.getUid(),deviceWaitQueueA.getTime(),deviceWaitQueueA.getSize());
        return deviceWaitQueueA.getTime();
    }
    /**
     * @Description 申请B设备
     * @param Uid
     * @param time
     * @param size
     */
    public int getDeviceB(String Uid, int time, int size ){
        deviceWaitQueueB =new DeviceWaitQueue(Uid,size,time);
        if (deviceTable.getB1().equals("设备空闲") ){
            deviceTable.setB1(Uid);
            c = returnIndexB1;
            returnIndexB1 = 9;
            return c;
        }
        else if(deviceTable.getB2().equals("设备空闲") ) {
            deviceTable.setB2(Uid);
            c = returnIndexB2;
            returnIndexB2 = 9;
            return c;
        }
        else{
            blockB.add(deviceWaitQueueB);
            return 9;
        }
    }
    /**
     * @Description 释放B设备
     * @param Uid
     */
    public int[] removeDeviceB(String Uid){
        int[] re =new int[2];
        if (Uid.equals(deviceTable.getB1())){
            deviceTable.setB1("设备空闲");
            if(!blockB.isEmpty()) {
                re[0] = 3;
                re[1] = gerFirstNodeB();;
                return re;
            }
            returnIndexB1 = 3;
            return null;
        }else if (Uid.equals(deviceTable.getB2())){
            deviceTable.setB2("设备空闲");
            if(!blockB.isEmpty()) {
                re[0] = 4;
                re[1] = gerFirstNodeB();;
                return re;
            }
            returnIndexB2 = 4;
            return null;
        }
        else
            return null;
    }
    /**
     * @Description 获取B设备等待队列第一个节点
     */
    public int gerFirstNodeB(){
        deviceWaitQueueB = blockB.removeFirst();
        getDeviceB(deviceWaitQueueB.getUid(),deviceWaitQueueB.getTime(),deviceWaitQueueB.getSize());
        return deviceWaitQueueB.getTime();
    }
    /**
     * @Description 申请C设备 两个c设备
     * @param Uid
     * @param time
     * @param size
     */
    public int getDeviceC(String Uid, int time, int size ){
        deviceWaitQueueC = new DeviceWaitQueue(Uid,size,time);
        if ( deviceTable.getC1().equals("设备空闲") ){
            deviceTable.setC1(Uid);
            c = returnIndexC1;
            returnIndexC1 = 9;
            return c;
        }
        else if( deviceTable.getC2().equals("设备空闲") ){
            deviceTable.setC2(Uid);
            c = returnIndexC2;
            returnIndexC2 = 9;
            return c;
        }
        else{
            blockC.add(deviceWaitQueueC);
            return 9;
        }
    }
    /**
     * @Description 释放C设备
     * @param Uid
     */
    public int[] removeDeviceC(String Uid){
        int[] re = new int[2];
        if (Uid.equals(deviceTable.getC1())){
            deviceTable.setC1("设备空闲");
            if(!blockC.isEmpty()) {
                re[0] = 6;
                re[1] = gerFirstNodeC();;
                return re;
            }
            returnIndexC1 = 6;
            return null;
        }else if (Uid.equals(deviceTable.getC2())){
            deviceTable.setC2("设备空闲");
            if(!blockC.isEmpty()) {
                re[0] = 7;
                re[1] = gerFirstNodeC();;
                return re;
            }
            returnIndexC2 = 7;
            return null;
        }
        else
            return  null;
    }
    /**
     * @Description 获取B设备等待队列第一个节点
     */
    public int gerFirstNodeC(){
        deviceWaitQueueC = blockB.removeFirst();
        getDeviceC(deviceWaitQueueC.getUid(),deviceWaitQueueC.getTime(),deviceWaitQueueC.getSize());
        return deviceWaitQueueC.getTime();
    }

    public DeviceTable getDeviceTable() {
        return deviceTable;
    }

    public void setDeviceTable(DeviceTable deviceTable) {
        this.deviceTable = deviceTable;
    }

    public LinkedList<DeviceWaitQueue> getBlockA() {
        return blockA;
    }

    public void setBlockA(LinkedList<DeviceWaitQueue> blockA) {
        this.blockA = blockA;
    }

    public LinkedList<DeviceWaitQueue> getBlockB() {
        return blockB;
    }

    public void setBlockB(LinkedList<DeviceWaitQueue> blockB) {
        this.blockB = blockB;
    }

    public LinkedList<DeviceWaitQueue> getBlockC() {
        return blockC;
    }

    public void setBlockC(LinkedList<DeviceWaitQueue> blockC) {
        this.blockC = blockC;
    }

    public DeviceWaitQueue getDeviceWaitQueueA() {
        return deviceWaitQueueA;
    }

    public void setDeviceWaitQueueA(DeviceWaitQueue deviceWaitQueueA) {
        this.deviceWaitQueueA = deviceWaitQueueA;
    }

    public DeviceWaitQueue getDeviceWaitQueueB() {
        return deviceWaitQueueB;
    }

    public void setDeviceWaitQueueB(DeviceWaitQueue deviceWaitQueueB) {
        this.deviceWaitQueueB = deviceWaitQueueB;
    }

    public DeviceWaitQueue getDeviceWaitQueueC() {
        return deviceWaitQueueC;
    }

    public void setDeviceWaitQueueC(DeviceWaitQueue deviceWaitQueueC) {
        this.deviceWaitQueueC = deviceWaitQueueC;
    }
}
