#include<bits/stdc++.h>
using namespace std;
int main() {
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double l1, l2, l3, p, s;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	l1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	l2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	l3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	p = (l1 + l2 + l3) / 2;
	s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
	printf("%.2lf", s);
	return 0;
}
