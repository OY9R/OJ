#include "bits/stdc++.h"
using namespace std;
int main(){
	int num;
	scanf("%d",&num);
	int a,b,c;
	a=num%10;
	b=num/10%10;
	c=num/100;
	for(int i=0;i<c;i++)
		printf("B");
	for(int i=0;i<b;i++)
		printf("S");
	for(int i=0;i<a;i++)
		printf("%d",i+1);
	printf("\n");
	return 0;
} 
