#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=-1,l=0,r=n-1;
    int temp=0,first=0;
    for(int i=0;i<n;i++){
        temp=temp+a[i];
        if(temp<0){
            temp=0;
            first=i+1;
        }else if(temp>ans){
            ans=temp;
            l=first;
            r=i;
        }
    }
    if(ans<0)
        ans=0;
    cout<<ans<<' '<<a[l]<<' '<<a[r]<<endl;
    return 0;
}