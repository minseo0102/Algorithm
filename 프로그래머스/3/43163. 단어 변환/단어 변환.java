import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    static List<String> list;
    static int answer;
    static boolean[] visited;
    
    public int solution(String begin, String target, String[] words) {
        answer = Integer.MAX_VALUE;
        list = new ArrayList<>(Arrays.asList(words));
        
        if(!list.contains(target)) return 0;
        
        for(int i=0; i<words.length; i++){
            if(canChange(words[i], begin)){
                visited = new boolean[words.length];
                visited[i]=true;
                dfs(1,words,words[i],target);
            }
        }
        
        return answer;
    }
    public void dfs(int index, String[] words, String begin, String target){
        if(begin.equals(target)){
            answer=Math.min(index, answer);
            return;
        }
        
        for(int i=0; i<words.length; i++){
            if(!visited[i]&&canChange(words[i],begin)){
                visited[i]=true;
                dfs(index+1, words, words[i], target);
                visited[i]=false;
            }
        }
    }
    
    public boolean canChange(String target, String begin){
        int count=0;
        for(int i=0; i<begin.length(); i++){
            if(begin.charAt(i)!=target.charAt(i)) count++;
        }
        
        return count==1;
    }
}