#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct {
    int num;
    char str[51];
} node;
int cmp(node a,node b) {
    return a.num<b.num;
}
int search(int n,char *a) {
    int flot=0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            if(a[j]-a[i]<0)flot++;
        }
    }
    return flot;
}
int main() {
    int m,n;
    node dna[110];
    scanf("%d%d",&n,&m);
    int i=0;
    for(int i=0; i<m; ++i) {
        scanf("%s",dna[i].str);
        dna[i].num=search(n,dna[i].str);
    }
    sort(dna,dna+m,cmp);
    for(int i=0; i<m; ++i)printf("%s\n",dna[i].str);
    return 0;
}