#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353,N=1e6+10;
struct Pri_info{
    int P;vector<int>pris,mind;
    void ini(int _P){P=_P;mind.resize(P+1,0);//����/��С������
        for(int i=2;i<=P;i++){if(!mind[i])mind[i]=i,pris.push_back(i);
            for(auto k:pris){if(k*i>P)break;mind[i*k]=k;if(k==mind[i])break;}}}
    vector<vector<int>>pfac;void getpfac(){pfac.resize(P+1);for(int i=2,lst;i<=P;i++)//����������
        {lst=i/mind[i];pfac[i]=pfac[lst];if(mind[i]!=mind[lst])pfac[i].push_back(mind[i]);}}
    vector<vector<int>>pfac2;void getpfac2(){pfac2.resize(P+1);pfac2[1].push_back(1);for(int i=2,lst;i<=P;i++)//�����ӵȼ�
        {lst=i/mind[i];pfac2[i]=pfac2[lst];if(mind[i]!=mind[lst])for(auto k:pfac2[lst])pfac2[i].push_back(k*mind[i]);}}
    vector<int>phi;void getphi(){phi.resize(P+1);phi[1]=1;for(int i=2,x;i<=P;i++)//����ɸŷ������
        x=i/mind[i],phi[i]=phi[x]*(mind[i]-(mind[i]!=mind[x]));}
}Pfo;
void precal(){Pfo.ini(100);Pfo.getpfac();Pfo.getpfac2();Pfo.getphi();}
int main(){ios::sync_with_stdio(0);cin.tie(0);precal();}