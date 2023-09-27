#include<bits/stdc++.h> 
using namespace std;
bool f[10005][105];
int  a[10005][105];
int  doors[105];//记录每层楼有楼梯的门数
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            cin>>f[i][j]>>a[i][j];
            if(f[i][j]) cnt++;//记录该层楼有楼梯的门数
        }
        doors[i]=cnt;
    }
    int k;
    cin>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i][k];
        ans%=20123;
        int cnt=0;
        int fl=a[i][k];
        while(1)
        {   
            if(k>=m)
            {
                k=0;
            }
            if(f[i][k])
            {
                cnt++;
            }
            if(cnt>=(fl-1)%doors[i]+1) // 考虑fl%doors[i]==0的情况
            {
                break;
            }
            k++;
        }
    }
    cout<<ans;
}