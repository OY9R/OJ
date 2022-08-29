#include "bits/stdc++.h"
#define ll long long
using namespace std;
string mm,m,n,ans;
int main(){
	cin>>mm>>m>>n;
	int l=max(m.length(),n.length()),p=0;
	reverse(mm.begin(),mm.end());
	if(l>20)
		for(int i=20;i<l;i++)
			mm.append("0");
	reverse(m.begin(),m.end());
	reverse(n.begin(),n.end());
	if(m.length()<l)
		for(int i=m.length();i<l;i++)
			m.append("0");
	else
		for(int i=n.length();i<l;i++)
			n.append("0");
	for(int i=0;i<l;i++){
		int x=m[i]-'0';
		int y=n[i]-'0';
		int temp=x+y+p;
		if(mm[i]!='0'&&mm[i]!='d'){
			p=temp/(mm[i]-'0');
			ans+='0'+temp%(mm[i]-'0');
		}else{ 
			p=temp/10;
			ans+='0'+temp%10;
		}
	}
	if(p!=0)ans+=p+'0';
	reverse(ans.begin(),ans.end());
	int flag=0;
	for(int i=0;i<ans.length();i++){
		if(flag==0&&ans[i]=='0')
			continue;
		if(flag==0&&ans[i]!='0'){
			flag=1;
			printf("%c",ans[i]);
			continue;
		}
		if(flag==1)
			printf("%c",ans[i]);	
	}
	if(flag==0)
		printf("0");
	return 0;
}