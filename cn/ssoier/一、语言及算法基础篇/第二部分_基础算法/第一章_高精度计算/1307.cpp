#include "bits/stdc++.h"
using namespace std;
#define ll long long
int ans[1009];
//string mul(string a,string b){
//	for(int i=b.length()-1;i>=0;i--){
//		for(int j=a.length()-1;j>=0;j--){
//			int k=b.length()+a.length()-i-j-2;
//			c[k]+=(a[j]-'0')*(b[i]-'0');
//		}
//	}
//	for(int i=0;i<100;i++){
//		c[i+1]+=c[i]/10;
//		c[i]=c[i]%10+'0';
//	}
//	int n=100;
//	while(c[--n]=='0');
//	string ss;
//	ss+=(char)c[n];
//	while(n--)ss+=(char)c[n];
//	return ss;
//}
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
