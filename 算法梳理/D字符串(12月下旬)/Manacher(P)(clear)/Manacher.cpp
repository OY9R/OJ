//Manacher(Original)test:https://www.luogu.com.cn/problem/P3805
#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct Manacher{//1 bas
    string s;int len,mr,C;vector<int>mxp;//mxp[a]=b=>s[a-b:a+b]ok/broader not
    void Pre(string&_s){
        s="%";mr=-1;for(auto k:_s)s+=k,s+='|';s.back()='$';
        len=s.length();mxp.clear();mxp.resize(len,0);
        for(int x=1;x<len-1;x++){if(mr>x)mxp[x]=min(mr-x,mxp[C-x]);
            while(s[x-mxp[x]-1]==s[x+mxp[x]+1])mxp[x]++;if(x+mxp[x]>mr)mr=x+mxp[x],C=x*2;}}
    vector<int> Range_Extract(){
        int L2=len/2;vector<int>mr(L2,0);for(int i=1;i<len-1;i++)mr[(i-mxp[i])/2]=i;//l+r+1=i
        for(int i=1;i<L2;i++)mr[i]=max(mr[i],mr[i-1]);for(int i=0;i<L2;i++)mr[i]-=(i+1);return mr;}}ManaS;
struct satsky{void Solve(){string s;cin>>s;ManaS.Pre(s);auto vmr=ManaS.Range_Extract();
    int len=vmr.size(),mx=0;for(int i=0;i<len;i++)mx=max(mx,vmr[i]-i+1);cout<<mx<<'\n';}};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--){satsky S;S.Solve();}}