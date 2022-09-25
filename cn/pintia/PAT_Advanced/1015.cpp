#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime(int n) {
	if(n<2)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i=3; i<=sqrt(n); i+=2)
		if(n%i==0)return false;
	return true;
}
void iitoa(int n,char* s,int d){
	int i=1,j=0;
	while(i<=n)i*=d;
	while(i>1){
		i/=d;
		s[j++]=n/i+'0';
		n%=i;
	}
	s[j]='\0';
}
int main() {
	int n,d;
	char s[100];
	while(cin>>n>>d&&n>=0){
		if(isPrime(n)){
			iitoa(n,s,d);
			reverse(s,s+strlen(s));
			int rn=stoi(s,0,d);
			if(isPrime(rn))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}else
			cout<<"No"<<endl;
	}
	return 0;
}