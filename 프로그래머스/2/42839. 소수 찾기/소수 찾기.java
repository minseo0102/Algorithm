import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] removeValue(int[] arr, int remove){
        int[] newarr = new int[arr.length-1];
        int first = 0;
        int index = 0;
        for(int i : arr){
            if(i==remove && first==0){
                first = 1;
            }else{
                newarr[index]=i;
                index++;
            }
        }
        
        return newarr;
    }
    
    public void makePrime(int[] arr, Set<Integer> set, int prev){
        for(int i=0; i<arr.length; i++){
            set.add(prev*10+arr[i]);
            int[] newarr = removeValue(arr, arr[i]);
            makePrime(newarr, set, prev*10+arr[i]);
        }
    }
    
    public int solution(String numbers) {
        int answer = 0;//count
        
        int[] nums = new int[numbers.length()];
        Set<Integer> set = new HashSet<>();
        
        for(int i=0; i<numbers.length(); i++){
            nums[i] = Character.getNumericValue(numbers.charAt(i));
        }
        
        for(int i=0; i<nums.length; i++){
            set.add(nums[i]);
            int[] newarr = removeValue(nums, nums[i]);
            makePrime(newarr, set, nums[i]);
        }
        
        //set에는 가능한 모든 값들이 생성된다.
        
        for(int i : set){
            if(i==0 || i==1){//0이거나 1이면 패스
                continue;
            }
            if(i==2 || i==3 || i==5 || i==7){//2,3,5,7이면 count
                answer++;
                continue;
            }
            if(i%2==0){//2의 배수이므로 패스
                continue;
            }else{
                int isPrime = 1;
                for(int j=3; j<=(i/3); j++){
                    if(i%j==0){
                        isPrime=0;
                        break;
                    }
                }
                if(isPrime==1) answer++;
            }
        }
        
        return answer;
    }
}