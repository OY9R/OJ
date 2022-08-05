#include<bits/stdc++.h>
using namespace std;
double a[108],b,c,d,e,f;
int main(){
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		if(a[i]<=18&&a[i]>=0)c++;
		if(a[i]<=35&&a[i]>=19)d++;
		if(a[i]<=60&&a[i]>=36)e++;
		if(a[i]>=61)f++;
	}
	cout<<fixed<<setprecision(2)<<c/b*100<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<d/b*100<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<e/b*100<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<f/b*100<<"%"<<endl;
	return 0; 
}