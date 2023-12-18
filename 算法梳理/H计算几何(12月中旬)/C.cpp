//#define _CRT_SECURE_NO_WARNINGS 1;
//https://ac.nowcoder.com/acm/contest/57358/C?&headNav=acm
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll inff = 1e18;
ll n, w[N], ans,bas;
double x[N], y[N], dis[N];
double r, r2, R, bx, by;
double pi = acos(-1);
bool se[N];
double combang(double x)
{
    while (x > pi * 2)x -= pi * 2;
    while (x < 0)x += pi * 2;
    return x;
}
inline double getdis(int a, int b){return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));}
inline double getanglein3(double a, double b, double c){return acos((a * a + b * b - c * c) / (a * b * 2));}
double getanglerela(int a, int b)//a from b
{
    double dx = x[a] - x[b], dy = y[a] - y[b];
    if (std::abs(dy) < 0.5)return pi * (dx < 0);
    if (std::abs(dx) < 0.5)return pi * (dy < 0) + pi / 2;
    double ang = combang(atan(dy / dx));
    if (dy < 0 && ang < pi)ang += pi; if (dy > 0 && ang > pi)ang -= pi;
    return ang;
}
void getO()
{
    ll Om=-inff;
    vector<pair<double, int> >events; x[n + 1] = x[0]+r; y[n + 1] = y[0]; ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = getdis(i, 0);
        if (dis[i]<r - R || dis[i]>r + R)continue;
        if (dis[i] < R - r) { sum += w[i]; continue; }
        double ang = getanglein3(r, dis[i], R);
        double f0ang = getanglerela(i, 0);
        events.push_back({ combang(f0ang + ang),i });
        events.push_back({ combang(f0ang - ang),i });
        se[i] = (getdis(i, n + 1) < R); if (se[i])sum += w[i];
    }
    Om = std::max(Om, sum); sort(events.begin(), events.end());
    for (auto k : events)
    {
        int nowd = k.second;
        se[nowd] ^= 1, sum += w[nowd] * (2 * se[nowd] - 1);
        Om = std::max(Om, sum);
    }
    ans = std::max(Om, ans);
}
void getA(int np)
{
    ll Am=-inff;
    dis[np] = getdis(np, 0); if (dis[np] > r + R || dis[np] < R - r)return;
    x[n + 1] = x[np] + R; y[n + 1] = y[np];
    se[np] = (getdis(n + 1, 0) <= r);
    vector<pair<double, int> >events; ll sum = std::max(w[np], 0ll);
    if (dis[np] > r - R)
    {
        double bsang = getanglerela(0, np);
        double ang = getanglein3(dis[np], R, r);
        events.push_back({ combang(bsang + ang),np });
        events.push_back({ combang(bsang - ang),np });
    }
    for (int i = 1; i <= n; i++)if (i != np)
    {
        dis[i] = getdis(i, np); if (dis[i] > R * 2)continue;
        double ang = getanglein3(dis[i], R, R);
        double f0ang = getanglerela(i, np);
        events.push_back({ combang(f0ang + ang),i });
        events.push_back({ combang(f0ang - ang),i });
        se[i] = (getdis(i, n + 1) < R); if (se[i])sum += w[i];
    }
    if (se[np])Am = std::max(Am, sum); sort(events.begin(), events.end());
    for (auto k : events)
    {
        int nowd = k.second;
        se[nowd] ^= 1; if (nowd != np)sum += w[nowd] * (2 * se[nowd] - 1);
        if (se[np])Am = std::max(Am, sum);
    }
    ans = std::max(Am, ans);
}
void solve()
{
    ans = -inff;
    cin >> n >> r >> r2 >> R >> x[0] >> y[0];
    r += r2;R+=1e-12;
    for (int i = 1; i <= n; i++)cin >> w[i];
    for (int i = 1; i <= n; i++)cin >> x[i] >> y[i];
    getO(); for (int i = 1; i <= n; i++)getA(i);
    cout << ans<< '\n';
}
int main()
{
    //freopen("11.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--)solve();
}