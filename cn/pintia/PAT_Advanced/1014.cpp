#include<bits/stdc++.h>
using namespace std;
int N,M,K,Q;
typedef struct Customer {
	int start=0;
	int time;
	int end;
};
int main() {
	cin>>N>>M>>K>>Q;
	Customer C[K+1];
	queue<Customer> windows[N+1];
	for(int i=1; i<=K; i++) {
		cin>>C[i].time;
		C[i].end = C[i].time;
	}
	for(int i=1; i<=K; i++) {
		int window = (i-1)%N+1;
		if(i<=N*M) {
			if(i>N) {
				C[i].start = windows[window].back().end;
				C[i].end = C[i].start+C[i].time;
			}
			windows[window].push(C[i]);
		} else {
			int window = 1;
			for(int j=2; j<=N; j++) {
				if(windows[j].front().end<windows[window].front().end)

					window = j;
			}
			windows[window].pop();
			C[i].start = windows[window].back().end;
			C[i].end = C[i].start+C[i].time;
			windows[window].push(C[i]);
		}
	}
	for(int i=0; i<Q; i++) {
		int a;
		cin>>a;
		int HH=8;
		if(C[a].start/60+8>=17)
			cout<<"Sorry"<<endl;
		else
			printf("%02d:%02d\n",C[a].end/60+HH,C[a].end%60);
	}
	return 0;
}