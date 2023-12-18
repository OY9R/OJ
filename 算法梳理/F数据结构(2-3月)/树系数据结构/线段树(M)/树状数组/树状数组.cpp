#include <bits/stdc++.h>//Ê÷×´Êý×é
using namespace std;;using ll=long long;
template <typename T>struct Fenwick{int n,B;vector<T>a;
    void init(int n_){n=n_+1;for(B=1;B*2<=n;B<<=1);a.assign(n+1,T{});}Fenwick(int n_=0){init(n_);}
    void add(int x,const T&v){for(int i=x;i<=n;i+=i&-i)a[i]+=v;}
    T sum(int x){T ans{};for(int i=x;i;i-=i&-i)ans+=a[i];return ans;}
    T rangeSum(int l,int r){return sum(r)-sum(l-1);}
	int kth(int k){int res=0;k--;for(int b=B;b;b>>=1)if(res+b<=n&&sum(res+b)<=k)res+=b;return res+1;}};