#include "bits/stdc++.h"
#include "conio.h"
#define ll long long
using namespace std;
char card[]= {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
void init2(int *cards) {
	cards[0]=2;
	cards[1]=rand()%13;
	cards[2]=rand()%13;
}
void print(int *banker,int *gamer) {
	printf("Banker:");
	if(banker[0]==2) {
		printf("[?][%c]",card[banker[2]]);
	} else {
		for(int i=1; i<=banker[0]; i++)
			printf("[%c]",card[banker[i]]);
	}
	printf("\nGamer :");
	for(int i=1; i<=gamer[0]; i++)
		printf("[%c]",card[gamer[i]]);
}
int score(int *cards,bool jack=true) {
	int sum=0;
	bool flag=false;
	for(int i=1; i<=cards[0]; i++) {
		if(cards[i]==0)flag=true;
		if(cards[i]>=10)sum+=10;
		else sum+=cards[i]+1;
	}
	if(jack&&flag&&sum+10<=21) {
		sum+=10;
	}
	//cout<<sum;
	return sum;
}
int add(int *cards) {
	cards[++cards[0]]=rand()%13;
	return cards[cards[0]];
}
void print(int *cards) {
	for(int i=1; i<=cards[0]; i++) {
		printf("[%c]",card[cards[i]]);
	}
}
int gamer[6],banker[6];
int main() {
	srand((int)time(0));
	int money,bet,sep=-1;
	bool fix_bet=false;
	cout<<"You have:";
	cin>>money;
	while(money>0) {
		if(sep==-1&&!fix_bet) {
			do {
				cout<<"Bet:";
				cin>>bet;
				if(bet<0){
					bet=-bet;
					fix_bet=true;
				}
			} while(bet>money);
		}
		init2(gamer);
		if(sep!=-1) {
			gamer[1]=sep;
			if(score(banker)>21){
				banker[0]--;
				
			}
		}else{
			init2(banker);
			printf("Banker:[?][%c]\n",card[banker[2]]);
		}
		printf("Gamer :[%c][%c]=%d",card[gamer[1]],card[gamer[2]],score(gamer));
		char c;
		int win=0,db=0;
		if(sep!=0&&score(gamer)==21) {
			printf("\nBlack Jack!\n");
			win=2;
		}
		int tmp=sep;
		if(sep==0)printf("\n");
		while(win==0&&sep!=0) {
			c=getch();
			if(c==' '||c=='0') {
				add(gamer);
				printf("\rGamer :");
				print(gamer);
				printf("=%d",score(gamer));
				if(score(gamer)>21) {
					printf("\nYou bust!\n");
					win=-1;
					break;
				}
			} else if(c=='\n'||c=='\r') {
				printf("\n");
				break;
			} else if(c=='d'||c=='2') {
				if(money>=bet*2) {
					db=1;
					bet*=2;
					add(gamer);
					printf("\rGamer :");
					print(gamer);
					printf("=%d (D)\n",score(gamer));
					if(score(gamer)>21) {
						printf("You bust!\n");
						win=-1;
					}
					break;
				} else {
					printf("X");
				}
			} else if(c=='s'||c=='1') {
				if(gamer[0]==2&&gamer[1]==gamer[2]&&money>=bet*2) {
					sep=gamer[1];
					gamer[0]=1;
					add(gamer);
					printf(" (S)\nGamer :");
					print(gamer);
					printf("=%d",score(gamer));
					if(gamer[1]==0){
						printf("\n");
						break;
					}
				} else {
					printf("X");
				}
			} else if(c=='f'||c=='.') {
				printf(" (F)\n");
				win=-2;
				break;
			}
		}
		if(tmp!=-1)sep=-1;
		int gamer_score=score(gamer);
		if(win==0) {
			printf("Banker:[%c][%c]",card[banker[1]],card[banker[2]]);
			while(gamer_score>score(banker)&&score(banker)<17&&tmp==-1)
				printf("[%c]",card[add(banker)]);
			int banker_score=score(banker);
			if(banker_score>21) {
				win=1;
			} else if(banker_score>gamer_score) {
				win=-1;
			} else {
				if(tmp==-1){
					while(gamer_score>score(banker,false)&&score(banker,false)<17)
						printf("[%c]",card[add(banker)]);
					banker_score=score(banker,false);
				}
				if(banker_score>21) {
					win=1;
				} else if(banker_score>gamer_score) {
					win=-1;
				}
			}
			printf("=%d\n",banker_score);
			if(banker_score<gamer_score)
				win=1;
		}
		switch(win) {
			case 1:
				printf("You Win! You get $%d!\n",bet);
				money+=bet;
				break;
			case 2:
				printf("You Win! You get $%d!\n",bet+bet/2);
				money+=bet+bet/2;
				break;
			case 0:
				printf("Draw.\n");
				break;
			case -1:
				printf("You Lose! You lost $%d!\n",bet);
				money-=bet;
				break;
			case -2:
				printf("You Fold! You lost $%d!\n",bet/2);
				money-=bet/2;
		}
		printf("Now you have:%d$\n",money);
		if(db==1)bet/=2;
		db=0;
		tmp=0;
	}
	return 0;
}
