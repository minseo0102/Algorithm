#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    if(numbers.empty()){
        if(target==0) return 1;
        else return 0;
    }
    
    int answer = 0;
    int top = numbers.back();
    numbers.pop_back();
    
    answer+=solution(numbers, target+top);
    answer+=solution(numbers, target-top);
    
    return answer;
}