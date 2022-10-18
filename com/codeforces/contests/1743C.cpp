#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n;
		cin>>s;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++){
			if(s[i]=='0'){
				for(int j=i+1;j<n&&s[j]=='1';j++){
					if(a[i]>a[j]){
						s[i]='1',s[j]='0';
						i=j;
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1') ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}