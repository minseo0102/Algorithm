import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        Stack<Integer> st = new Stack<>();
        List<Integer> list = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            list.add(i);
        }
        
        int i = 0;//st의 top을 저장
        while(!list.isEmpty()){
            if(st.isEmpty()) {
                i=list.get(0);
                list.remove(0);
                answer++;//하나의 네트워크 시작
            }else{
                i=st.pop();
                list.remove(Integer.valueOf(i));
            }
            for(int j = 0; j<n; j++){
                if(computers[i][j]==1 && list.contains(j)) st.push(j);
            }
            
        }
    
        return answer;
    }
}