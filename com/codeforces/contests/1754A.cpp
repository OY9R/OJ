#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q=0;
        string s;
		cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='Q'){
                q++;     
            }else{
                q=max(q-1,0);
            }
        }
        if(q<=0){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
		cout<<endl;
	}
	return 0;
}