import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Stack<String> st = new Stack<>();
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '('){
                st.push("(");
            }else{
                if(st.isEmpty()){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        //System.out.println("Hello Java");
        
        if(!st.isEmpty()) answer = false;
        
        return answer;
    }
}