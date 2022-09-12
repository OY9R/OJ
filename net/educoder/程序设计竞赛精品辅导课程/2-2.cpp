#include<bits/stdc++.h>
using namespace std;
vector<string> m;
void f() {
	int len=m.size();
	for(int i=0; i<len; i++) {
		m.push_back(m[i]+m[i]);
		string s(len,' ');
		m[i]=s+m[i]+s;
	}
}
int main() {
	int n;
	cin>>n;
	if(n==0) {
		cout<<"/\\"<<endl;
		return 0;
	}
	m.push_back(" /\\ ");
	m.push_back("/__\\");
	while(--n)f();
	for(int i=0; i<m.size(); i++)
		cout<<m[i].substr(0,m[i].find_last_of("\\")+1)<<endl;
	return 0;
}