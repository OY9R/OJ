#include<bits/stdc++.h>
using namespace std;
int main () {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxn=0;
        for(int i=n-1;~i;i--){
            if(a[i]+i<n)
                a[i]+=a[a[i]+i];
            maxn=max(maxn,a[i]);
        }
        cout<<maxn<<endl;
    }
    return 0;
}