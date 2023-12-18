//二次剩余Cipolla p为奇素数 求a^2=x(%P)
//test:https://www.luogu.com.cn/record/128529590
//blog:https://www.cnblogs.com/bztMinamoto/p/10664973.html
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
struct Cipolla{//a^2=x(%P)
	struct cp{ll x,y;int w,mod;cp(ll _x,ll _y,int _w,int P){x=_x,y=_y;w=_w;mod=P;}//x+y*sqrt(w)(%P)
        inline cp operator*(const cp&b)const{return cp((x*b.x+w*y%mod*b.y)%mod,(x*b.y+y*b.x)%mod,w,mod);}
        inline cp operator*(const int&b)const{return cp((x*b)%mod,(y*b)%mod,w,mod);}};
    ll poww(ll bs,ll x,int P){ll res=1;for(;x;x>>=1,(bs*=bs)%=P)if(x&1)(res*=bs)%=P;return res;}
    int poww(cp x,int y){cp res(1,0,x.w,x.mod);for(;y;y>>=1,x=x*x)if(y&1)res=res*x;return res.x;}
    int Cipo(int x,int P){if(!x)return 0;if(poww(x,(P-1)>>1,P)==P-1)return -1;
    for(int a=1;a<=P>>1;a++){int w=(ll(a)*a-x+P)%P;if(!w)return a;if(poww(w,(P-1)>>1,P)==P-1)
        {int val=poww(cp(a,1,w,P),(P+1)>>1);return min(val,P-val);}}}}Ci;
void solve(){int x,P;cin>>x>>P;int a=Ci.Cipo(x,P);if(a<1){a?cout<<"Hola!\n":cout<<"0\n";return;}cout<<min(a,P-a)<<' '<<max(a,P-a)<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;cin>>t;while(t--)solve();}