#include "bits/stdc++.h"
using namespace std;
int num[105];
int flag[105];
int main(){
    int n;
    scanf("%d",&n);
    memset(flag,1,sizeof(flag));
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            flag[i]=-1;
            flag[j]=-1;
            vector<int> v;
            for(int k=1;k<=n;k++)
                if(num[k]*flag[abs(num[k])]<0)
                    v.push_back(k);
            if(v.size()==2&&flag[v[0]]+flag[v[1]]==0){
                printf("%d %d\n",i,j);
                return 0;
            }
            flag[i]=1;
            flag[j]=1;
        }
    }
    printf("No Solution\n");
    return 0;
}