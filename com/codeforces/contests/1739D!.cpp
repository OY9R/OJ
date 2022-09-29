#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100100;
int tree[N];
bool check(int n){
	//?
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=2;i<=n;i++){
			cin>>tree[i];
		}
		int l=1,r=N,ans;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else r=mid-1;
		}
		cout<<ans<<endl;
	}
    return 0;
}
