#include<bits/stdc++.h>
using namespace std;

string str[]= {"Typically Otaku","Eye-opener","Young Traveller","Excellent Traveller","Contemporary Xu Xiake"};
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int cnt=0;
		for(int j=1; j<=4; j++) {
			int x;
			scanf("%d",&x);
			if(x!=0)
				cnt++;
		}
		cout<<str[cnt]<<endl;
	}
	return 0;
}