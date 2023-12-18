//https://www.luogu.com.cn/problem/P5410
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e7 + 10;
int nxt[N], ext[N];
void kmp(char* c)
{
	int len = strlen(c), mx = 0, k = 1; nxt[0] = len;
	for (int i = 1; i < len; i++)
	{
		nxt[i] = std::min(nxt[i - k], std::max(mx - i + 1, 0));
		while (i + nxt[i] < len && c[i + nxt[i]] == c[nxt[i]]) nxt[i]++;
		if (i + nxt[i] > mx)k = i, mx = k + nxt[k] - 1;
	}
	
}
void kmp2(char* c)
{
	int len = strlen(c), mx = 0, k = 1; nxt[1] = len;
	for (int i = 2; i <= len; i++)
	{
		nxt[i] = std::min(nxt[i - k], std::max(mx - i + 1, 0));
		while (i + nxt[i] <= len && c[i + nxt[i]-1] == c[nxt[i]-1]) nxt[i]++;
		if (i + nxt[i] > mx)k = i, mx = k + nxt[k] - 1;
	}
	for (int i = 0; i < len; i++)nxt[i] = nxt[i + 1];
}
void exkmp(char* a, char* b)
{
	int la = strlen(a), lb = strlen(b), mx = -1, k = 0;
	for (int i = 0; i < la; i++)
	{		
		ext[i] = std::min(nxt[i - k], std::max(mx - i + 1, 0));
		while (i + ext[i] < la && ext[i] < lb && a[i + ext[i]] == b[ext[i]]) ext[i]++;
		if (i + ext[i] > mx)k = i, mx = k + ext[k] - 1;
	}
}
int la, lb;
char a[N], b[N];
ll ans;
void solve()
{
	cin >> a >> b;
	kmp(b); for (int i = 0; i < lb; i++)cout << nxt[i] << "*"; cout << "\n";
	kmp2(b); for (int i = 0; i < lb; i++)cout << nxt[i] << "*"; cout << "\n";
	kmp2(b); exkmp(a, b); la = strlen(a), lb = strlen(b);
	ans = 0;for (int i = 0; i < lb; i++) ans ^= 1ll*(i + 1) * (nxt[i] + 1),cout<<nxt[i]<<"*"; cout << ans << "\n";
	ans = 0;for (int i = 0; i < la; i++)ans ^= 1ll*(i + 1) * (ext[i] + 1), cout << ext[i] << "*"; cout << ans << "\n";
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int t = 1; //cin >> t;
	while (t--)solve();
}