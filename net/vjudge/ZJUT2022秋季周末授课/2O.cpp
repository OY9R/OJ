#include<bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	while(true){
		if(!(getline(cin,a)&&getline(cin,b)))break;
		int an=a.size(),bn=b.size();
		if(an<=0||bn<=0)break;
		if(an<bn){
			cout<<"No"<<endl;
			continue;
		}
		int j=0;
		for(int i=0;i<an;i++){
			if(a[i]==b[j])j++;
		}
		if(j<bn)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}