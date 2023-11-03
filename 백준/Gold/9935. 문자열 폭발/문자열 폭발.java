import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      String st=scanner.nextLine();
      String target=scanner.nextLine();
      scanner.close();
      
      Stack<Character> stack = new Stack<>();
     
      for(int i=0; i<st.length(); i++){
          stack.push(st.charAt(i));
          
          if(stack.size()>=target.length()){
              boolean flag = true;
              
              for(int j=0; j<target.length(); j++){
                  if(stack.get(stack.size()-target.length()+j)!=target.charAt(j)){
                      flag=false;
                      break;
                  }
              }
              if(flag){
                  for(int j=0; j<target.length(); j++){
                      stack.pop();
                  }
              }
          }
      }
      
      StringBuilder sb = new StringBuilder();
      
      for(Character c : stack){
          sb.append(c);
      }
      
      if(sb.length()!=0){
        System.out.print(sb.toString());
      }
      else System.out.print("FRULA");
    }
}
