#include<bits/stdc++.h>
using namespace std;
int n;
bool rooms[1001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            rooms[j]=!rooms[j];
    for(int i=1;i<=n;i++)
        if(rooms[i])
            cout<<i<<' ';
    return 0;
}