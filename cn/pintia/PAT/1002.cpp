#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int sum=0;
	char *num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
		sum+=str[i]-'0';
	int temp[100],j=0;
	while(sum!=0){
		temp[j++]=sum%10;
		sum/=10;
	}
	for(j--;j>=0;j--){
		printf("%s",num[temp[j]]);
		if(j!=0)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
