package cn.edu.scau.mi.hesguangsheng.������;
import cn.edu.scau.mi.hesguangsheng.������.SortAdapter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		System.out.println("������ѧ�ŵ����ͣ�\n" + "1:������ĸ��eg��201925230107\n" +"2������ĸ�� eg:201925230107z");
		int type = cin.nextInt();
		if(type == 2) {
			List<String> ids = new ArrayList<String>();
			while(true) {
				System.out.println("������ѧ����ѧ��(��end����)");
				String id = cin.nextLine();
				if(id.equals("end")) break;
				ids.add(id);
			}
			SortAdapter sot = new SortAdapter();
			ids = sot.sortString(ids);
			System.out.println("ѧ��ѧ������Ľ������");
			for(int i = 0; i < ids.size(); i ++ ) {
				System.out.println(ids.get(i));
			}
		} else {
			List<Integer> ids = new ArrayList<Integer>();
			while(true) {
				System.out.println("������ѧ����ѧ��(��end����)");
				String id = cin.next();
				if(id.equals("end")) break;
				int idInt = Integer.parseInt(id);
				ids.add(idInt);
			}
			SortAdapter sot = new SortAdapter();
			ids = sot.sortInt(ids);
			System.out.println("ѧ��ѧ������Ľ������");
			for(int i = 0; i < ids.size(); i ++ ) {
				System.out.println(ids.get(i));
			}
		}
		return; 
	}
}
