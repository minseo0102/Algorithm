#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        string s = phone_book[i+1].substr(0, phone_book[i].size());
        if(phone_book[i]==s) {
            answer = false;
            break;
        }
    }
    /*for(int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book.size(); j++){
            if(i==j) continue;
            if(phone_book[i].size()>phone_book[j].size()) continue;
            string s = phone_book[j].substr(0,phone_book[i].size());
            if(phone_book[i]==s) return false;
        }
    }*/
    return answer;
}