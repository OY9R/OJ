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
char s[200005];
void solve(){
	int n,m;cin>>n>>m;
    cin>>s+1;
    VI a(n+1);
    a[0]=0;
    int j=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            a[i]=a[i-1]+1;
            if(a[i]>1){
                j=i;
                break;
            }
        }else{
            a[i]=a[i-1]-1;
            if(a[i]<0){
                j=i;
                break;
            }
        }
    }
    while(m--){
        int ii;cin>>ii;
        if(s[ii]=='(')s[ii]=')';
        else s[ii]='(';
        if(ii<=j){
            j=-1;
            for(int i=ii;i<=n;i++){
                if(s[i]=='('){
                    a[i]=a[i-1]+1;
                    if(a[i]>1){
                        j=i;
                        break;
                    }
                }else{
                    a[i]=a[i-1]-1;
                    if(a[i]<0){
                        j=i;
                        break;
                    }
                }
            }
        }
        cout<<j<<' ';
        if(j>0&&a[j]>0||j==-1&&a[n]==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}