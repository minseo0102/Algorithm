import java.io.*;
import java.util.*;

public class Main {

    static long D = 1000000007; 
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      long K = scanner.nextLong();
      long P = scanner.nextLong();
      long N = scanner.nextLong();
      N*=10;
      long res = solve(P,N)*K;

      res%=D;
      
      System.out.println(res);
    }

    public static long solve(long P, long N){
      if(N==1) return P;

      long res = solve(P, N/2);
      if(N%2==0){
        return (res*res)%D;
      }
      else{
        res*=res;
        res%=D;
        return (res*P)%D;
      }
    }
}
