#include <bits/stdc++.h>
using namespace std;
 
int main(){
    float m,n;
    cin>>m;
    float s=0;
    for(n=1;;n++){
        s=s+(1/n);
        if(s>=m){
            cout<<n;
            break;
        }
        if(m<0){
            cout<<0;
            break;
        }
    }
    return 0;
}