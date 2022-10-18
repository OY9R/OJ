#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        set<int> m;
        while(n--){
            int in;
            cin>>in;
            m.insert(in);
        }
        n=9-m.size();
        cout<<3*(n+n*n);
		cout<<endl;
	}
	return 0;
}