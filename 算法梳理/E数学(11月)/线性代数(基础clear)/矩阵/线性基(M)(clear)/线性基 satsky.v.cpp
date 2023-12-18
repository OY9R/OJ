#include<bits/stdc++.h>//ÏßÐÔ»ù https://codeforces.com/problemset/problem/587/E
using namespace std;using ll=long long;const int M=998244353,P=20,K=18;//20/18
struct Khe{vector<int>bs;Khe(int x=0){ini(x);}void ini(int x=0){bs.resize(P+1,0);if(x)ins(x);}
	void ins(int x){for(int i=P;i>=0;i--)if(x&(1<<i)){if(bs[i])x^=bs[i];else bs[i]=x,x=0;}}
	bool chk(int x){for(int i=P;i>=0;i--)if(x&(1<<i))x^=bs[i];return bool(x);}
	Khe operator+(const Khe &B){Khe A=*this;for(auto&k:B.bs)A.ins(k);return A;}
	void operator+=(const Khe &A){for(auto&k:A.bs)ins(k);}};