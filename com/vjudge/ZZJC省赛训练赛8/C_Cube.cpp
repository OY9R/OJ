#include <bits/stdc++.h>
#define _for(i, a) for(int i = 0, le = (a); i < le; ++i)
#define _rep(i, a, b) for(int i = (a), le = (b); i <= le; ++i)
typedef long long LL;
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

LL read() {
    LL x(0), f(1); char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct poi {
    int x, y, z;
    poi(){}
    poi(int x, int y, int z):x(x), y(y), z(z) {}
    void sc() {
        x = read(), y = read(), z = read();
    }
    bool operator<(const poi b) const {
        if(x != b.x) return x < b.x;
        if(y != b.y) return y < b.y;
        if(z != b.z) return z < b.z;
        return 0;
    }
};

int T;
vector<poi> a;

LL getDis(poi a, poi b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

int sol() {
    _for(i, 8) _for(j, i) if(!(a[i] < a[j]) && !(a[j] < a[i])) return 0;
    vector<LL> diss;
    _for(i, 8) _for(j, i) diss.push_back(getDis(a[i], a[j]));
    sort(diss.begin(), diss.end());
    _for(i, 12) _for(j, i) if(diss[i] != diss[j]) return 0;
    _for(i, 12) _for(j, i) if(diss[12 + i] != diss[12 + j]) return 0;
    _for(i, 4) _for(j, i) if(diss[24 + i] != diss[24 + j]) return 0;
    if(diss[0] + diss[12] != diss[24]) return 0;
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    _for(i, T) {
        a.resize(8);
        _for(i, 8) a[i].sc();
        printf("%s\n", sol() ? "YES":"NO");
    }
    return 0;
}