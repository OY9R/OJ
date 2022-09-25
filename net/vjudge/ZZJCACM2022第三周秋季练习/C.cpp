#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	string a,b;
	while(getline(cin,a)&&getline(cin,b)){
		int j=0;
		for(int i=0;i<(int)a.length();i++)
			if(a[i]==b[j])j++;
		if(j<(int)b.length())cout<<"No";
		else cout<<"Yes";
		cout<<endl;
	}
	return 0;
}