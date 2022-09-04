#include "bits/stdc++.h"
using namespace std;
vector<int> v[100005];
int m,n;
int goods[10005];
int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        int t,flag=1;
        scanf("%d",&t);
        for(int j=0;j<t;j++)
            scanf("%d",&goods[j]);
        for(int j=0;j<t&&flag==1;j++)
            for(int k=j+1;k<t&&flag==1;k++)
                for(int m=0;m<v[goods[j]].size()&&flag==1;m++)
                    if(v[goods[j]][m]==goods[k])
                        flag=0;
        if(flag==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}