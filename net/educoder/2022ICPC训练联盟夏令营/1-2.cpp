#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str1[1010], temp[1010];
int main(){
	while(cin>>str1){
		memset(temp,0,sizeof(temp));
		int num,tmp,k=0,length = strlen(str1);
		int j;
		for(int i = length - 1; i > 1 ; i--){
			num = str1[i]-'0';
			for( j = 0;j<k||num!=0;j++ ){
				int z;
				if(j<k) z = temp[j]-'0';
				else z = 0;
				tmp = num*10+z;
				temp[j] = tmp/8 +'0';
				num = tmp%8;
			}
			k = j;
		}
		printf("%s [8] = 0.%s [10]\n",str1,temp);
	}
	return 0;    
}
