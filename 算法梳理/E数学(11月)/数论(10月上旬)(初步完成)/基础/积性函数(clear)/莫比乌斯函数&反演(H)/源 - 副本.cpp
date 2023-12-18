https://codeforces.com/contest/1845/problem/F
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 524288, N1 = 2e5, N2 = 4e5 + 10, M = 998244353, M2 = 1e9 + 7;
ll l, t, ans;
int n, st;
ll a[N], b[N], c[2][N], d[2][N], e[N];
int p[N + 5], buf[N];
bool se[N2], fcov[N2 + 5];
int getbuf(int x, int cnt)
{
	int ans = 0;
	while (cnt--)ans = ans * 2 + (x & 1), x >>= 1;
	return ans;
}
ll poww(ll bs, ll x)
{
	ll ans = 1;
	while (x)
	{
		if (x & 1)ans = ans * bs % M;
		bs = bs * bs % M; x >>= 1;
	}
	return ans;
}
void NTT(int siz)//998244352 max 2^23
{
	int bs = 1, layy = 1, iv2 = (M + 1) / 2;
	while (bs < siz)bs *= 2, layy++; bool se;
	p[0] = 1; p[1] = poww(3, (M - 1) >> (layy - 1));
	for (int i = 2; i <= bs; i++)p[i] = 1ll * p[i - 1] * p[1] % M;
	for (int i = 0; i < siz; i++)buf[i] = getbuf(i, layy - 1);
	//
	for (int i = 0; i < bs; i++)c[0][i] = a[i];
	for (int i = 1, div = bs / 2; i < layy; div >>= 1, i++)
	{
		se = i & 1;
		for (int j = 0; j < bs; j += 2 * div)for (int k = j; k < j + div; k++)
		{
			c[se][k] = (c[se ^ 1][k] + c[se ^ 1][k + div] * p[buf[k >> (layy - i - 1)]] % M) % M;
			c[se][k + div] = (c[se ^ 1][k] + c[se ^ 1][k + div] * (M - p[buf[k >> (layy - i - 1)]]) % M) % M;
		}
	}
	for (int i = 0; i < bs; i++)d[0][i] = c[se][i];
	//
	for (int i = 0; i < bs; i++)c[0][i] = b[i];
	for (int i = 1, div = bs / 2; i < layy; div >>= 1, i++)
	{
		se = i & 1;
		for (int j = 0; j < bs; j += 2 * div)for (int k = j; k < j + div; k++)
		{
			c[se][k] = (c[se ^ 1][k] + c[se ^ 1][k + div] * p[buf[k >> (layy - i - 1)]] % M) % M;
			c[se][k + div] = (c[se ^ 1][k] + c[se ^ 1][k + div] * (M - p[buf[k >> (layy - i - 1)]]) % M) % M;
		}
	}
	for (int i = 0; i < bs; i++)d[0][i] = d[0][i] * c[se][i] % M;
	//
	for (int i = 1, div = 1; i < layy; div <<= 1, i++)
	{
		se = i & 1;
		for (int j = 0; j < bs; j += 2 * div)for (int k = j; k < j + div; k++)
		{
			d[se][k] = (d[se ^ 1][k] + d[se ^ 1][k + div]) * iv2 % M;
			d[se][k + div] = ((d[se ^ 1][k] - d[se ^ 1][k + div] + M) % M) * iv2 % M * p[bs - buf[k >> (i - 1)]] % M;
		}
	}
	for (int i = 0; i < bs; i++)e[i] = d[se][i];
}
vector<int>pris, pd[N];
int mind[N2 + 5], mob[N2 + 5];
int tim[N2], tc;
ll mobc(int x)
{
	ll c = t * x / 2 / l, ac = 0; tc++;
	queue<int>Q; Q.push(x);
	while (!Q.empty())
	{
		st = Q.front(); Q.pop();
		ac = (ac + c / st * mob[st] + M2) % M2;
		for (auto k : pd[st])if (tim[st / k] != tc)
			tim[st / k] = tc, Q.push(st / k);
	}
	//cout << x << 'c'<<c<<'f' << ac << '\n';
	return ac;
}
void getpriinfo()
{
	bool jud;
	for (int i = 2; i <= N2; i++)
	{
		if (!mind[i])mind[i] = i, pris.push_back(i);
		pd[i] = pd[i / mind[i]];
		if (pd[i].empty() || pd[i].back() != mind[i])
			pd[i].push_back(mind[i]);
		for (auto k : pris)
		{
			if (i * k > N2)break;
			mind[i * k] = k;
			if (mind[i] == k)break;
		}
	}
	for (int i = 1; i <= N2; i++)
	{
		int bs = 1, c = 1; for (auto k : pd[i])bs *= k, c *= -1;
		bs == i ? mob[i] = c : mob[i] = 0;
	}
}
void solve()
{
	cin >> l >> t >> n; for (int i = 1; i <= n; i++)cin >> st, se[st] = 1;
	for (int i = 0; i <= N1; i++)a[i] = b[i] = se[i + 1]; NTT(N);//e[i]:a+b-2¼¯
	for (int i = 0; i < N2; i++)if (e[i])if (!(i % 2 == 0 && e[i] == 1 && se[i / 2 + 1])) fcov[i + 2] = 1;
	for (int i = 0; i <= N1; i++)a[i] = se[i + 1], b[i] = se[N1 + 1 - i]; NTT(N);//e[i]:a-b+N1¼¯
	for (int i = N1 + 1; i < N2; i++)if (e[i])fcov[i - N1] = 1;
	//for (int i = 1; i < N2; i++)if (fcov[i])cout << i << "!"; cout << '\n';
	for (int i = N2; i; i--)if (fcov[i]) { ans += mobc(i); for (auto k : pd[i])fcov[i / k] = 1; }
	cout << ans % M2 << '\n';
	//for (int i = 1; i < N2; i++)if (fcov[i])cout << i << "!"; cout << '\n';
}
int main()
{
	getpriinfo();
	int t = 1; //cin >>t;
	while (t--)solve();
}