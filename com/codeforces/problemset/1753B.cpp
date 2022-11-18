#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
    int n,x,mmin=INT_MAX;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
        mmin=min(mmin,t);
    }
    bool flag=true;
    for(int i=mmin;i<x;i++){
        if(a[i]==0)continue;
        a[i+1]+=a[i]/(i+1);
        a[i]=a[i]%(i+1);
        if(a[i]!=0){
            flag=false;
            break;
        }
    }
    if(flag){
        if(a[x]>0)cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
	return 0;
}