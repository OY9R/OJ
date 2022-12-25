#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        string s;
        cin>>s;
        int t=0;
        cout<<"1 ";
        for(int i=1,j=2;i<n-1;i++,j++){
            if(s[i]==s[i-1])t++;
            else t=0;
            cout<<j-t<<' ';
        }
		cout<<endl;
	}
	return 0;
}