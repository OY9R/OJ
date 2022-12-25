#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    map<int,int>f;
    while(t--){
        f.clear();
        long long n;
        int m=0;cin>>n;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(f.count(a)){
                f[a]=f[a]+1;
            }else{
                f[a]=1;
                m++;
            }
        }
        long long x=0;
        int i=0,mm=m>>1;
        for(auto it=f.begin();i<mm;i++,it++){
            x+=(*it).second;
        }
        cout<<max(x*(n-x),n>>1)<<'\n';
    }
}