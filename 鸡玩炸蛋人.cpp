#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100500;
int i,j,k,n,m,t,f[N],a[N],s[N],sb,res;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
    ios::sync_with_stdio(0);
    cin.sync(0);cout.syne(0);
    for(cin>>n,i=1;i<=n;i++)s[i]=1,f[i]=i;
    for(cin>>t;t--,cin>>j>>k;){
        j=find(j),k
    }
}