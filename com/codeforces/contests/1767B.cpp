#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin()+1,a.end());
        for(int i=1;i<n;i++){
            if(a[i]>a[0]){
                a[0]=(a[i]+a[0])/2+(a[i]+a[0])%2;
            }
        }
		cout<<a[0]<<endl;
	}
	return 0;
}