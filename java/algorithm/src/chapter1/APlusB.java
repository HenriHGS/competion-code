    package chapter1;

    import java.math.BigInteger;
    import java.util.Scanner;

    public class APlusB {
        public static void main(String[] args){
            Scanner cin = new Scanner(System.in);
            String sa, sb;
            sa = cin.next();
            sb = cin.next();
            BigInteger A = new BigInteger(sa);
            BigInteger B = new BigInteger(sb);
            A = A.add(B);
            System.out.println(A);
           /* int a = cin.nextInt(), b = cin.nextInt();
            System.out.println(a+b);*/
        }
    }
