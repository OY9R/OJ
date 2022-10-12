#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<long long> b(n+1);
		b[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]+b[i-1];
		}
		int tmin=INT_MAX;
		for(int i=1;i<=n;i++){
			if(b[n]%b[i]==0){
				int tmax=i;
				int l=i;
				bool flag=true;
				for(long long j=b[i]+b[i];j<=b[n];j+=b[i]){
					int f=find(b.begin(),b.end(),j)-b.begin();
					tmax=max(tmax,f-l);
					//cout<<f<<',';
					l=f;
					if(f>n){
						//cout<<'!';
						flag=false;
						break;
					}
				}
				if(flag){
					tmin=min(tmin,tmax);
				}
			}
		}
		cout<<tmin<<endl;
	}
	return 0;
}
