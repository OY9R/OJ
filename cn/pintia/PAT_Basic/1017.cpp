#include "bits/stdc++.h"
using namespace std;
int main(){
	string s;
	int n,t=0;
	cin>>s>>n;
	if(s.length()==1&&s[0]-'0'<n){
		cout<<"0 "<<s[0]-'0'<<endl;
		return 0;
	}
	for(int i=0;i<s.length();i++){
		int tmp=t*10+s[i]-'0';
		s[i]=tmp/n+'0';
		t=tmp%n;
	}
	int i=0;
	while(s[i]=='0')i++;
	cout<<&s[i]<<' '<<t<<endl;
	return 0;
}
