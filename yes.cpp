#include <bits/stdc++.h>
using namespace std;
int n;
regex r("(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]):(\\d|[1-9]\\d{1,3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])");
map<string, int> m;
string o, a;
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> o >> a;
    if (!regex_match(a, r)) { cout << "ERR\n"; continue; }
    if (o[0] == 'S') {
      if (m[a]) cout << "FAIL\n";
      else m[a] = i, cout << "OK\n";
    } else {
      if (!m.count(a)) cout << "FAIL\n";
      else cout << m[a] << '\n';
    }
  }
  return 0;
}