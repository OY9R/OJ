#include "bits/stdc++.h"
using namespace std;
int num[1005];
int main(){
	int n,temp=1,a1=0,a2=0,a3=0,ia4=0,a5=-1,f1=0,f2=0,f3=0,f4=0,f5=0;
	double a4=0.0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]%10==0){
			a1+=num[i];
			f1=1; 
		}
		if(num[i]%5==1){
			a2+=(num[i]*temp);
			temp*=-1;
			f2=1;
		}
		if(num[i]%5==2){
			a3++;
			f3=1;
		}
		if(num[i]%5==3){
			a4+=num[i];
			ia4++;
			f4=1;
		} 
		if(num[i]%5==4){
			a5=max(a5,num[i]);
			f5=1;
		}	
	}
	a4/=ia4;
	if(f1==0)cout<<"N ";
	else cout<<a1<<' ';
	if(f2==0)cout<<"N ";
	else cout<<a2<<' ';
	if(f3==0)cout<<"N ";
	else cout<<a3<<' ';
	if(f4==0)cout<<"N ";
	else printf("%.1lf ",a4);
	if(f5==0)cout<<"N"<<endl;
	else cout<<a5<<endl;
	return 0;
} 
