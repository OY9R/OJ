#include<bits/stdc++.h>
using namespace std;
int m[100001];
int main() {
	int _;
	cin>>_;
	for(int t=1;t<=_;t++) {
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
		cout<<"#Case "<<t<<':'<<endl;
		for(int i=0;i<b.length();i++){
			cout<<m[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}