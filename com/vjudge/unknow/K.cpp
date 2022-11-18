#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;cin>>n;
    while (n--)
    {
        cin>>t;
        int a[300]={0},b[300]={0};
        for(int i=0;i<t;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        if(t==1||t==2)printf("%d\n",a[0]);
        else{
            for(int i=0;i<=100;i++){
                if(b[i]==1){
                    for(int j=0;j<t;j++){
                        if(a[j]==i){
                            printf("%d\n",j+1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}