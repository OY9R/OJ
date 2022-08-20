#include<bits/stdc++.h>
using namespace std;
double fun(int n,double x){
	if(n==0)return 1;
	else if(n==1)return 2*x;
	else return 2*x*fun(n-1,x)-2*(n-1)*fun(n-2,x);
}
int main(){
	double x;
	int n;
	cin>>n>>x;
	printf("%.2f",fun(n,x));
 	return 0;
}