#include<bits/stdc++.h>
using namespace std;
struct Line {
	double k,a;
};
struct Point {
	double x,y;
};
struct Point mid(struct Point a,struct Point b) {
	struct Point ret;
	ret.x=(a.x+b.x)/2;
	ret.y=(a.y+b.y)/2;
	return ret;
}
struct Line X(struct Line a, struct Point b) {
	a.a=b.y-a.k*b.x;
	return a;
}
struct Line f1(struct Point a,struct Point b) {
	struct Line pa;
	pa.k=-(a.x-b.x)/(a.y-b.y);
	pa=X(pa,mid(a,b));
	return pa;
}
struct Point X2(struct Line a, struct Line b) {
	struct Point ret;
	ret.x=(a.a-b.a)/(b.k-a.k);
	ret.y=a.k*ret.x+a.a;
	return ret;
}
int main() {
	struct Point A,B,C;
	A.x=0; A.y=0; B.y=0;
	cin>>B.x>>C.x>>C.y;
	struct Point A2;
	A2.x=0; A2.y=(C.x+C.y)/2+(C.x/2*(C.y/C.x))
	             cout<<
	             return 0;
}