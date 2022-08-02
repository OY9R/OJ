#include<iostream>
using namespace std;
int main()
{
    int n,number,N;
    int sum=0;
    int i;

    cin>>n>>number;
    for(i=1; i<=n; i++)
    {
        cin>>N;
        if(N==number)	sum++;
    }
    cout<<sum<<endl;
    return 0;
}