#include<iostream>
using namespace std;
int num[300];
int main(){
	char c;
	for(int i=0;i<2;i++){
		while((c=getchar())!='\n'){
			if(num[c]==0){
				num[c]=1;
				cout<<c;
			}
        }	
	}
	return 0;
}