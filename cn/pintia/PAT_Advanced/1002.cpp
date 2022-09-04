#include<bits/stdc++.h>
using namespace std;
int an,n;
double x,a[1001];
int main(){
    cin>>an;
    while(an--){
        cin>>n>>x;
        a[n]=x;
    }
    cin>>an;
    while(an--){
        cin>>n>>x;
        a[n]+=x;
    }
    int l=0;
    for(int i=0;i<=1000;i++)
        if(a[i])l++;
    cout<<l;
    for(int i=1000;i>=0;i--)
        if(a[i])printf(" %d %.1lf",i,a[i]);
    return 0;
}