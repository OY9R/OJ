#include "bits/stdc++.h"
#define ll long long
using namespace std;
struct Student{
	string id;
	int t1,t2;
} students[1009];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int t1,t2;
		cin>>s>>t1>>t2;
		students[t1].id=s;
		students[t1].t1=t1;
		students[t1].t2=t2;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int tmp;
		cin>>tmp;
		cout<<students[tmp].id<<' '<<students[tmp].t2<<endl;
	}
	return 0;
}
