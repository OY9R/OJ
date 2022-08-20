#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
 
using namespace std;
 
const int inf = 0x3f3f3f3f;
int res;
int minn = inf;
 
int main() {
 
    string s, a;
    cin >> s;
    getchar();
    getline(cin, a);
    
    for(int i = 0; i < a.size(); i ++) {
        int j = 0;
        if(a[i] == s[0] || a[i] == (s[0] - 32) || a[i] == (s[0] + 32)) {
            for(j = 0; j < s.size(); j ++) {
                if(a[i + j] == (s[j] + 32) || a[i + j] == (s[j] - 32) || a[i + j] == s[j]) {
                    continue;
                } else break;
            }
            if(j == s.size() && (a[i - 1] == ' ' || i == 0) && (a[i + j] == ' ' || (i + j - 1) == (a.size() - 1))) {
                res ++;
                minn = min(minn, i);
            }
        }
    }
    
    if(res)
    cout << res << " " << minn;
    else 
    cout << -1;
 
    return 0;
}