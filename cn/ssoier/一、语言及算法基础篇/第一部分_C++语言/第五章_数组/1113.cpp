#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define N 105
int a[N];
int main(){
	int n;
	long max=-1000000,sum=0;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(max<a[i]) max=a[i];
	}
	for(int i=1;i<=n;i++)
		if(a[i]==max)sum+=0;
		else sum+=a[i];
	cout<<sum;
    return 0;
}