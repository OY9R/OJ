#include "bits/stdc++.h"
#define ll long long
using namespace std;
struct Student{
	string name;
	int height;
}students[10005];
bool cmp(struct Student p1,struct Student p2){
	if(p1.height!=p2.height)
		return p1.height>p2.height;
	else
		return p1.name<p2.name;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>students[i].name>>students[i].height;
	int len=n/k;
	int last=len+n%k;
	sort(students,students+n,cmp);
	for(int i=0;i<k;i++){
		if(i==0&&n%k){
			for(int j=last-1;j>0;j-=2)
				cout<<students[j].name<<' ';
			for(int j=0;j<last;j+=2){
				cout<<students[j].name;
				if(j!=last-2)
					cout<<' ';
			}
			cout<<endl;
		}else{
			if(len%2==1){
				for(int j=last+i*len-2;j>last+(i-1)*len;j-=2)
					cout<<students[j].name<<' ';
				for(int j=last+(i-1)*len;j<last+i*len;j+=2){
					if(j!=last+(i-1)*len)
						cout<<' ';
					cout<<students[j].name;
				}
				cout<<endl;
			}else{
				for(int j=last+i*len-1;j>last+(i-1)*len;j-=2)
					cout<<students[j].name<<' ';
				for(int j=last+(i-1)*len;j<last+i*len;j+=2){
					if(j!=last+(i-1)*len)
						cout<<' ';
					cout<<students[j].name;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
