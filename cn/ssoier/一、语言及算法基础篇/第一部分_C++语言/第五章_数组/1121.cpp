#include <iostream>
using namespace std;
 
int main(){
    int m,n;
    int sum=0;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int j=0;j<n;j++)
        sum=sum+a[0][j]+a[m-1][j];
    for(int i=1;i<m-1;i++)
        sum=sum+a[i][0]+a[i][n-1];
    cout<<sum;
    return 0;
}