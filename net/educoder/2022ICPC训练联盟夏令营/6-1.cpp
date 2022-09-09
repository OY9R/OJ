#include<bits/stdc++.h>
using namespace std;
const int N=10001;
char ss[N];
int sl,sr;
int main() {
	int n,d;
	char m;
	cin>>n>>d;
	for(int i=0; i<=d; i++) {
		cin>>m;
		while(sr!=0&&ss[sr-1]<m)sr--;
		ss[sr++]=m;
	}
	for(sl=1; sl<n-d; sl++) {
		cin>>m;
		while(sr!=sl&&ss[sr-1]<m)sr--;
		ss[sr++]=m;
	}
	ss[n-d]='\0';
	cout<<ss;
	return 0;
}