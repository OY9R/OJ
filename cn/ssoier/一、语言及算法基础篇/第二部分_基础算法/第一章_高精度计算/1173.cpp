#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void addup(string &a,string b){
	if(a.length()<b.length()){
		string t=a;
		a=b;
		b=t;
	}
	int i=a.length()-1;
	int j=b.length()-1;
	int t=0;
	for(;i>=0;i--,j--){
		if(j>=0)t+=b[j]-'0';
		t+=a[i]-'0';
		a[i]=t%10+'0';
		t/=10;
	}
	string tmp;
	if(t>0)a=(char)(t+'0')+a;
}
int main() {
	string a;
	string b;
	cin>>a>>b;
	addup(a,b);
	cout<<a;
	return 0;
}
