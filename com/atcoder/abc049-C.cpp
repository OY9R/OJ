#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  string t="";
  for(int i=s.size()-1;i>=0;i--){
    t+=s[i];
    if(t=="maerd" || t=="remaerd" || t=="esare" || t=="resare")t="";
  }
  if(t.empty()) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}