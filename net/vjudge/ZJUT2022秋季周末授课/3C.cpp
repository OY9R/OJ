#include <iostream>
#include <cstring>
using namespace std;
const int maxN=30+5;
int n,map[maxN][maxN];
const int dx[]= {1,0,-1,0};
const int dy[]= {0,1,0,-1};
const int DELTA_COUNT=4;
void unpaint(int x, int y) {
    if(map[x][y]!=2) return;
    map[x][y]=0;
    for(int i=0; i<DELTA_COUNT; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        unpaint(nx,ny);
    }
}
void printAns() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    cin >> n;
    memset(map,-1,sizeof(map));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp==0) map[i][j]=2;
            else map[i][j]=1;
        }
    }
    for(int i=1; i<=n; i++) {
        unpaint(1,i);
        unpaint(n,i);
        unpaint(i,1);
        unpaint(i,n);
    }
    printAns();
    return 0;
}