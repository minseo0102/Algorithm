#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N;
  cin>>N;

  vector<int> h(N);//높이를 담을 벡터
  for(int i=0; i<N; i++){
    cin >> h[i];
  }
  
  vector<int> cnt(N,1);//계수를 담을 벡터
  for(int i=1; i<N; i++){
    int cnt_max=0;//이전 계수 중, 돌의 높이가 현재 돌보다 작으면서, 계수가 가장 큰 것을 저장하기 위함
    
    for(int j=0; j<i; j++){
      if(h[i]>h[j]){//이전 돌이 현재 돌보다 작으면
        cnt_max = max(cnt_max, cnt[j]);
      }
    }

    cnt[i]=cnt_max+1;//이전 계수에 현재 돌까지 합쳐서 계수 설정
  }

  cout<<*max_element(cnt.begin(), cnt.end());

   return 0;
}
