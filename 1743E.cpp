#include<bits/stdc++.h>
using namespace std;
int p1,t1,p2,t2,h,s;
int damage1(int t){
	return p1*(t/t1)+p1*(t/t2);
}
int damage2(int t){
	if(t1>t2){
		int tt=t1/t2;
		return p1*(t/t1)+p2*(t/t1)*tt+p2*(t%t1/t2);
	}else{
		int tt=t2/t1;
		return p2*(t/t2)+p1*(t/t2)*tt+p1*(t%t2/t1);
	}
}
int main(){
	cin>>p1>>t1>>p2>>t2>>h>>s;

	cout<<damage1(20)<<' '<<damage2(20)<<endl;
	return 0;
}