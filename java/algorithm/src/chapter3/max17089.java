package chapter3;

import java.util.Scanner;

public class max17089 {
    public static int n, V, W;
    public static int dp[][] = new int[1100][600];
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt(); V = cin.nextInt(); W = cin.nextInt();
        init();
        int ans = 0;
        for(int i = 1; i <= n; i ++ ){
            int v = cin.nextInt(),
            w = cin.nextInt(),
            c = cin.nextInt(), val = cin.nextInt();
            for(int j = V; j >= v; j -- ) for(int k = W; k >= w; k --)for(int p = 1; p <= c; p ++ ){
                int vv = p*v, ww = p*w, cc = p*val;
                if(vv > j || ww > k) continue;
                dp[j][k] = max(dp[j][k], dp[j-vv][k-ww] + cc);
                ans = max(ans,dp[j][k]);
            }
        }
        System.out.println(ans);
        return ;
    }

    private static void init() {
        for(int i = 0; i <= V; i ++ ) for(int j = 0; j <= W; j ++ ) dp[i][j] =0;
    }
    private static int max(int a, int b) {
        if(a > b) return a;
        return b;
    }
}
