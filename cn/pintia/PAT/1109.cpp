#include "bits/stdc++.h"
bool isUpper(char ch){
    return 'A'<=ch&&ch<='Z';
}
void printWordMatrix(char *w,int len,char Matrix[][6]){
    for(int i=0;i<7;i++){
        for(int j=0;j<len;j++){
            int index=(w[j]-'A')*7+i;
            printf("%s",Matrix[index]);
            if(j!=len-1)
                printf(" ");
        }
        printf("\n");
    }
}
int main(){
    int x=26*7;
    int y=6;
    char matrix[26*7][6];
    for(int i=0;i<x+1;i++){
        if(i==x){
            getchar();
            char ch,res[10]={0};
            int index=0,newLine=0;
            while((ch=getchar())!='\n')
                if(!(isUpper(ch))){
                    res[index] = '\0';
                    int len = strlen(res);
                    if(len != 0){
                        if(newLine != 0)
                            printf("\n");
                        printWordMatrix(res,len,matrix);
                        newLine++;
                    }
                    index = 0;
                    res[index] = '\0';
                }else
                    res[index++] = ch;
            if(strlen(res) != 0){
                if(newLine != 0)
                    printf("\n");
                printWordMatrix(res,strlen(res),matrix);
            }
        }else
            scanf("%s",matrix[i]);
    }
}
