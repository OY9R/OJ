#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s="2019";
	for(int i=4;i<n;i++)
		s+=(s[i-1]-'0'+s[i-2]-'0'+s[i-3]-'0'+s[i-4]-'0')%10+'0';
	if(n==1)
		cout<<"2"<<endl;
	else if(n==2)
		cout<<"20"<<endl;
	else if(n==3)
		cout<<"201"<<endl;
	else
		cout<<s<<endl;
	return 0;
}