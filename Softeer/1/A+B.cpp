#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin>>T;

  for(int i=0; i<T; i++){
    int A,B;
    cin>>A>>B;
    cout<<"Case #"<<i+1<<": "<<A+B<<endl;
  }
  
   return 0;
}
