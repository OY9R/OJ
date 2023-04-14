#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string s;cin>>n>>s;
    for(int i=1;i<n;i++)
        if(s[i]==s[0]){
            cout<<"Wrong Answer"<<endl;
            return 0;
        }
    cout<<"Correct"<<endl;
	return 0;
}