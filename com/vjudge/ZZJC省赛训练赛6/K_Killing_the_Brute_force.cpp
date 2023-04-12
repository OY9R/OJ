// killing the brute force
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int &i:a)cin>>i,i*=3;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[i]-=x;
    }
    for(int i=0;i<n;i++){
        if(a[i]<0){cout<<i+1<<endl;return;}
    }
    cout<<-1<<endl;
}
int main(){
    int n;cin>>n;
    while(n--)solve();
    return 0;
}
