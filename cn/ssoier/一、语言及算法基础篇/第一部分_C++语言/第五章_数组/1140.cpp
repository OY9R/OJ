#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,x;
	cin>>s>>x;
	if(s.find(x)!=-1)cout<<x<<" is substring of "<<s<<endl;
	else if(x.find(s)!=-1)cout<<s<<" is substring of "<<x<<endl;
	else cout<<"No substring"<<endl;
 	return 0;
}