    #include <bits/stdc++.h>
     
    using namespace std;
    using LL = long long;
     
    int l, r;
     
    int is_prime(int x)
    {
        for(int i = 2; i * i <= x; ++ i)
            if(x % i == 0)return i;
        return -1;
    }
     
    void solve()
    {
        cin >> l >> r;
     
        while(r >= l && is_prime(r) == -1)r --;
     
        if(r < l)cout << -1 << '\n';
        else
        {
            cout << is_prime(r) << ' ' << r - is_prime(r) << '\n';
        }
    }
     
    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int T;
        for (cin >> T; T -- ; )
            solve();
     
    }
