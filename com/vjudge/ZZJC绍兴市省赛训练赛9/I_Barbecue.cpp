#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1000007,P=131;
ULL hl[N], hr[N], p[N];
int n,m;
string str;
inline void init(){
    p[0]=1;
    for(int i=1;i<=n;i++){
        hl[i]=hl[i-1]*P+str[i-1]-'a';
        hr[i]=hr[i-1]*P+str[n-i]-'a';
        p[i]=p[i-1]*P;
    }
}
inline ULL get(int l,int r){
    if(l<r)return hl[r]-hl[l-1]*p[r-l+1];
    else return hr[n-r+1]-hr[n-l]*p[l-r+1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>str;
    init();
    while(m--){
        int l,r;cin>>l>>r;
        // cout<<get(l,r)<<':'<<get(r,l)<<endl;
        if((r-l+1)%2==0||get(l,r)==get(r,l)){
            cout<<"Budada\n";
        }else{
            cout<<"Putata\n";
        }
    }
	return 0;
}