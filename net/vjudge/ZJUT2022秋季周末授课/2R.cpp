#include <bits/stdc++.h>
#define int long long
using namespace std;
int Atoi(string s,int radix) {
	int ans=0;
	for(int i=0; i<s.size(); i++) {
		char t=s[i];
		if(t>='0'&&t<='9') {
			if(t - '0' >= radix) return -1;
			ans = ans * radix + 1ll * (t-'0');
		} else {
			if(1ll * (t - 'A' + 10) >= radix) return -1;
			ans = ans * radix + 1ll * (t - 'A' + 10);
		}
	}
	return ans;
}
bool calc(int a, int b, int c, char opt) {
	if(opt == '+')
		return a + b == c;
	else if(opt == '-')
		return a - b == c;
	else if(opt == '*')
		return a * b == c;
	else {
		if(b == 0) return -1;
		return a % b == 0 && a == b * c;
	}
}
signed main() {
	string s;
	while(cin >> s) {
		int opt = -1, eq = -1;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z') continue;
			if(opt == -1) opt = i;
			else eq = i;
		}
		string a = s.substr(0, opt);
		string b = s.substr(opt + 1, eq - opt - 1);
		string c = s.substr(eq + 1);
		bool flag = 0;
		for(int i = 2; i <= 16; i++) {
			int aa = Atoi(a, i), bb = Atoi(b, i), cc= Atoi(c, i);
			if(aa == -1 || bb == -1 || cc == -1) continue;
			if(calc(aa, bb, cc, s[opt])) {
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << -1 << endl;
	}
}