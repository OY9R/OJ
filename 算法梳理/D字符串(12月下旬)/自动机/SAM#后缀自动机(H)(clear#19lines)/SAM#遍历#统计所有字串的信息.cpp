//SAM ����/ͳ�������ִ�����Ϣ
//blog/source:https://www.cnblogs.com/zaza-zt/p/15419181.html
//test:https://www.luogu.com.cn/problem/P3804
#include<bits/stdc++.h>
using namespace std;using ll=long long;
struct Suffix_Automaton{//��string s��SAM root=0 �ȼ����к�׺����
    int nod_cnt=0;vector<int>len,link,lit,occ;vector<vector<int>>ch,v;ll ans=0;
    void extend(string s){//occ:�ȼ������Ӵ����ִ��� link:parent��,��һ�ȼ���(���̺�׺)���ڽڵ�  
        //len:�ڵ��Ӧ�ȼ������Ӵ������ lit:�ڵ㱻���ʴ���(��link����lit֮�ͼ��Ӵ����ִ���)       
        int lens=s.length(),L=lens*2+5;len.resize(L),link.resize(L),lit.resize(L,0),occ.resize(L);
        ch.resize(L,vector<int>(26,0));v.resize(L);len[0]=0;link[0]=-1;int cur=0,p,c;for(auto k:s){                    
            p=cur;cur=++nod_cnt,lit[cur]++,c=k-'a';len[cur]=len[p]+1;while(p!=-1&&!ch[p][c])ch[p][c]=cur,p=link[p];
            if(p==-1){link[cur]=0;continue;}int q=ch[p][c];if(len[q]==len[p]+1){link[cur]=q;continue;}
            int copy=++nod_cnt;len[copy]=len[p]+1;link[copy]=link[q];link[q]=link[cur]=copy;
            ch[copy]=ch[q];while(p!=-1&&ch[p][c]==q)ch[p][c]=copy,p=link[p];}
        for(int i=1;i<=nod_cnt;i++)v[link[i]].push_back(i);spr(0,0);}          
    void spr(int x,int lst){occ[x]=lit[x];for(auto k:v[x])if(k!=lst)spr(k,x),occ[x]+=occ[k];
        if(!x)return;if(occ[x]>1)ans=max(ans,ll(occ[x])*len[x]);}
}sam;
int main(){ios::sync_with_stdio(0);cin.tie(0);string s;cin>>s;sam.extend(s);cout<<sam.ans<<'\n';}