#include<cstdio>
#include<cstring>
const int MaxN = 1001;
int main() {
	int i, j;
	char src[MaxN];
	while(scanf("%s", src) != EOF) {
		char dest[MaxN] = {'0'};
		int index = 0;
		for(i=strlen(src)-1; i>1; i--) {
			int num = src[i] - '0';
			int temp;
			for(j=0; j < index || num; j++) {
				temp = num * 10 + (j < index ? (dest[j] - '0') : 0);
				dest[j] = temp / 8 + '0';
				num = temp % 8;
			}
			index = j;
		}
		if(dest[0]=='0'&&dest[1]=='\0')
			dest[0]='\0';
		printf("%s [8] = 0.%s [10]\n", src, dest);
	}
	return 0;
}