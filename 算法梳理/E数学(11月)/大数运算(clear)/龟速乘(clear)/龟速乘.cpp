long long quick_mul(long long x, long long y, long long mod) {
    long long ans = 0;
    while (y != 0) {
        if (y & 1)ans += x, ans %= mod;
        x = x + x, x %= mod;
        y >>= 1;
    }
    return ans;
}