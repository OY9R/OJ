#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int a[N];
queue<int> b;
int main() {
    int n,m;cin>>n>>m;
    int i=0;
    while(m--){
        int t;cin>>t;
        if(n){
            if(!a[t])n--;
        }else{
            if(!a[t]){
                while(a[b.front()]!=1){
                    a[b.front()]--;
                    b.pop();
                }
                a[b.front()]--;
                cout<<b.front()<<' ';
                b.pop();
            }
        }
        b.push(t);
        a[t]++;
    }
    return 0;
}