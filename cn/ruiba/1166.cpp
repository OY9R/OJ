#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a,b=0,c=0;cin>>n;
    string s;getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        if(s[0]=='n')a=(a&~b)^c;
        else{int x,h;
            sscanf(s.c_str(),"%d:%*d %d",&h,&x);
            if(i==0)a=x;
			else if(h<12)a&=x,b|=~x,c&=x;
			else if(h<18)a|=x,b|=x,c|=x;
			else a^=x,c^=x;
        }cout<<a<<'\n';
    }
}