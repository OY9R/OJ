#include<bits/stdc++.h>
using namespace std;
 int main() {
	int n;string s;
	cin>>n>>s;
    vector<int> m(n);
	for(int i=0;i<n;i++)
        m[i]=(s[i]=='x');
	for(int i=0;i<4;i++) {
		int a=i/2,b=i%2;
		for(int j=0;j<n;j++) {
			int c=(a+b+m[j])%2;
			a=b;b=c;
		}
		if(a==i/2&&b==i%2) {
			for(int j=0;j<n;j++) {
				cout<<(b?"W":"S");
				int c=(a+b+m[j])%2;
				a=b;b=c;
			}
			cout<<endl;
            return 0;
		}
	}
	cout<<-1;
    return 0;
}