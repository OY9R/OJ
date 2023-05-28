#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    list<char> ls;
    auto in=ls.begin();
    for(char c:s)
        if(c=='[')in=ls.begin();
        else if(c==']')in=ls.end();
        else ls.insert(in,c);
    for(char c:ls)cout<<c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}