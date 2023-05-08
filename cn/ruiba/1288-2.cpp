#include <bits/stdc++.h>
using namespace std;
const int N= 2e7 + 5, mod= 1e9 + 7;
long long n, k;
int P[N], pcnt, ik[N], d[N], up, x;
bool notp[N];
__int128 res= 1;
int main() {
    cin >> n >> k;
    d[1]= ik[1]= 1;
    up= k % (mod - 1);
    for(int i= 2; i <= n; i++) {
        if(!notp[i]) {
            P[++pcnt]= i;
            int res= 1, a= i, b= up;
            for(; b; b>>= 1, a= a * 1ll * a % mod)
                if(b & 1)
                    res= res * 1ll * a % mod;
            ik[i]= res;
            d[i]= k % i ? 1 : i;
        }
        for(int j= 1; j <= pcnt && i * P[j] <= n; j++) {
            x= i * P[j];
            notp[x]= 1;
            ik[x]= ik[i] * 1ll * ik[P[j]] % mod;
            if(i % P[j] == 0) {
                d[x]= d[i] * (k % (d[i] * P[j]) == 0 ? P[j] : 1);
                break;
            }
            d[x]= d[i] * d[P[j]];
        }
        res+= d[i] * 1ll * ik[i];
    }
    cout << int(res % mod);
}