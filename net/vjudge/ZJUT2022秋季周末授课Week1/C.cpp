#include <bits/stdc++.h>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int main() {
	int res=0;
	for(int p : prime){
		cout<<p<<endl;
		fflush(stdout);
		string s;
		cin>>s;
		if(s=="yes")res++;
	}
	if(res>=2)
		cout<<"composite"<<endl;
	else
		cout<<"prime"<<endl;
	return 0;
}