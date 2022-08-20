#include<iostream>
using namespace std;
int main()
{
    int n;
    int a[20001];
    bool b[20001];
    int i,j;
 
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=true;
    }
 
    for(i=1; i<=n; i++)
        if(b[i])
            for(j=i+1; j<=n; j++)
                if(a[i]==a[j])
                    b[j]=false;
 
    for(i=1; i<=n; i++)
        if(b[i]==true)
            cout<<a[i]<<" ";
    cout<<endl;
 
    return 0;
}