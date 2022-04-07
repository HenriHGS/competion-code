package chapter3;


import java.util.Scanner;

//import static sun.swing.MenuItemLayoutHelper.max;

public class rock8597 {
    static final int dx[] = new int[]{1,-1,0,0};
    static final int dy[] = new int[]{0,0,-1,1};
    static int dist[][] = new int[300][300];
    static int n, m;
    static int g[][] = new int[300][300];
    public static void init(){
        for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= m; j ++ ) dist[i][j] = 0;
    }
    public static int max(int a, int b){
        if(a > b) return a;
        return b;
    }
    public static int dp(int x, int y){
        int tx, ty;
        if(dist[x][y] != 0) return dist[x][y];
        int res = dist[x][y];
        for(int k = 0; k < 4; k ++ ){
            tx = x + dx[k];
            ty = y + dy[k];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && g[x][y] > g[tx][ty])res = max(res, 1 + dp(tx,ty));
        }
        dist[x][y] = res;
        if(res == 0) res = dist[x][y] = 1;
       // System.out.println("dist" + "[" + x + "]" + "[" + y + "] = " + res);
        return res;
    }
    public static void main(String[] args){
        init();
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt(); m = cin.nextInt();
        int ans = 0;
        for(int i = 1; i <= n;  i++ ) for(int j = 1; j <= m; j ++ ) g[i][j] = cin.nextInt();
        for(int i = 1; i <= n;  i++ ) for(int j = 1; j <= m; j ++ ) ans = max(ans,dp(i,j));
        System.out.println(ans);
    }
}
