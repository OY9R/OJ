#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
    string s;cin>>s;
    stack<int> ss;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='-')cout<<i<<' ';
        else if(s[i-1]=='(')ss.push(i);
        else {cout<<i<<' '<<ss.top()<<' ';ss.pop();}
    }
	return 0;
}