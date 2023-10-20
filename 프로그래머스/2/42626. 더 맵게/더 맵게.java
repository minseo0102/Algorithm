import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int item : scoville){
            pq.offer(item);
        }
        
        while(pq.peek()<K && pq.size()>=2){
            int temp1 = pq.poll();
            int temp2 = pq.poll();
            pq.offer(temp1+(temp2*2));
            answer++;
        }
        
        if(pq.size()==1 && pq.peek()<K) return -1;
        
        return answer;
    }
}