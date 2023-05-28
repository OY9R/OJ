#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, y;
};

int mark[10], ret[10];
double rad[10];
node a[10];
int n, xa, ya, xb, yb, S;
double mn;

void dfs(int x) {
	if (x > n) {
		for (int i = 1; i <= n; i++) {
			int idx = ret[i];
			int h = min(abs(a[idx].y-ya), abs(a[idx].y-yb));
			int w = min(abs(a[idx].x-xa), abs(a[idx].x-xb));
			int r = min(h, w);
			rad[idx] = r;
			for (int j = 1; j < i; j++) {
                if(rad[ret[j]]==0)continue;
				int ax = a[ret[j]].x;
				int ay = a[ret[j]].y;
				int bx = a[idx].x;
				int by = a[idx].y;
				double dis = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by)) - rad[ret[j]];
				if (dis <= 0) {
					rad[idx] = 0;
					break;
				}
				rad[idx] = min(rad[idx], dis);
			}
		}
		
		double sCircle = 0;
		for (int i = 1; i <= n; i++) {
			double r = rad[i];
			// cout << "r:" << r << endl; 
			sCircle += acos(-1) * r * r; 
		}
		// cout << mn << " " << S << " " << sCircle << endl;
		mn = min(mn, S - sCircle);
		
		return; 
	}
	
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			mark[i] = 1;
			ret[x] = i;
			dfs(x + 1);
			mark[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	
	S = abs(xa-xb) * abs(ya-yb);
	mn = S;
	
	dfs(1);
	
	int final = mn + 0.5; 
	printf("%d", final);
		
	return 0;
} 