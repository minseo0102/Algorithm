import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] arr = new int[n+1];
    
        Arrays.fill(arr,0);
        
        for(int i=0; i<reserve.length; i++){
            arr[reserve[i]]++;
        }
        
        int lost_num=lost.length;
        
        Stack<Integer> st = new Stack<>();
        
        Arrays.sort(lost);
        
        for(int i=0; i<lost.length; i++){
            if(arr[lost[i]]==1){
                arr[lost[i]]--;
                lost_num--;
            }else{
                st.push(lost[i]);
            }
        }
        
        while(!st.isEmpty()){
            if(st.peek()<n&&arr[st.peek()+1]==1){
                arr[st.peek()+1]--;
                lost_num--;
            }
            else if(st.peek()>1&&arr[st.peek()-1]==1){
                arr[st.peek()-1]--;
                lost_num--;
            }
            st.pop();
        }
        
        answer=n-lost_num;
        return answer;
    }
}