#include<bits/stdc++.h>
using namespace std;
int mm[500][500];
int d[500];
int p[500];
int v[500];
int c[500];
int a[500];
int n,m,c1,c2;
int main(){
    for(int i=0;i<500;i++)
        for(int j=0;j<500;j++)
            mm[i][j]=INT_MAX;
    for(int i=0;i<500;i++)
        d[i]=INT_MAX;
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<m;i++){
        int t1,t2,l;
        cin>>t1>>t2>>l;
        mm[t1][t2]=l;
        mm[t2][t1]=l;
    }
    d[c1]=0;
    c[c1]=1;
    for(int i=0;i<n;i++){
        int w=-1,mn=INT_MAX;
        for(int j=0;j<n;j++)
            if(!p[j]&&d[j]<mn)
                w=j,mn=d[j];
        if(w==-1)break;
        p[w]++;
        for(int j=0;j<n;j++)
            if(!p[j]&&mm[w][j]!=INT_MAX){
                if(d[j]==d[w]+mm[w][j]){
                    c[j]+=c[w];
                    a[j]=max(a[j],a[w]+v[w]);
                }
                if(d[j]>d[w]+mm[w][j]){
                    d[j]=d[w]+mm[w][j];
                    c[j]=c[w];
                    a[j]=a[w]+v[w];
                }
            }
    }
    cout<<c[c2]<<' '<<a[c2]+v[c2];
    return 0;
}