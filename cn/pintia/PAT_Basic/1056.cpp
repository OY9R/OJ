#include"bits/stdc++.h"
using namespace std;
int main(){
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		ans=ans+temp*10*(n-1)+temp*(n-1);
	}
	cout<<ans<<endl;
	return 0;
 } 