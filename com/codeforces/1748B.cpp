#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		string s;cin>>s;
		int ans=0;
		for(int i=0;i<n;i++){
			vector<int> a(10);
			int num=0,cnt=1;
			for(int j=i;j<n&&j<100+i;j++){
				if(a[s[j]-'0']++)
					cnt=max(cnt,a[s[j]-'0']);
				else num++;
				if(cnt<=num)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}