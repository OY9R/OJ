#include "bits/stdc++.h"
using namespace std;
int main(){
	string str;
	cin>>str;
	int flag2=1;
	int Etar=str.find('E');
	if(str[0]=='-')printf("-");
	string a=str.substr(1,Etar-1);
	if(str[Etar+1]=='-')
		flag2=-1;
	string b=str.substr(Etar+2);
	int y=0;
	int len=b.length();
	for(int i=0;i<len;i++)
		y=y*10+b[i]-'0';
	if(flag2==-1){
		printf("0.");
		y--;
		if(y==-1)
			printf("0");
		else{
			while(y--)
				printf("0");
			len=a.length();
			for(int i=0;i<len;i++)
				if(a[i]!='.')
					printf("%d",a[i]-'0');
		}
	}else{
		int tmp=2,flag=0;
		printf("%d",a[0]-'0');
		len=a.length();
		while(y--){
			printf("%d",a[tmp++]-'0');
			if(tmp==len){
				flag=1;
				break;
			}	
		}
		if(y!=-1)
			while(y--)
				printf("0");
		else
			printf(".0");
		if(flag!=1&&y!=-1){
			printf(".");
			for(int i=tmp;i<len;i++)
				printf("%d",a[i]-'0');
		}		
	}
	
	return 0;
} 
