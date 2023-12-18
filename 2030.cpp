#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(i==2){
            cout<<2<<endl;
            continue;
        }
        if(i<2||i%2==0)continue;
        bool flag=true;
        for(int j=3;j<i;j+=2){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<i<<endl;
        }
    }
}