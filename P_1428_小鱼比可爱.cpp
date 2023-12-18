#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[j]<a[i])b[i]++;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
}