package chapter3;

import java.util.Scanner;

public class bi8598 {
    private static int n, ans;
    private static int dp[] = new int[200010];
    private static int dp2[] = new int[200010];
    private static int vv[] = new int[200010];
    private static int cc[] = new int[200010];
    private static final int maxn = 200010;
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        init();
        dp[0] = 0; dp2[0] = 1;
        for(int i = 1; i <= n; i++ ){
            int x = cin.nextInt();
            vv[i] = x;
        }
        for(int i = 1; i <= n; i++ ){
            int x = cin.nextInt();
            cc[i] = x;
        }
        for(int i = 1; i <= n; i++ ){
            int v = vv[i],
            c = cc[i];
            for(int j = maxn - 1; j >= 0; j -- ){
                for(int k = 1; k <= c; k ++ ){
                    if(k*v <= j && dp[j-k*v] != maxn) {
                        dp[j] = min(dp[j], dp[j-k*v] + k);
                        dp2[j] += dp2[j-k*v];
                    }
                }
            }
        }
        ans = cin.nextInt();
        if(dp[ans] == maxn) System.out.println("no possible");
        else {
            System.out.println(dp2[ans]);
            System.out.println(dp[ans]);
        }
    }
    private static int min(int a, int b){
        return (a>b?b:a);
    }
    private static void init() {
        for(int i = 0; i < maxn; i ++ ) { dp[i] = maxn; dp2[i] = 0; }
    }
}
/*
3
1 2 5
3 3 1
7
 */
