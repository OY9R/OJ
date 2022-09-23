#include <stdio.h>
#include <string.h>
struct node {
    int key;
    char str[55];
} dna[110];
int s(char str[]) {
    int sum=0,i,j;
    int len=strlen(str);
    int sd[50]= {0};
    for(i=0; i<len-1; i++) {
        for(j=i+1; j<len; j++) {
            if(str[i]>str[j]) sd[i]++;
        }
    }
    for(i=0; i<len; i++) sum=sum+sd[i];
    return sum;
}
int main(void) {
    int n,m,i,j;
    int res[110];
    scanf("%d %d",&n,&m);
    if(n>0 && n<=50 && m>0 && m<=100) {
        for(i=0; i<m; i++)
            scanf("%s",&dna[i].str);
        for(i=0; i<m; i++) {
            res[i]=s(dna[i].str);
            dna[i].key=res[i];
        }
        sort(res,res+m);
        for(i=0; i<m; i++)
            for(j=0; j<m; j++) {
                if(dna[j].key==res[i]) {
                    printf("%s\n",dna[j].str);
                    dna[j].key=INT_MAX;
                }
            }
    }
    return 0;
}