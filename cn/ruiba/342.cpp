#include "bits/stdc++.h"
using namespace std;
int m[8][8];
int a,b,c,d;
bool dfs(int x,int y,int s){
    //cout<<'['<<x<<' '<<y<<']';
    if(x==c&&y==d)return true;
    if(s){
        return\
            x<7&&y<6&&dfs(x+1,y+2,s-1)\
         || x<6&&y<7&&dfs(x+2,y+1,s-1)\
         || x<6&&y>0&&dfs(x+2,y-1,s-1)\
         || x<7&&y>1&&dfs(x+1,y-2,s-1)\
         || x>0&&y<6&&dfs(x-1,y+2,s-1)\
         || x>1&&y<7&&dfs(x-2,y+1,s-1)\
         || x>1&&y>0&&dfs(x-2,y-1,s-1)\
         || x>0&&y>1&&dfs(x-1,y-2,s-1);
    }
    return false;
}
int main(){
    scanf("%c%d %c%d",&a,&b,&c,&d);
    a-='a';c-='a';b--;d--;
    if(a==c&&b==d){
        cout<<0;
        return 0;
    }
    int step=0;
    while(!dfs(a,b,++step));
    cout<<step;
    return 0;
}
