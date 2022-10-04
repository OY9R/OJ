#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,b;
	char c;
	cin>>a>>b;
	do cin>>c;
	while(c==' ');
	switch(c){
		case '-':
			b=-b;
		case '+':
			cout<<a+b;
			break;
		case '*':
			cout<<a*b;
			break;
		case '/':
			if(b==0)cout<<"Divided by zero!";
			else cout<<a/b;
			break;
		default:
			cout<<"Invalid operator!";
	}
	return 0;
}