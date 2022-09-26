#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e8 + 7;
int primes[N], cnt=1;
bool st[N];

void getPrimes(int n) {
    primes[0]=2;
    for(int i=3;i<=n;i+=2){
        if(!st[i])
            primes[cnt++]=i;
        for(int j=1;j<cnt&&i*primes[j]<=n;j++){
            st[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    getPrimes(n);
    while(q--) {
        int m;
        cin>>m;
        cout<<primes[m-1]<<'\n';
    }
    return 0;
}