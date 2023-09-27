#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main(){
    // freopen("test.txt","w",stdout);
    int tot=0;
    printf(" yes.cpp compiling...  ");
    if(system("g++ yes.cpp -o yes.exe")){
        printf("\nCompile Error; yes.cpp");
        return 0;
    }
    printf("Success\n  no.cpp compiling...  ");
    if(system("g++ no.cpp -o no.exe")){
        printf("\nCompile Error; no.cpp");
        return 0;
    }
    printf("Success\nmake.cpp compiling...   ");
    if(system("g++ make.cpp -o make.exe")){
        printf("\nCompile Error; make.cpp");
        return 0;
    }
    printf("Success\n start checker...\n");
    while(1){
        tot++;
        printf("text %d :",tot);
        system("make.exe");
        double st1=clock();
        system("yes.exe < input.txt > right.txt");
        double ed1=clock();
        double st2=clock();
        system("no.exe < input.txt > wrong.txt");
        double ed2=clock();
        if(system("fc right.txt wrong.txt > nul")){
            printf("Wrong Answer;\n > input: \n");
            system("type input.txt ");
            printf("\n> diff:\n");
            system("fc right.txt wrong.txt /N");
            return 0;
        }
        else printf("Accepted; yes:%.0lfms no:%.0lfms\n",ed1-st1,ed2-st2);
    }   //正解用时和错解用时
    return 0;
}