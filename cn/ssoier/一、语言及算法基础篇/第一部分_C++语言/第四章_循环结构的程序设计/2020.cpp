#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int n,s=0;
    for(int i=0;i<400000;i++)
    {
        s=s+i;
        if(s>m)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}