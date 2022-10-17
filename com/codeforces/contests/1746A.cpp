#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int m=0;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			if(t==1)m++;
		}
		if(m==n||(m>0&&k<=n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}