#include<bits/stdc++.h>
using namespace std;
double m[10];
int main() {
	for(int i=0; i<10; i++)
		cin>>m[i];
	double sum=0;
	for(int i=0; i<10; i++)
		sum+=m[i];
	double avg=sum/10;
	sum=0;
	for(int i=0; i<10; i++)
		sum+=(m[i]-avg)*(m[i]-avg);
	if(sqrt(sum/9)>1.0)
		cout<<"NOT COMFY";
	else
		cout<<"COMFY";
	cout<<endl;
	return 0;
}