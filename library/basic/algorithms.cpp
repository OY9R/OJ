#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void quick_sort(int q[],int l,int r) {
	if(l>=r) return;
	int i=l-1,j=r+1,x=q[l+r>>1];
	while(i<j) {
		do i++; while(q[i]<x);
		do j--; while(q[j]>x);
		if(i<j) swap(q[i],q[j]);
	}
	quick_sort(q,l,j),quick_sort(q,j+1,r);
}
int bit_search_1(int l,int r,bool (*check)(int)) {
	while(l<r) {
		int mid=l+r>>1;
		if((*check)(mid)) r=mid;
		else l=mid+1;
	}
	return l;
}
int bit_search_2(int l,int r,bool (*check)(int)) {
	while(l<r) {
		int mid=l+r+1>>1;
		if((*check)(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
double bit_search_3(double l,double r,double eps,bool (*check)(int)) {
	while(r-l>eps) {
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	return l;
}
vector<int> add(vector<int> &A,vector<int> &B) {
	if(A.size()<B.size()) return add(B,A);
	vector<int> C;
	int t=0;
	for(int i=0; i<A.size(); i++) {
		t+=A[i];
		if(i<B.size()) t+=B[i];
		C.push_back(t%10);
		t/=10;
	}
	if(t) C.push_back(t);
	return C;
}
vector<int> sub(vector<int> &A,vector<int> &B) {
	vector<int> C;
	for(int i=0,t=0; i<A.size(); i++) {
		t=A[i]-t;
		if(i<B.size()) t-=B[i];
		C.push_back((t+10)%10);
		if(t<0) t=1;
		else t=0;
	}
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}
vector<int> mul(vector<int> &A,int b){
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size()||t;i++){
		if(i<A.size())t+=A[i]*b;
		C.push_back(t%10);
		t/=10;
	}
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}
vector<int> div(vector<int> &A,int b,int &r){
	vector<int> C;
	r=0;
	for(int i=A.size()-1;i>=0;i--){
		r=r*10+A[i];
		C.push_back(r/b);
		r%=b;
	}
	reverse(C.begin(),C.end());
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}
int qmi(int m, int k, int p){
	int res=1%p,t=m;
	while(k){
		if(k&1)res=res*t%p;
		t=t*t%p;
		k>>=1;
	}
	return res;
}

int get_bit(int n,int k){
	return n>>k&1;
}
int low_bit(int n){
	return n&-n;
}
void de_duplication(vector<int> &A){
	A.erase(unique(A.begin(),A.end()),A.end());
}
void discrete_init(vector<int> &alls){
	sort(alls.begin(),alls.end());
	de_duplication(alls);
}
int discrete_find(vector<int> &alls,int x){
	int l=0,r=alls.size()-1;
	while(l<r) {
		int mid=l+r>>1;
		if(alls[mid]>=x) r=mid;
		else l=mid+1;
	}
	return r+1;
}
void merge(vector<pair<int,int>> &segs){
	vector<pair<int,int>> res;
	sort(segs.begin(),segs.end());
	int st=-2e9,ed=-2e9;
	for(auto seg:segs)
		if(ed<seg.first){
			if(st!=-2e9)res.push_back({st,ed});
			st=seg.first,ed=seg.second;
		}else ed=max(ed,seg.second);
	if(st!=-2e9)res.push_back({st,ed});
	segs=res;
}
vector<int> kmp(string s,string p){
	vector<int> ne(s.length());
	vector<int> res;
	for(int i=2,j=0;i<=p.length();i++){
		while(j&&p[i]!=p[j+1])j=ne[j];
		if(p[i]==p[j+1])j++;
		ne[i]=j;
	}
	for(int i=1,j=0;i<=s.length();i++){
		while(j&&s[i]!=p[j+1])j=ne[j];
		if(s[i]==p[j+1])j++;
		if(j==p.length()){
			j=ne[j];
			res.push_back(i);
		}
	}
	return res;
}