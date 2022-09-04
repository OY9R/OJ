#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int m,n,num=0;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        ll a=pow(i,3)-pow(i-1,3);
        ll l=sqrt(a);
        if(a%l==0)
            for(int j=2;j<l;j++)
                if(j*j+(j-1)*(j-1)==l){
                    num++;
                    cout<<i<<' '<<j<<endl;
                    break;
                }
    }
    if(num==0)cout<<"No Solution"<<endl;
    return 0;
}