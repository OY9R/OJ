#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  int w = 0, l = 0;
  for(int i=0;i<S.size();i++){
    if(i%2==0 && S[i] == 'p') l++;
    else if(i%2 && S[i] == 'g') w++;
  }
  cout<<w-l<<endl;
}