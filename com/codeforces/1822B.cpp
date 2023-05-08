#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n;cin>>n;
    VL a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    ll max1=0,max2=0,min1=0,min2=0;
    for(int i=1;i<=n;i++){
        max1=a[max1]<a[i]?i:max1;
        min1=a[min1]>a[i]?i:min1;
    }
    for(int i=1;i<=n;i++){
        if(i!=max1&&a[max2]<a[i])max2=i;
        if(i!=min1&&a[min2]>a[i])min2=i;
    }
    cout<<max(a[max1]*a[max2],a[min1]*a[min2])<<endl;
}
void solve2(){
    int n;cin>>n;
    VL a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    cout<<max(a[0]*a[1],a[n-1]*a[n-2])<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve2();
    return 0;
}