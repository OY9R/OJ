#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve(){
	int n;cin>>n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++)a[i].second=i;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        s='%'+s;
        for(int j=1;j<=n;j++)
            if(s[j]=='o')a[i].first--;
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++)cout<<a[i].second<<' ';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}