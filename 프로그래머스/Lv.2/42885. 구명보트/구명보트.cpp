#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), compare);
    
    int left=0;
    int right=people.size()-1;
    
    while(left<=right){
        answer++;
        if(limit-people[left]>=people[right]){
            left++;
            right--;
        }
        else{
            left++;
        }
    
    }
    
    return answer;
}