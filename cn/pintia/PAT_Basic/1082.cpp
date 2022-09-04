#include "bits/stdc++.h"
using namespace std;
struct Node{
    int id;
    int x,y;
    double dis;
};
struct Node nodes[10005];
bool cmp(struct Node a,struct Node b){
    return a.dis<b.dis;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&nodes[i].id,&nodes[i].x,&nodes[i].y);
        nodes[i].dis=sqrt(nodes[i].x*nodes[i].x+nodes[i].y*nodes[i].y);
    }
    sort(nodes,nodes+n,cmp);
    printf("%04d %04d",nodes[0].id,nodes[n-1].id);
    return 0;
}