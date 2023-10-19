import java.util.Arrays;

class Solution {
    public String solution(int[] numbers) {
        
        String[] nums = new String[numbers.length];
        
        for(int i=0; i<numbers.length; i++){
            nums[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(nums, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        if(nums[0].equals("0")) return "0";
        
        StringBuilder answer = new StringBuilder();
        
        for(int i=0; i<nums.length; i++){
                answer.append(nums[i]);
        }
    
        
        //문자로 표현된 숫자의 경우.. 숫자가 더 크냐가 아니라, 사전식으로 어떤게 더 앞에 있냐를 따지니까.. 문자로 바꿔서 정렬하면 바로 해결됨.
        
        
        return answer.toString();
    }
}