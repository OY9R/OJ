#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, r;
    cin >> s;
    s.pop_back();
    r = s;
    reverse(r.begin(), r.end());
    cout << (s == r ? "Yes" : "No");
    return 0;
}