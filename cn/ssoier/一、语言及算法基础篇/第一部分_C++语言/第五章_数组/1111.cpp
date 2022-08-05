#include <bits/stdc++.h>
using namespace std;
#define N 10
int a[N];
int main(){
    int x,y;
    for(int i=1;i<=7;i++){
        cin>>x>>y;
        a[i]=x+y;
        if(a[i]>8){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}