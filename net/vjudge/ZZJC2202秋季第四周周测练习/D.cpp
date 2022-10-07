#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int n,m;
void DFS(int i,int j) {
    if(i>=0&&i<n&&j>=0&&j<m&&a[i][j]=='W') {
        a[i][j]='.';
        DFS(i-1,j-1);
        DFS(i-1,j);
        DFS(i-1,j+1);
        DFS(i,j-1);
        DFS(i,j+1);
        DFS(i+1,j-1);
        DFS(i+1,j);
        DFS(i+1,j+1);
    }
}
int main() {
    int i,j,flag=0;
    scanf("%d %d",&n,&m);
    memset(a,'0',sizeof(a));
    flag=0;
    for(i=0; i<=n-1; i++)
        scanf("%s",a[i]);
    for(i=0; i<=n-1; i++) {
        for(j=0; j<=m-1; j++) {
            if(a[i][j]=='W') {
                flag++;
                DFS(i,j);
            }
        }
    }
    printf("%d\n",flag);
}