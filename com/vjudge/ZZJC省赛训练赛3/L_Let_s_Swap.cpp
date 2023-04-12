#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int P=131,N=500005;
ull h[N<<1],p[N<<1],h2[N];
void solve(){
    string s1,s2;cin>>s1>>s2;
    int a,b,n=s1.size();cin>>a>>b;
    int g=__gcd(abs(a-b),n);
    string ss=s1+s1;
    p[0]=1;
    for(int i=1;i<=n*2;i++){
        h[i]=h[i-1]*P+ss[i-1];
        p[i]=p[i-1]*P;
    }
    for(int i=1;i<=n;i++){
        h2[i]=h2[i-1]*P+s2[i-1];
    }
    ull t2=h2[n]-h2[0]*p[n];
    for(int off=0;off<n;off+=g){
        ull t1=h[off+n]-h[off]*p[n];
        if(t1==t2){
            cout<<"yes\n";
            return;
        }
    }
    reverse(s1.begin(),s1.begin()+a);
    reverse(s1.begin()+a,s1.end());
    ss=s1+s1;
    for(int i=1;i<=n*2;i++){
        h[i]=h[i-1]*P+ss[i-1];
    }
    for(int off=0;off<n;off+=g){
        ull t1=h[off+n]-h[off]*p[n];
        if(t1==t2){
            cout<<"yes\n";
            return;
        }
    }
    cout<<"no\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}