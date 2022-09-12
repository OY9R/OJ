#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0; i<len-1; i++) {
		for(int j=i+1; j<len; j++) {
			if(s[i]==s[j]&&i%2==j%2) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}