#include<bits/stdc++.h>
using namespace std;
char a[8][4096][256],c;
int N,n,sx,sy,ex,ey,cnt;
string line;
void DFS(int y,int x,int l){
    if(a[l][y][x]<3)cout<<a[l][y][x]-1;
    else{
        if(l<cnt-1)cout<<'*';
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                DFS(2*y+i,2*x+j,l-1);
    }
}
int main(){
    for(getline(cin,line);getline(cin,line);puts("")){
        stringstream ss(line);
        ss>>n;
        if(n&-n!=n||n<2){
            cout<<"Size is invalid";
            continue;
        }
        memset(a,1,sizeof a[0]);
        while(ss>>c>>sx>>c>>sy>>c>>c>>ex>>c>>ey>>c)
            for(int i=sx-1;i<ex;i++)
                for(int j=sy-1;j<ey;j++)
                    a[0][j][i]=2;
        cnt=1;
        for(int m=n;m/=2;cnt++)
            for(int x=0;x<m;x++)
                for(int y=0;y<m;y++)
                    a[cnt][x][y]=a[cnt-1][x<<1][y<<1]|a[cnt-1][x<<1][y<<1|1]|a[cnt-1][x<<1|1][y<<1]|a[cnt-1][x<<1|1][y<<1|1];
        DFS(0,0,cnt-1);
    }
}