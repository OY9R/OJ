#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(101);
		for(int i=0;i<n;i++){
			int t;cin>>t;
			a[t]++;
		}
		int cnt=0;
		for(int i=0;i<=100;i++){
			if(a[i])cnt++;
		}
		if(cnt>2||n==1){
			cout<<n;
		}else{
			cout<<n/2+1;
		}
		cout<<endl;
	}
	return 0;
}