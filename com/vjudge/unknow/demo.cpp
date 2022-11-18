#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int in[N],pre[N];
int tree[N],n;
int maxi=0;
void bulid(int tri,int si,int ini,int prei){
    if(si==0||prei==n){
        maxi=max(tri,maxi);
        return;
    }
    tree[tri]=pre[prei];
    int ri=find(in+ini,in+ini+si,pre[prei])-in-ini;
    bulid(tri*2,ri,ini,prei+1);
    bulid(tri*2+1,si-ri-1,ini+ri+1,prei+ri+1);
}
void printport(int ri){
    if(tree[ri]==0)return;
    printport(ri*2);
    printport(ri*2+1);
    cout<<tree[ri]<<' ';
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    bulid(1,n,0,0);
    // for(int i=0;i<=maxi;i++)
    //     cout<<tree[i]<<' ';
    
    printport(1);
    return 0;
}