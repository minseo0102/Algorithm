#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
  return a.second>b.second;
}//두번째 요소를 기준으로 내림차순 하도록..

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int W,N;
  cin>>W>>N;

  vector<pair<int, int>> v(N);
  for(int i=0; i<N; i++){
    cin>>v[i].first>>v[i].second;
  }

  sort(v.begin(), v.end(), compare);//두번째 요소를 통해 compare 하도록 비교함수 정의
  
  int value=0;
  for(int i=0; i<N; i++){
    if(W==0) break;
    int used=(v[i].first<=W)?v[i].first:W;
    value+=used*v[i].second;
    W-=used;
  }
  
  cout<<value;
  
   return 0;
}
