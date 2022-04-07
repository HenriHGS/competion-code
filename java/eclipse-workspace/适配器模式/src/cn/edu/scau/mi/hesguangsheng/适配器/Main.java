package cn.edu.scau.mi.hesguangsheng.适配器;
import cn.edu.scau.mi.hesguangsheng.适配器.SortAdapter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		System.out.println("请输入学号的类型：\n" + "1:不含字母，eg：201925230107\n" +"2：含字母， eg:201925230107z");
		int type = cin.nextInt();
		if(type == 2) {
			List<String> ids = new ArrayList<String>();
			while(true) {
				System.out.println("请输入学生的学号(以end结束)");
				String id = cin.nextLine();
				if(id.equals("end")) break;
				ids.add(id);
			}
			SortAdapter sot = new SortAdapter();
			ids = sot.sortString(ids);
			System.out.println("学生学号排序的结果如下");
			for(int i = 0; i < ids.size(); i ++ ) {
				System.out.println(ids.get(i));
			}
		} else {
			List<Integer> ids = new ArrayList<Integer>();
			while(true) {
				System.out.println("请输入学生的学号(以end结束)");
				String id = cin.next();
				if(id.equals("end")) break;
				int idInt = Integer.parseInt(id);
				ids.add(idInt);
			}
			SortAdapter sot = new SortAdapter();
			ids = sot.sortInt(ids);
			System.out.println("学生学号排序的结果如下");
			for(int i = 0; i < ids.size(); i ++ ) {
				System.out.println(ids.get(i));
			}
		}
		return; 
	}
}
