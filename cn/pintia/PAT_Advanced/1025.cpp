#include<bits/stdc++.h>
using namespace std;
int m[100100];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i];
    int l=0;
    while(l<n){
        int maxi,maxn=0;
        for(int i=l;i<n;i++){
            if(m[i]>maxn){
                maxn=m[i];
                maxi=i;
            }
        }
        for(int i=maxi;i>=l;i--){
            cout<<m[i]<<' ';
        }
        l=maxi+1;
    }
    return 0;
}
