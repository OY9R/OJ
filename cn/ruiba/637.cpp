#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<20;
int a[MAXN],b[MAXN],c[MAXN];
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
	while(cin>>n){
        int x,mmax=0;
        memset(a,0,n*sizeof(int));
        memset(c,0,n*sizeof(int));
        for(int i=0;i<n;i++)
            cin>>x,a[x]++,mmax=max(mmax,x);
        c[n]=1;
        for(int i=2;i<=mmax;i++){
            for(int j=i;j<=mmax;j+=i)
                b[i]+=a[j];
            c[b[i]]=i,b[i]=0;
        }
        for(int i=n-1;i;i--)
            c[i]=max(c[i],c[i+1]);
        for(int i=1;i<=n;i++)
            cout<<c[i]<<"\n";
    }
}