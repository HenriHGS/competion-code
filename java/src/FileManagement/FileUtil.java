package FileManagement;
import frame.processManagement.Util;

import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class FileUtil {
    private byte[][] diskBuffer;
    private final int ROOT_DIR = 4;
    private final byte EXE_PROERTY = 5;
    private final byte TXT_PROERTY = 1;
    private FAT fileAllocationTable;
    private Disk disk;
    private byte[] emptyBlock;
    private byte[] emptyItem;
    public FileUtil() throws Exception {
        disk = new Disk();
        diskBuffer = disk.getDisk();
        fileAllocationTable = new FAT(disk);
        emptyBlock = new byte[64];
        emptyItem = new byte[8];
    }

    public int getBlock(byte[] name, byte property, int blockIndex){
        int block = -1;
        byte[] dirName;
        for(int j = 0; j < 8; j ++ ){
            //乘8 其实可以看成二进制下左移三位。
            int i = j * 8;
            dirName = Arrays.copyOfRange(diskBuffer[blockIndex], i, i + 3);
            if(Arrays.equals(name, dirName) && diskBuffer[blockIndex][i+4] == property){
                block = Disk.byteToUnsigned(diskBuffer[blockIndex][i+5]);
                break;
            }
        }
        return block;
    }
    public int findDirectory(byte[][] path){
        int blockIndex = ROOT_DIR;
        int nextBlockIndex = blockIndex;
        for(int i = 0; i < path.length && blockIndex != -1; i ++ ){
            do {
                blockIndex = getBlock(path[i], DIR_PROPERTY, nextBlockIndex);
                nextBlockIndex = fileAllocationTable.getNextBlock(nextBlockIndex);
            }
            while(blockIndex == -1 && nextBlockIndex != -1);
            nextBlockIndex = blockIndex;
        }
        return nextBlockIndex;
    }

    public int findFile(byte[] name, byte property, int dirBlock){
        int blockIndex;
        if(dirBlock == -1){
            blockIndex = -1;
            return blockIndex;
        }
        int itemIndex = getItem(name, property, dirBlock);
        if(itemIndex == -1){
            blockIndex = -1;
            return blockIndex;
        }
        /* 这里*8 + 5 相当于左移三位，然后低位补上1 */
        blockIndex = Disk.byteToUnsigned(diskBuffer[dirBlock][itemIndex*8 + 5]);
        return blockIndex;
    }


    public int getFile(String path){
        byte property = TXT_PROERTY;
        if(path.contians(".e")){
            property = EXE_PROERTY;// the val is 5
        }
        byte[][] bytePath = disk.formatPath(path);
        byte[][] fatherPath = Arrays.copyOf(bytePath, bytePath.length - 1);
        int parentDIrBlock = this.findDirectory(fatherPath);
        if(parentDIrBlock > 4){
            parentDIrBlock = this.getContained(bytePath[bytePath.length - 1], property, parentDIrBlock);
        }
        int dirBlock = findFile(bytePath[bytePath.length - 1], property, parentDIrBlock);
        return dirBlock;
    }

    public int getContained(byte[] name, byte property, int blockIndex){
        boolean isContained;
        int index = blockIndex;
        int itemIndex;
        int currentIndex;
        do{
            itemIndex = getBlock(name, property, index);
            currentIndex = index;
            index = fileAllocationTable.getNextBlock(index);
        }while(index > 1 && itemIndex == -1);
        isContained = (itemIndex != -1);
        if(!isContained) currentIndex = -1;
        return currentIndex;
    }

    public boolean isBlockEmpty(int blockIndex){
        boolean isEmpty = Arrays.equals(emptyBlock, diskBuffer[blockIndex]);
        return isEmpty;
    }

    public boolean isDirfull(int blockIndex){
        boolean isFull = true;
        byte[] emptyBlock = new byte[3];
        if(blockIndex == 2){
            if(getBlock(emptyBlock, (byte)0, blockIndex) != -1) {
                isFull = false;
            }
        }
        else {
            if(getContained(emptyBlock, (byte)0, blockIndex) != -1){
                isFull = !fileAllocationTable.isEmptyBlockEnough(1);
            }else {
                isFull = !fileAllocationTable.isEmptyBlockEnough(2);
            }
        }
        return isFull;
    }
    public void assignDirectorySpace(byte[] name, byte property, byte isExecutable, int dirBlock){
        int blockIndex = 0;
        int itemIndex;
        int assignedBlock;
        byte[] freeSpace = new byte[3];
        blockIndex = getContained(freeSpace, (byte)0, dirBlock);
        if(blockIndex == -1){
            blockIndex = fileAllocationTable.assignNextBlock(dirBlock);
        }
        itemIndex = getItem(freeSpace, (byte)0, blockIndex);
        assignedBlock = fileAllocationTable.assignBlock();
        byte[] byteFile = new byte[8];
        System.arraycopy(name, 0, byteFile, 0, 3);
        byteFile[3] = isExecutable;
        byteFile[4] = property;
        byteFile[5] = (byte)assignedBlock;
        System.arraycopy(byteFile, 0, diskBuffer[blockIndex], itemIndex*8, 8);
    }
    public void writeLength(int length, int blockIndex, int itemIndex){

        byte[] temp = Disk.lengthToBytes(length);
        diskBuffer[blockIndex][itemIndex*8+6] = temp[0];
        diskBuffer[blockIndex][itemIndex*8+7] = temp[1];
    }
    public int getFileLength(String path){
        byte property = TXT_PROERTY;
        if(path.contains(".e")){
            property = EXE_PROERTY;
        }
        byte[][] bytePath = disk.formatPath(path);
        byte[][] fatherPath = Arrays.copyOf(bytePath, bytePath.length - 1);
        byte[] name = bytePath[bytePath.length - 1];
        int fatherDirBlock = this.findDirectory(fatherPath);
        if(fatherDirBlock > 2) {
            fatherDirBlock = this.getContained(bytePath[bytePath.length - 1], property, fatherDirBlock);
        }
        int itemIndex = getItem(name, property, fatherDirBlock);
        int low = Disk.byteToUnsigned(diskBuffer[fatherDirBlock][itemIndex * 8 + 6]);
        int high = Disk.byteToUnsigned(diskBuffer[fatherDirBlock][itemIndex*8+7]) << 8;
        return low + high;
    }
    public void writeContent(byte[] content, int headBlock){
        int blockNum = content.length / 64;
        int tailNum = content.length % 64;
        int blockIndex = headBlock;
        for(int i = 0; i < blockNum; i ++ ){
            System.arraycopy(content, i*64, diskBuffer[blockIndex], 0, 64);
            blockIndex = fileAllocationTable.getNextBlock(blockIndex);
        }
        if(tailNum > 0){
            System.arraycopy(content, blockNum*64, diskBuffer[blockIndex], 0, tailNum);
        }
    }
    public byte[] createByteContent(String content, boolean isExecutable){
        byte[] bytes;
        if(isExecutable) {
            bytes = Util.getByteFile(content);
        }else {
            bytes = disk.stringToBytes(content);
        }
        return bytes;
    }
    public boolean writeFile(byte[] name, byte[] content, byte property, int dirBlock) throws Exception{
        String message;
        byte[] bytes = content;
        int length = bytes.length;
        int blockNum = length / 64 + ((length % 64) == 0 ? 0 : 1);
        if(!fileAllocationTable.isEmptyBlockEnough(blockNum - 1)) {
            message = "空间不足";
            return false;
        }

        return true;
    }
}
