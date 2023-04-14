#include<bits/stdc++.h>
using namespace std;
int main(){
	long long r=0,b=0,t;
    for(int i=0;i<5;i++)cin>>t,b+=t;
    for(int i=0;i<5;i++)cin>>t,r+=t;
    if(b>=r)cout<<"Blue"<<endl;
    else cout<<"Red"<<endl;
	return 0;
}