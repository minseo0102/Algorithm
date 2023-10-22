import java.util.Arrays;//배열의 정렬 sort함수를 가지고 있음

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        for(int i=citations.length-1; i>=0; i--){
            if(citations[i]>=citations.length-i){ 
                answer=citations.length-i;//i번째 논문 인용수 이상의 인용수를 갖는 논문개수가 h이므로, 위 조건을 따른다면 i번째 논문은 무조건 h번 이상 인용된 논문임.
            }else break;
        }
        return answer;
    }
}