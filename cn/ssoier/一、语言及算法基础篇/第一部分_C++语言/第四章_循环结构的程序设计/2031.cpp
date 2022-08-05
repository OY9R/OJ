#include<bits/stdc++.h>
using namespace std;
int a,b;
unsigned long long s,t;
int main(){
    for(int i=32;i<99;++i){
        if(i*i%10==i*i/10%10&&i*i/100%10==i*i/1000){
            cout<<i*i<<endl;
        }
    }
    return 0;
}