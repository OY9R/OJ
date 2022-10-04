#include<bits/stdc++.h>
using namespace std;
int main() {
	int a;
	cin>>a;
	if(a%2)cout<<"0 0";
	else cout<<a/4+(a%4>0)<<' '<<a/2;
	return 0;
}