import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      long K = scanner.nextInt();
      int P = scanner.nextInt();
      int N = scanner.nextInt();
      int d = 1000000007;

      for(int i=0; i<N; i++){
        K=(K*P)%d;
      }
      
      System.out.println(K);
      
    }
}
