#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int m[N];
int main() {
	int a=1,b=1,c=0;
	cout<<"? 1 2000"<<endl;
	cin>>c;
	do{
		b=max(c+1,b+1);
		cout<<"? "<<a<<' '<<b<<endl;
		cin>>c;
	}while(c!=-1);
	cout<<"! "<<b-1<<endl;
	return 0;
}
