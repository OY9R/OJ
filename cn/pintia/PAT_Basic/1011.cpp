#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int t=1;t<=n;t++){
		long a,b,c;
		cin>>a>>b>>c;
		cout<<"Case #"<<t<<": ";
		if(a+b>c)cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
	return 0;
}
