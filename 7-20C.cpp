#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
string s;
int i;
ll solve(){
    getline(cin,s);
    i=0;
    int n=s.size();
    ll type=0,ans=0;
    switch (s[0]){
        case 'i':i=4;type=4;break;
        case 'l':i=5;type=8;break;
        case 'S':i=7;type=1;break;
    }
    if(s[i]==']')
        for(i+=2;i<n;i++)
            if(s[i]=='='){
                i+=5;
                if(s[i]=='i')i+=4,type=4;
                else i+=5,type=8;
                ans+=type*atoi(s.c_str()+i);
                while(i<n&&s[i]!=']')i++;
            }else;
    else
        if(type!=1)
            for(;i<n;i++)
                if(s[i]=='=')ans+=type;
                else;
        else
            for(int ss=0;i<n;i++)
                if(s[i]=='"')
                    if(ss)ans+=i-ss-1,ss=0;
                    else ss=i;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    getline(cin,s);
    ll sum=0;
    while(n--)sum+=solve();
    ll a=0,b=0,c=0,d=0;
    d=sum;
    c=d/1024,d%=1024;
    b=c/1024,c%=1024;
    a=b/1024,b%=1024;
    if(a)cout<<a<<"GB";
    if(b)cout<<b<<"MB";
    if(c)cout<<c<<"KB";
    if(d)cout<<d<<"B";
    cout<<'\n';
    return 0;
}