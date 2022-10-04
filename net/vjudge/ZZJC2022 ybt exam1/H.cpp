#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			printf("%d只青蛙%d张嘴，%d只眼睛%d条腿，扑通一声跳进水里：",i,i,2*i,4*i);
			for(int j=1;j<=i;j++)printf("呱");
			printf(i==n?"。\n":"；\n");
		}
	}
}