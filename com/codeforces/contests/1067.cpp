#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
	string pd,s;
	int num;
	cin>>pd>>num;
	getchar();
	while(true){
		getline(cin,s);
		if(s=="#")
			break;
		else if(s==pd){
			printf("Welcome in\n");
			break;
		}else{
			cout<<"Wrong password: "<<s<<endl;
			num--;
		}
		if(num==0){
			printf("Account locked\n");
			break;
		}
	}
	return 0;
 } 
