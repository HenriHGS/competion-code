package cn.edu.scau.mi.hesguangsheng.  ≈‰∆˜;

import java.util.List;

public class SortAdapter extends SortUtil implements SortUtilString{
	
	static int cmp(String a, String b) {
		if(a.length() != b.length()) {
			if(a.length() < b.length()) return -1;
			else return 1;
		}else {
			return a.compareTo(b);
		}
		
	}
	@Override
	public List<String> sortString(List<String> stringList){
		boolean flag = true;
		while(flag){
			flag = false;
			for(int i = 0; i < stringList.size() - 1; i ++ ) {
				String a =  stringList.get(i);
				String b = stringList.get(i+1);
				if(cmp(a,b) > 0) {
					flag = true;
					String t = a;
					stringList.set(i,b);
					stringList.set(i+1,a);
				}
			}
		}
		return stringList;
	}
}
