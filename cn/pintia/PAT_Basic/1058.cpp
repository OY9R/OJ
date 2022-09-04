#include"bits/stdc++.h"
using namespace std;
int n,m;
struct Problem{
	int id;
	int grade;
	int all;
	int right;
	int a[6];
	int cnt;
}problems[1005];
int fun(string str,int n){
	int num=str[1]-'0';
	if(num!=problems[n].right)
		return 0;
	int cnt=0;
	for(int i=2;i<str.length();i++)
		if(str[i]>='a'&&str[i]<='z'&&problems[n].a[str[i]-'a']==1)
			cnt++;
	if(num==cnt){
		problems[n].cnt++;
		return 1;
	}
	return 0;
}
bool cmp(struct Problem a,struct Problem b){
	if(a.cnt!=b.cnt)
		return a.cnt<b.cnt;
	return a.id<b.id;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&problems[i].grade,&problems[i].all,&problems[i].right);
		getchar();
		problems[i].cnt=0;
		problems[i].id=i+1;
		for(int j=0;j<problems[i].right;j++){
			char temp;
			scanf("%c",&temp);
			problems[i].a[temp-'a']++;
			getchar();
		}
	}
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		int left,cnt=0,goal=0;
		for(int j=0;j<str.length();j++){
			if(str[j]=='(')
				left=j;
			if(str[j]==')'){
				int temp=fun(str.substr(left,j-left),cnt);
				if(temp==1)
					goal+=problems[cnt].grade;
				cnt++;
			}		
		}
		printf("%d\n",goal);
	}
	sort(problems,problems+m,cmp);
	if(problems[0].cnt==n)
		printf("Too simple\n");
	else{
		printf("%d %d",n-problems[0].cnt,problems[0].id);
		for(int i=1;i<m;i++){
			if(problems[i].cnt==problems[i-1].cnt)
				printf(" %d",problems[i].id);
			else{
				printf("\n");
				break;
			}
		}
	}
	return 0;
 } 