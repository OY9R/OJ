//https://www.cnblogs.com/birchtree/p/12470386.html
//https://www.luogu.com.cn/problem/P4721
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=262144,M=998244353;
struct NTT{//998244352=1048576*8*119//或P=1004535809//支持多测//不可>int
    int n,m,bit,bitnum=0;vector<int>a,b,rev,w;
    int poww(ll a,int b){ll ans=1;for(;b;b>>=1,a=a*a%M)if(b&1)(ans*=a)%=M;return ans;}
    void prew(int n){bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;a.resize(bit,0);b.resize(bit,0)
        ;rev.resize(bit,0);w.resize(bit,0);w[0]=1;int bs=poww(3,(M-1)/bit);
        for(int i=1;i<bit; i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),w[i]=1ll*w[i-1]*bs%M;}
    void _NTT(vector<int>&s,int op){//cur*op:IFFT A/reverse(s+1,s+bit):IFFT B
        for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);int x,y;
        for(int len=1;len<bit;len<<=1)for(int st=0,cur=0,dst=(len<<1),dc=op*bit/(len<<1)+bit;st<bit;st+=dst,cur=0)
            for(int k=st;k<len+st;k++,cur=(cur+dc)&(bit-1))x=s[k],y=ll(s[k+len])*w[cur]%M,s[k]=(x+y)%M,s[k+len]=(x-y+M)%M;
        if(op==-1){int inv=poww(bit,M-2);for(int i=0;i<bit;i++)s[i]=ll(s[i])*inv%M;}}
    void Getmul(){_NTT(a,1);_NTT(b,1);for(int i=0;i<bit;i++)a[i]=ll(a[i])*b[i]%M;_NTT(a,-1);}
    vector<int>solve(vector<int>&aa,vector<int>&bb){a=aa;b=bb;
        n=a.size();m=b.size();prew(n+m-1);Getmul();a.resize(n+m-1);return a;}}K;
void cdq_divide(vector<int>&f,vector<int>&g,int l,int r){
	if(l==r)return;int mid=(l+r)>>1;cdq_divide(f,g,l,mid);
    vector<int>A(mid-l+1);for(int i=0;i<=mid-l;i++)A[i]=f[i+l];
    vector<int>B(r-l);for(int i=0;i<r-l;i++)B[i]=g[i+1];A=K.solve(A,B);
	for(int i=mid+1;i<=r;i++)(f[i]+=A[i-l-1])%=M;cdq_divide(f,g,mid+1,r);}
void solve(){int n;cin>>n;vector<int>f(n),g(n);for(int i=1;i<n;i++)cin>>g[i];
	f[0]=1;cdq_divide(f,g,0,n-1);for(int i=0;i<n;i++)cout<<f[i]<<' ';cout<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;cin>>t;/**/while(t--)solve();}
/*样例:(4|3 1 2=>1 3 10 35)(2|8=>1 8)*/