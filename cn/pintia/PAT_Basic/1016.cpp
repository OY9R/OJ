#include "bits/stdc++.h"
using namespace std;
long a,b,da,db,aa,bb;
int main(){
	cin>>a>>da>>b>>db;
	while(a){
		if(a%10==da)
			aa=aa*10+da;
		a/=10;
	}
	while(b){
		if(b%10==db)
			bb=bb*10+db;
		b/=10;
	}
	cout<<aa+bb<<endl;
}
