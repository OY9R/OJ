#include<bits/stdc++.h>
using namespace std;
int M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
	int y,m,d;
	cin>>y>>m>>d;
	if((y%4==0&&y%100!=0)||y%400==0){
		M[2]=29;
	}
	if(d==M[m]){
		if(m==12)cout<<y+1<<" 1 1\n";
		else cout<<y<<' '<<m+1<<" 1\n";
	}else cout<<y<<' '<<m<<' '<<d+1<<'\n';
	return 0;
}