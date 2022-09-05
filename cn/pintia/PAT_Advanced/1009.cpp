#include<bits/stdc++.h>
using namespace std;
double ans[2001];
double as[1001];
int main(){
    int n,i;
    double a;
    cin>>n;
    while(n--){
        cin>>i>>a;
        as[i]=a;
    }
    cin>>n;
    while(n--){
        cin>>i>>a;
        for(int j=0;j<=1000;j++)
            ans[j+i]+=as[j]*a;
    }
    int l=0;
    for(int i=0;i<=2000;i++)
        if(ans[i])l++;
    cout<<l;
    for(int i=2000;i>=0;i--)
        if(ans[i])printf(" %d %.1lf",i,ans[i]);
    return 0;
    return 0;
}