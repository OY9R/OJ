#include<bits/stdc++.h>
using namespace std;
const int N=10000001;
int a[N],b[N];
int main() {
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            a[j]+=i;
    memset(b,-1,sizeof b);
    for(int i=1;i<N;i++)
        if(a[i]<N&&b[a[i]]==-1)b[a[i]]=i;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<b[n]<<endl;
    }
    return 0;
}