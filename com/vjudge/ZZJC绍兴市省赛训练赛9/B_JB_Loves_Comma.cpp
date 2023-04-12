#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    cin>>s;
    cout<<s[0]<<s[1];
    for(int i=2;i<s.size();i++){
        cout<<s[i];
        if(s[i]=='b'&&s[i-1]=='j'&&s[i-2]=='c'){
            cout<<',';
        }
    }
}