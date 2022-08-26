#include "bits/stdc++.h"
#define ll long long
using namespace std;
double ans=0;
bool check(string str){
	double num=0,flag=1.0;
	int tar=-1;
	if(str[0]=='-'){
		flag*=-1;
		str.erase(0,1);
	}
	for(int i=0;i<str.length();i++){
		if(!isdigit(str[i])&&str[i]!='.')
			return false;
		if(str[i]=='.'&&tar!=-1)
			return false;
		if(i-tar>2&&tar!=-1)
			return false;	
		if(tar==-1&&str[i]!='.')
			num=num*10+str[i]-'0';
		else if(str[i]=='.'&&tar==-1)
			tar=i;
		else if(tar!=-1)
			num=num+1.0*(str[i]-'0')*pow(10,tar-i);
	}
	if(num>1000||num<-1000)
		return false;
	else{
		ans+=flag*num;
		return true;
	}
		
}
int main(){
	int n,cnt=0;
	double ssum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(check(str))
			cnt++;
		else
        	cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
	}
	if(cnt==0)
        cout<<"The average of 0 numbers is Undefined";
    else if(cnt==1)
        cout<<"The average of "<<cnt<<" number is "<<ans/cnt;
    else
        cout<<"The average of "<<cnt<<" numbers is "<<ans/cnt;
	return 0;
 } 
