#include<bits/stdc++.h>
using namespace std;
int ans;
unordered_map<int,int> m1,m2;
inline void lsh(int x){
    if(m1[x]==0)m1[x]=x,m2[x]=1;
}
inline int find(int x){
    return m1[x]==x?x:m1[x]=find(m1[x]);
}
inline void add(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return;
    m1[b]=a;m2[a]+=m2[b];
    if(m2[a]>ans)ans=m2[a];
}
inline void solve(){
    ans=0,m1.clear(),m2.clear();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        lsh(a),lsh(b);
        add(a,b);
    }cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}