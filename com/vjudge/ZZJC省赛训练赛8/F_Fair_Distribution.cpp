#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lf;
typedef unsigned long long ull;
typedef pair<int,int>P;
const int inf = 0x7f7f7f7f;
const ll INF = 1e16;
const int N = 1e6+10;
const ll base = 131;
const ll mod =  1e9+7;


inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline string readstring(){string str;char s=getchar();while(s==' '||s=='\n'||s=='\r'){s=getchar();}while(s!=' '&&s!='\n'&&s!='\r'){str+=s;s=getchar();}return str;}
int random(int n){return (int)(rand()*rand())%n;}
void writestring(string s){int n = s.size();for(int i = 0;i < n;i++){printf("%c",s[i]);}}
bool is_prime(int n){if(n <2) return false;for(int i = 2;i*i <= n;i++){if(n%i == 0) return false;}return true;}



void solve(){
    int n = read(),m = read();
    if(n >= m){
        printf("%d\n",n-m);
        return;
    }
    int ans = inf;
    for(int i = 1;i <= n;){
        int l = i;
        int x = (m-1)/l;
        int r = (m-1)/x;
        r = min(r,n);
        //cout<<l<<" "<<r<<endl;
        int ret = n-r;
        int y = ((m-1)/r+1)*r;
        ret += y-m;
        ans = min(ans,ret);
        i = r+1;

        ret = n-l;
        y = ((m-1)/l+1)*l;
        ret += y-m;
        ans = min(ans,ret);
    }
    cout<<ans<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t = read();
    while(t--){
        solve();
    }

    return 0;
}