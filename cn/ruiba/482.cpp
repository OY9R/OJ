#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e8 + 7;
int primes[N], cnt;
bool st[N];
void getPrimes(int n) {
    primes[0]=0;
    for(int i=2;i<=n;i++){
        if(!st[i])
            primes[++primes[0]]=i;
        for(int j=1;j<=primes[0]&&i<=n/primes[j];j++){
            st[i*primes[j]]=1;
            if(i%primes[j]==0)
                break;
        }
    }
}
int main() {
    int n,q;
    cin >> n >> q;
    getPrimes(n);
    while(q--) {
        int m;
        cin>>m;
        cout<<primes[m]<<endl;
    }
    return 0;
}