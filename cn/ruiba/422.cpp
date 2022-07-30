#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 100
int X, Y, d;
char m[maxn][maxn];

bool dfs(int x, int y, int b) {
	if (b == d) {
		bool finish = true;
		for (int i = 1; i <= X; i++) {
			for (int j = 0; j <= Y; j++) {
				if (m[i][j] == '.') {
					finish = false;
				}
			}
		}
		return finish;
	}
	bool flag = false;
	for (int i = 1; x + i <= x && y + i <= Y; i++) {
		for (int j = 0; j < i; j++) {
			if (m[x + i][y + j] == '$') {
				
			}else if(m[x + i][y + j] == '.'||m[x + i][y + j] == '.')
			switch (m[x + i][y + j]) {
				case '$':
					if (!flag) {
						flag = true;
					} else {
						return false;
					}
				case '.':
					m[x + i][y + j] = 'A' + b;
					break;
				default:
					return false;
			}
		}
	}
}

int main() {
	cin >> X >> Y;
	for (int i = 1; i <= X; i++) {
		cin >> (m[i] + 1);
		for (int j = 1; j <= Y; j++) {
			if (m[i][j] == '$') {
				d++;
			}
		}
	}
	for (int i = 1; i <= X; i++) {
		cout << (m[i] + 1) << endl;
	}
}
