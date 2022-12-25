#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int ans;
int main() {
    string s;cin>>s;
    char c=s[0];
    for(int i=1;i<s.size();i++)
        if(s[i]!=c)ans++,c=s[i];
    cout<<ans;
    return 0;
}