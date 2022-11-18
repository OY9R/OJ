#include<bits/stdc++.h>
using namespace std;
int a[200002];
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        n+=2;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        long long sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i];
        long long t=-1,ans=-1;
        for(int i=n-2;i<=n-1;i++){
            for(int j=0;j<n;j++)
                if(j!=i&&sum-a[j]==a[i]+a[i]){
                    t=j,ans=i;
                    break;
                }
        }
        if(t==-1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(i==t||i==ans) continue;
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}