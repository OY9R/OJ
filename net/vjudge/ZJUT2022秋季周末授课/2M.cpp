#include<bits/stdc++.h>
using namespace std;
int m[100001];
int main() {
	int t;
	cin>>t;
	while(t--) {
		string a,b;
		cin>>a;
		cin>>b;
		memset(m,0,sizeof m);
		for(int i=0;i<a.length();i++){
			for(int j=0;j<b.length();j++){
				if(a[i+j]==b[j])m[j]+=i+1;
				else break;
			}
		}
		for(int i=0;i<b.length();i++){
			cout<<m[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}