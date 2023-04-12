#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int rever(int n){
    char s[114514];
    memset(s,0,sizeof s);
    sprintf(s,"%d",n);
    reverse(s,s+strlen(s));
    sscanf(s,"%d",&n);
    return n;
}
void solve(){
    int a,b;cin>>a>>b;
    cout<<rever(rever(a)+rever(b))<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}