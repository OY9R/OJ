#include<bits/stdc++.h>
using namespace std;
int main(){
    int g,p,t;cin>>g>>p>>t;
	int a=g+p*t,b=g*p;
	cout<<(a==b?0:a>b?1:2);
}