//PAM blog:https://www.cnblogs.com/nianheng/p/9814530.html
//test:https://www.luogu.com.cn/problem/P5496
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int N=2e6+10;
struct Palidrone_Automaton{
    vector<int>len,cnt,fail;vector<vector<int>>trie;string s;int n,cur=0,last=0,tot=1;
    int getfail(int x,int i){while(i-len[x]-1<0||s[i-len[x]-1]!=s[i])x=fail[x];return x;}
    void ini(int n){n+=5;len.resize(n);fail.resize(n);trie.resize(n,vector<int>(26,0));cnt.resize(n,0);}
    void extend(string _s){//len:最长回文串长 fail:失配/次长 trie:回文树边 cnt:在i结尾回文串个数   
        s=_s;n=s.length();ini(n);fail[0]=1;len[1]=-1;s+='*';
        for(int i=0;i<=n-1;i++){int c=s[i]-'a',pos=getfail(cur,i);if(!trie[pos][c])
            {fail[++tot]=trie[getfail(fail[pos],i)][c];trie[pos][c]=tot;//不存在建立点，存在直接走过去
                len[tot]=len[pos]+2;cnt[tot]=cnt[fail[tot]]+1;}cur=trie[pos][c];}}}pam;
int main(){ios::sync_with_stdio(0);cin.tie(0);string s;cin>>s;pam.extend(s);}
/*last=cnt[cur];cout<<last<<' ';s[i+1]=(s[i+1]+last-97)%26+97;*/