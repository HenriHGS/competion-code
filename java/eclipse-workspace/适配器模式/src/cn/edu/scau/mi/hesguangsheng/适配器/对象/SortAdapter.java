package cn.edu.scau.mi.hesguangsheng.  ≈‰∆˜.∂‘œÛ;

package cn.edu.scau.mi.hesguangsheng.  ≈‰∆˜;

import java.util.List;

public class SortAdapter  implements SortUtilString{
	
	static int cmp(String a, String b) {
		if(a.length() != b.length()) {
			if(a.length() < b.length()) return -1;
			else return 1;
		}else {
			return a.compareTo(b);
		}
		
	}
	static List<Integer> sortInt1(List<Integer> intList) {
		SortUtil sot = new SortUtil();
		intList = sot.sortInt(intList);
		return intList;
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
