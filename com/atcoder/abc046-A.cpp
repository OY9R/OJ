#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,n=3;cin>>a>>b>>c;
if(a==b)n--;
if(a==c)n--;
if(b==c)n--;
if(!n)n++;
cout<<n;}