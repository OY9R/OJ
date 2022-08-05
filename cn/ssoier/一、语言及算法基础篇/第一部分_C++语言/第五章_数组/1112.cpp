#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define M 10005
int a[M];
int main(){
	int m,min=10001,max=-10001;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	cout<<max-min;
    return 0;
}