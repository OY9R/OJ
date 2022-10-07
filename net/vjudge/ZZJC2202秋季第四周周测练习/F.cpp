#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,tianji[1001],king[1001];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>tianji[i];
	for(int i=0;i<n;i++)
		cin>>king[i];
	sort(tianji,tianji+n);
	sort(king,king+n);
	int i=0,j=0,ans=0;
	while(true){
		while(i+j<n&&tianji[i+j]<=king[i])j++;
		if(i+j<n)i++;
		else break;
	}
	cout<<i<<endl;
	return 0;
}