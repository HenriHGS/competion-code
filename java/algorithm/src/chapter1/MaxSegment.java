package chapter1;

import java.util.Scanner;

import static java.lang.Math.abs;
import static java.lang.Math.max;

public class MaxSegment {
    public static void main(String[] args){
        int[] a = new int[10010];
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for(int i = 1; i <= n; i ++ ) a[i] = cin.nextInt();
        int i = n, j = n;
        int ans = j - i + 1;

        for(; i >= 1 && j >= 1; j--){
            while(i>=1 && a[i] <= abs(a[j])) i--;
            ans = max(ans,j - i);
        }
        System.out.println(ans);
    }
}
