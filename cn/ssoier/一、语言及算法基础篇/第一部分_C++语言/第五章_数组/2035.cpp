#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a;
    if(a==0)return 0;
    cin>>b;
    while(--a){
        cin>>c;
        cout<<c<<' ';
    }
    cout<<b;
    return 0;
}