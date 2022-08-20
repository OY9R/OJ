#include "bits/stdc++.h"
using namespace std;
#define ll long long
int ans[1009];
int main() {
	string a,b;
	cin>>a>>b;
	if(a.length()<b.length()){
		string tmp;
		tmp=a;a=b;b=tmp;
	}
	for(int i=0;i<b.length();i++){
		if(b[i]=='0')continue;
		for(int j=0;j<a.length();j++){
			ans[i+j+100]+=(b[i]-'0')*(a[j]-'0');
			for(int k=0;ans[i+j+100-k]>=10;k++){
				ans[i+j+100-k-1]+=ans[i+j+100-k]/10;
				ans[i+j+100-k]%=10;
			}
		}
	}
	int j=0;
	while(ans[++j]==0);
	for(;j<b.length()+a.length()+99;j++){
		cout<<ans[j];
	}
	cout<<endl;
	return 0;
}