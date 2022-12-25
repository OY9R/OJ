#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string s;int i;
bool flag=true;
void dfs(vector<int> m){
    vector<int> mm(m);
    while(i<s.size()){
        if(s[i]=='(')i++,dfs(mm);
        else if(!flag) break;
        else if(s[i]==')'){i++;break;}
        else if(mm[s[i]-'a']%2==1){flag=false;break;}
        else mm[s[i++]-'a']++;
    }
}
void solve(){
    cin>>s;
    vector<int> m(26);
    dfs(m);
    if(flag)cout<<"Yes";
    else cout<<"No";
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}