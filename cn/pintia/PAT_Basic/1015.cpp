#include "bits/stdc++.h"
#define MAXN 1000005
using namespace std;
struct student{
	int id;
	int de;
	int cai;
} a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int n,l,h,ai,bi,ci,di,cnt;
bool cmp(struct student a,struct student b){
	if((a.de+a.cai)!=(b.de+b.cai))
		return (a.de+a.cai)>(b.de+b.cai);
	else if(a.de!=b.de)
		return a.de>b.de;
	else
		return a.id<b.id;
}
int main(){
	cin>>n>>l>>h;
	while(n--){
		int id,de,cai;
		cin>>id>>de>>cai;
		if(de>=l&&cai>=l){
			cnt++;
			if(de>=h&&cai>=h){
				a[ai].id=id;
				a[ai].de=de;
				a[ai].cai=cai;
				ai++;
			}else if(de>=h&&cai<h){
				b[bi].id=id;
				b[bi].de=de;
				b[bi].cai=cai;
				bi++;
			}else if(de<h&&cai<h&&de>=cai){
				c[ci].id=id;
				c[ci].de=de;
				c[ci].cai=cai;
				ci++;
			}else{
				d[di].id=id;
				d[di].de=de;
				d[di].cai=cai;
				di++;
			}
		}
	}
	sort(a,a+ai,cmp);
	sort(b,b+bi,cmp);
	sort(c,c+ci,cmp);
	sort(d,d+di,cmp);
	cout<<cnt<<endl;
	for(int i=0;i<ai;i++)
		cout<<a[i].id<<' '<<a[i].de<<' '<<a[i].cai<<endl;
	for(int i=0;i<bi;i++)
		cout<<b[i].id<<' '<<b[i].de<<' '<<b[i].cai<<endl;
	for(int i=0;i<ci;i++)
		cout<<c[i].id<<' '<<c[i].de<<' '<<c[i].cai<<endl;
	for(int i=0;i<di;i++)
		cout<<d[i].id<<' '<<d[i].de<<' '<<d[i].cai<<endl;
	return 0;
}
