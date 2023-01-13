#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    reverse(all(a));
    if(a[0]==a[1]){
        int i=2;
        while(i<n&&a[i]==a[0])i++;
        if(i==n){
            cout<<"NO\n";
            return;
        }
        swap(a[i],a[0]);
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}