package chapter1;

public class perfectNum {
    static boolean isPrime(long x){
        if(x <= 1) return false;
        for(long i = 2; i <= x/i; i ++ ){
            if(x % i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args){
        long ans = 0,st = 0;
        for(st = 1; ans <= 7; st++){
            long x = (long)1<<st;
            //System.out.println(x - 1);
            if(isPrime(x - 1)){
                ans++;
                long res = ((long)1<<(st-1)) * (x-1);
                System.out.println(ans + " " + res);
            }
        }
        return;
    }
}
