#include "bits/stdc++.h"
#define N 100005
using namespace std;
struct People{
	string name;
	int year;
	int month;
	int day;
}people[N];
const int days[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,
					   0,31,29,31,30,31,30,31,31,30,31,30,31};
int check(int tar){
	int flag=0;
	if(people[tar].year>2014
		|| people[tar].year==2014&&people[tar].month>9
		|| people[tar].year==2014&&people[tar].month==9&&people[tar].day>6
		|| people[tar].year<1814
		|| people[tar].year==1814&&people[tar].month<9
		|| people[tar].year==1814&&people[tar].month==9&&people[tar].day<6
		|| days[people[tar].year%4==0&&people[tar].year%100!=0
		|| people[tar].year%400==0][people[tar].month]<people[tar].day)
		return 0;
}
bool cmp(struct People a,struct People b)
{
	if(a.year!=b.year)
		return a.year<b.year;
	else if(a.month!=b.month)
		return a.month<b.month;
	else
		return a.day<b.day;
}
int main(){
	int n;
	cin>>n;
	int ans=n;
	for(int i=0;i<ans;i++){
		cin>>people[i].name;
		scanf("%d/%d/%d",&people[i].year,&people[i].month,&people[i].day);
		if(!check(i)){
			ans--;
			i--;
		}
	}
	sort(people,people+ans,cmp);
	cout<<ans;
	if(ans!=0)
		cout<<' '<<people[0].name<<' '<<people[ans-1].name<<endl;
	return 0;
}
