#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,z;cin>>n>>k>>z;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll sum=0;
        for(int i=0;i<=k;i++){
            sum+=a[i];
        }
        ll maxb=-1,maxi;
        for(int i=k;i;i--){
            b[i]=a[i]+a[i-1];
            if(maxb<b[i]){
                maxb=b[i];
                maxi=i;
            }
        }
        //cout<<b[k]<<' ';
        int i=k;
        while(i>=maxi+2&&z&&b[i]<maxb){
            sum=sum-b[i]+maxb;
            i-=2;z--;
        }
        //cout<<i<<' ';
        if(z&&i>1&&a[i-2]>a[i]){
            sum=sum-a[i]+a[i-2];
        }
        cout<<sum<<'\n';
    }
    return 0;
}