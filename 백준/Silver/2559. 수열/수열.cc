#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<int> v(N+1,0);
    
    for(int i=1; i<N+1; i++){
        int temp;
        cin>>temp;
        v[i]=v[i-1]+temp;
    }
    
    int max=v[K];
    for(int i=K+1; i<N+1; i++){
        max=(max<v[i]-v[i-K])?v[i]-v[i-K]:max;
    }
    
    cout<<max;
    
    return 0;
}