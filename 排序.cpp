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
	string s;cin>>s;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==0)continue;
        if(s[i]=='0'){
            s[i]=0;
            ans+='0';
            continue;
        }
        if(s[i]=='9'){
            for(int j=i+1;j<n;j++){
                if(s[j]==0||s[j]=='9'||s[j]=='1');
                else if(s[j]=='0'){
                    s[j]=0;
                    ans+='0';
                }else break;
            }
            for(int j=i+1;j<n;j++){
                if(s[j]==0||s[j]=='7'||s[j]=='9');
                else if(s[j]=='8'){
                    s[j]=0;
                    ans+='8';
                }else break;
            }
            for(int j=i+1;j<n;j++){
                if(s[j]==0||s[j]=='9');
                else if(s[j]=='8'||s[j]=='0'){
                    ans+=s[j];
                    s[j]=0;
                }else break;
            }
            ans+=s[i];
        }else{
            char sm=s[i]-1;
            char smd1=sm=='0'?'9':sm-1;
            for(int j=i+1;j<n;j++){
                if(s[j]==0||s[j]==smd1||s[j]==s[i]);
                else if(s[j]==sm){
                    s[j]=0;
                    ans+=sm;
                }else break;
            }
            ans+=s[i];
        }
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}