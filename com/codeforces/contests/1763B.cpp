#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
        vector<pair<int,int>> a(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > b;
        for(int i=0;i<n;i++)cin>>a[i].first;
        for(int i=0;i<n;i++)cin>>a[i].second;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            b.push({a[i].second,i});
        }
        int l=0;
        bool flag=true;
        for(int d=k;l<n;d+=k){
            //cout<<d<<' ';
            while(l<n&&a[l].first<=d){
                l++;
            }
            if(l<n){
                while(b.top().second<l)b.pop();
                //cout<<k<<-b.top().first<<' ';
                k-=b.top().first;
            }
            if(k<=0){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES";
        else cout<<"NO";
		cout<<endl;
	}
	return 0;
}