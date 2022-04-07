package cn.edu.scau.mi.hesguangsheng.ÊÊÅäÆ÷;

import java.io.*;
import java.util.*;
public class SortUtil {
	static List<Integer> sortInt(List<Integer> intList) {
		boolean flag = true;
		while(flag) {
			flag = false;
			for(int i = 0; i < intList.size() - 1; i ++ ) {
				if(intList.get(i) > intList.get(i+1)) {
					flag = true;
					int t = intList.get(i);
					intList.set(i, intList.get(i+1));
					intList.set(i + 1, t);
				}
			}
		}
		return intList;
	}
}
