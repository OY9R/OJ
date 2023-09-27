#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2+5;
int n,m,k,a[N][N],b[N][N],p=1e9+7;
long long ans[N][N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			cin>>a[i][j];
	for(int i = 0;i<m;i++)
		for(int j = 0;j<k;j++)
			cin>>b[i][j];
    long long sum;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<k;j++)
		{
            sum = 0;
			for(int c = 0;c<m;c++)
				sum = (sum + a[i][c] * b[c][j]) % p;
			ans[i][j] = sum + p;
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<k;j++)
			cout<<ans[i][j] % p<<" ";
		cout<<"\n";
	}
	return 0;
}