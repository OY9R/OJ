#include "bits/stdc++.h"
#define ll long long
#define N 10001
using namespace std;
struct Paper{
	string id;
	int price;
	int num;
}papers[N];
bool cmp1(struct Paper a,struct Paper b){
	return a.num>b.num;
}
bool cmp2(struct Paper a,struct Paper b){
	return a.num*a.price>b.num*b.price;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>papers[i].id>>papers[i].price>>papers[i].num;
	sort(papers+1,papers+n+1,cmp1);
	cout<<papers[1].id<<' '<<papers[1].num<<endl;
	sort(papers+1,papers+n+1,cmp2);
	cout<<papers[1].id<<' '<<papers[1].num*papers[1].price<<endl;
	return 0;
}
