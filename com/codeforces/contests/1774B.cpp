#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
        vector<int> a(m+1);
        for(int i=1;i<=m;i++)cin>>a[i];
        sort(a.begin()+1,a.end());
        // if(a.back()>(n+(k-1))/k){
        //     cout<<"NO";
        // }else cout<<"YES";
		int tmp=n%k,flag=true;
		for(int i=0;i<k;i++){
			if(a[m-i]>n/k+(tmp>0)){
				flag=false;
				break;
			}
			tmp--;
		}
		cout<<(flag?"YES":"NO");
		cout<<endl;
	}
	return 0;
}