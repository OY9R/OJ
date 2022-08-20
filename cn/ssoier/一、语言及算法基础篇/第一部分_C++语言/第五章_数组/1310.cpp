#include<iostream>
#include<string> 
#include<cstdio>
using namespace std;
int main(){
	int n;
	int a[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
				count++;
			}
		}
	}
	cout<<count<<endl;

	return 0;
}