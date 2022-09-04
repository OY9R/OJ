#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    int d[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>d[i][j];
    int s=1;
    for(int i=0;i<n;i+=2){
        for(int j=n-s-1;j>=0;j--)
            d[i][j+s]=d[i][j];
        for(int j=0;j<s;j++)
            d[i][j]=x;
        if(++s>k)
            s=1;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            d[0][j]+=d[i][j];
    for(int i=0;i<n;i++){
        if(i!=0)
            cout<<" ";
        cout<<d[0][i];
    }
    return 0;
}