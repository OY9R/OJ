#include "bits/stdc++.h"
using namespace std;
int num[105];
int main(){
	long long int a,b,c;
	int d;
	cin>>a>>b>>d;
	c=a+b;
	int i=0;
	do{
		num[i++]=c%d;
		c/=d;
	}while(c!=0);
	for(int j=i-1;j>=0;j--)
		printf("%d",num[j]);
	return 0;	
}

