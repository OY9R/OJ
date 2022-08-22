#include "bits/stdc++.h"
using namespace std;
char weeks[8][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int i=0;
	while(a[i]!=b[i]||a[i]<'A'||a[i]>'G')i++;
	printf("%s ",weeks[a[i++]-'A']);
	while(a[i]!=b[i]||!(a[i]>='0'&&a[i]<='9'||a[i]>='A'&&a[i]<='N'))i++;
	if(a[i]<'A')printf("%02d:",a[i]-'0');
	else printf("%02d:",a[i]-'A'+10);
	i=0;
	while(c[i]!=d[i]||!(c[i]>='a'&&c[i]<='z'||c[i]>='A'&&c[i]<='Z'))i++;
	printf("%02d",i);
	return 0;
}
