#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
using ll=long long;
const int N=2e5+10,P=1e8,M=998244353;
const ll K=1e16;
clock_t a;ll ans;
void int_check()
{
    int C;string s="int";//P=1e8
    a=clock();C=1;for(int i=P;i<=(P<<1);i++)C+=i;ans+=C;cout<<"1e8 "<<s<<" add:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(int i=P;i<=(P<<1);i++)C-=i;ans+=C;cout<<"1e8 "<<s<<" sub:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(int i=P;i<=(P<<1);i++)C*=i;ans+=C;cout<<"1e8 "<<s<<" mul:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C/=i;ans+=C;cout<<"1e8 "<<s<<" div:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C%=i;ans+=C;cout<<"1e8 "<<s<<" mod:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C&=i;ans+=C;cout<<"1e8 "<<s<<" and:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C|=i;ans+=C;cout<<"1e8 "<<s<<" or:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C^=i;ans+=C;cout<<"1e8 "<<s<<" xor:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(int i=P;i<=(P<<1);i++)C=~C;ans+=C;cout<<"1e8 "<<s<<" flip:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
void ll_check()
{
    ll C;string s="ll";//using ll=long long; K=1e16
    a=clock();C=1;for(ll i=K;i<=K+P;i++)C+=i;ans+=C;cout<<"1e8 "<<s<<" add:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(ll i=K;i<=K+P;i++)C-=i;ans+=C;cout<<"1e8 "<<s<<" sub:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(ll i=K;i<=K+P;i++)C*=i;ans+=C;cout<<"1e8 "<<s<<" mul:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C/=i;ans+=C;cout<<"1e8 "<<s<<" div:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C%=i;ans+=C;cout<<"1e8 "<<s<<" mod:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C&=i;ans+=C;cout<<"1e8 "<<s<<" and:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C|=i;ans+=C;cout<<"1e8 "<<s<<" or:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C^=i;ans+=C;cout<<"1e8 "<<s<<" xor:"<<double(clock()-a)<<'\n';
    a=clock();C=K+10;for(ll i=K;i<=K+P;i++)C=~C;ans+=C;cout<<"1e8 "<<s<<" flip:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
void double_check()
{//循环里的i一般绝对不要用double,有极小精度误差,大概率循环次数出错
    double C;string s="double";
    a=clock();C=1;for(double i=1;i<=P;i++)C+=i;ans+=C;cout<<"1e8 "<<s<<" add:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(double i=1;i<=P;i++)C-=i;ans+=C;cout<<"1e8 "<<s<<" sub:"<<double(clock()-a)<<'\n';
    a=clock();C=1;for(double i=1;i<=P;i++)C*=i;ans+=C;cout<<"1e8 "<<s<<" mul:"<<double(clock()-a)<<'\n';
    a=clock();C=P;for(double i=1;i<=P;i++)C/=i;ans+=C;cout<<"1e8 "<<s<<" div:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
int recur(int x)
{
    if(!x)return 1;
    return recur(x-1)+x;
}
void recur_check()
{
    a=clock();int E=1e3;//过深递归会爆栈RE
    for(int i=1;i<=100000;i++)ans+=recur(E);cout<<"1e8 递归函数:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
const int A=100;
int mat[A+10][A+10];
void int2_check()
{
    a=clock();int E=1e4;//过深递归会爆栈RE
    for(int e=1;e<=E;e++)for(int i=1;i<=A;i++)for(int j=1;j<=A;j++)mat[i][j]++;
    cout<<"1e8 二维数组访问:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
void vector_ini_check()
{
    a=clock();int E=1e4;//过深递归会爆栈RE
    for(int e=1;e<=E;e++)vector<int>v(E,1);
    //E=1e4:7ms
    //E=1e5:562ms
    cout<<"1e8 vector初始化:"<<double(clock()-a)<<'\n';
    cout<<'\n';
}
void solve()
{
    int_check();return;
    ll_check();double_check();
    recur_check();int2_check();
    vector_ini_check();
    cout<<ans<<'\n';//防优化
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;/*cin>>t;*/while(t--)solve();
}