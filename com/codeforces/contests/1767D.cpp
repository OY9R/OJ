#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=1,r=1;
    for(int i=0;i<n;i++)
        if(s[i]=='1')l+=l;
        else r+=r;
    //cout<<l<<' '<<r;
    for(int i=l;i<=(1<<n)-r+1;i++)
        cout<<i<<' ';
    cout<<endl;
	return 0;
}