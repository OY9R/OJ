#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
const int INT_SIZE=32;
int a[N];
int b[INT_SIZE+1];
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		memset(b,0,sizeof(int)*(INT_SIZE+1));
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<n; i++)
			b[(int)log2(a[i])]++;
		ll ans=0;
		for(int i=0; i<=INT_SIZE; i++)
			if(b[i])
				ans+=((ll)b[i]*(b[i]-1)/2);
		cout<<ans<<endl;
	}
	return 0;
}