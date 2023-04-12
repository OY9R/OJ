#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
string s;
int i;
vector<string> vs;
void dfs(int lv){
    if(s[i]>='a'){vs[lv]+=s[i--];return;}
    if(vs.size()==lv+1)vs.push_back("");
    vs[lv]+=s[i--];
    dfs(lv+1),dfs(lv+1);
}
void solve(){
    cin>>s;i=s.size()-1;
    vs=vector<string>();
    vs.push_back("");
    dfs(0);
    reverse(all(vs));
    for(int i=0;i<vs.size();i++)cout<<vs[i];
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}