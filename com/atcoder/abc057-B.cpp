#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<pair<int,int> > s(n+1),c(m+1);
  for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
  for(int i=1;i<=m;i++)cin>>c[i].first>>c[i].second;
  for(int i=1;i<=n;i++){
    int minj=0,minx=INT_MAX;
    for(int j=1;j<=m;j++)
      if(abs(s[i].first-c[j].first)+abs(s[i].second-c[j].second)<minx){
        minx=abs(s[i].first-c[j].first)+abs(s[i].second-c[j].second);
        minj=j;
      }
    cout<<minj<<endl;
  }
}