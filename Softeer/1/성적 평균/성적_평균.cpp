#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
  int N,K;
  
  cin>>N>>K;

  vector<double> prefixSum(N+1);

  prefixSum[0]=0;
  
  for(int i=1; i<N+1; i++){
    int S;
    cin>>S;
    prefixSum[i] = prefixSum[i-1]+(double)S;
  }

  int A,B;
  for(int i=1; i<K+1; i++){
    cin>>A>>B;
    printf("%.2f\n", (double)(prefixSum[B]-prefixSum[A-1])/(double)(B-A+1));
  }

  return 0;
}
