#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int n;
    string str;
    while (t--)
    {
        int x[3]={0},y[3]={0};
        cin>>n;
        int k=0;
        for(int i=0;i<n;i++){
            cin>>str;
            for(int j=0;j<n;j++){
                if(str[j]=='*'){
                    x[k]=i;
                    y[k]=j;
                    k++;
                }
            }
        }
        if(n==2){
            printf("**\n**\n");
        }
        else{
            if(x[0]!=x[1]&&y[0]!=y[1]){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==x[0]&&j==y[0]||i==x[1]&&j==y[1]||i==x[0]&&j==y[1]||i==x[1]&&j==y[0])
                        {
                            printf("*");
                        }
                        else {
                            printf(".");
                        }
                    }
                    printf("\n");
                }
            }
            else if(x[0]==x[1]){
                int p;
                if(x[0]!=0)p=0;
                else p=1;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==x[0]&&j==y[0]||i==p&&j==y[1]||i==x[0]&&j==y[1]||i==p&&j==y[0])
                        {
                            printf("*");
                        }
                        else {
                            printf(".");
                        }
                    }
                    printf("\n");
                }
            }
            else{
                int p;
                if(y[0]!=0)p=0;
                else p=1;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==x[0]&&j==y[0]||i==x[1]&&j==p||i==x[0]&&j==p||i==x[1]&&j==y[0])
                        {
                            printf("*");
                        }
                        else {
                            printf(".");
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
    
    return 0;
}