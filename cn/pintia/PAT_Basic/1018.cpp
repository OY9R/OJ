#include "bits/stdc++.h"
using namespace std;
int win=0,lose=0,draw=0;
int CJ1=0,JB1=0,BC1=0;
int CJ2=0,JB2=0,BC2=0;
void print(){
	if(BC1>=CJ1&&BC1>=JB1)
		printf("B ");
	else if(CJ1>BC1&&CJ1>=JB1)
		printf("C ");
	else if(JB1>CJ1&&JB1>BC1)
		printf("J ");
	
	if(BC2>=CJ2&&BC2>=JB2)
		printf("B\n");
	else if(CJ2>BC2&&CJ2>=JB2)
		printf("C\n");
	else if(JB2>CJ2&&JB2>BC2)
		printf("J\n");
}
void fun(char a,char b){
	if(a=='C'&&b=='J'){
		win++;
		CJ1++;
	}	
	else if(a=='C'&&b=='B'){
		lose++;
		BC2++;
	}
	else if(a=='J'&&b=='B'){
		win++;
		JB1++;
	}
	else if(a=='J'&&b=='C'){
		lose++;
		CJ2++;
	}
	else if(a=='B'&&b=='C'){
		win++;
		BC1++;
	}
	else if(a=='B'&&b=='J'){
		lose++;
		JB2++;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		char a,b;
		scanf("%c %c",&a,&b);
		getchar();
		if(a==b){
			draw++;
			continue;
		}
		fun(a,b);	
	}
	printf("%d %d %d\n",win,draw,lose);
	printf("%d %d %d\n",lose,draw,win);
	print();
	return 0;
}
