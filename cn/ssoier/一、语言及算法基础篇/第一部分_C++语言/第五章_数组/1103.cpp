#include<bits/stdc++.h>
using namespace std;
int a[10],b,sum=0;
int main(){
    for(int i=0;i<10;i++)	
		cin>>a[i];
    cin>>b;
    b+=30;
    for(int i=0;i<10;i++)
        if(a[i]<=b)
        	sum++;
    cout<<sum<<endl;
    return 0;
}