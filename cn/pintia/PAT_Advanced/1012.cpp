#include<bits/stdc++.h>
using namespace std;
struct Node {
	int number;
	int c,m,e,a;
	int rank[4];
};
bool cmp_a(struct Node tmp1,struct Node tmp2) {
	return tmp1.a>tmp2.a;
}
bool cmp_e(struct Node tmp1,struct Node tmp2) {
	return tmp1.e>tmp2.e;
}
bool cmp_m(struct Node tmp1,struct Node tmp2) {
	return tmp1.m>tmp2.m;
}
bool cmp_c(struct Node tmp1,struct Node tmp2) {
	return tmp1.c>tmp2.c;
}
int main() {
	int n,m,tmp,cnt;
	cin>>n>>m;
	struct Node node[n];
	for(int i=0; i<n; i++) {
		cin>>node[i].number>>node[i].c>>node[i].m>>node[i].e;
		node[i].a=(node[i].c+node[i].m+node[i].e)/3;
	}

	tmp=1; cnt=1;
	sort(node,node+n,cmp_a);
	for(int i=0; i<n; i++) {
		node[i].rank[0]=tmp;
		if(i!=n-1&&node[i].a!=node[i+1].a) {
			tmp+=cnt; cnt=1;
		} else cnt++;
	}

	tmp=1; cnt=1;
	sort(node,node+n,cmp_c);
	for(int i=0; i<n; i++) {
		node[i].rank[1]=tmp;
		if(i!=n-1&&node[i].c!=node[i+1].c) {
			tmp+=cnt; cnt=1;
		} else cnt++;
	}

	tmp=1; cnt=1;
	sort(node,node+n,cmp_m);
	for(int i=0; i<n; i++) {
		node[i].rank[2]=tmp;
		if(i!=n-1&&node[i].m!=node[i+1].m) {
			tmp+=cnt; cnt=1;
		} else cnt++;
	}

	tmp=1; cnt=1;
	sort(node,node+n,cmp_e);
	for(int i=0; i<n; i++) {
		node[i].rank[3]=tmp;
		if(i!=n-1&&node[i].e!=node[i+1].e) {
			tmp+=cnt; cnt=1;
		}else cnt++;
	}
	for(int i=0; i<m; i++) {
		int temp;
		cin>>temp;
		int flag=0;
		for(int j=0; j<n; j++) {
			if(node[j].number==temp) {
				int pos=min_element(node[j].rank,node[j].rank+4)-node[j].rank;
				cout<<*min_element(node[j].rank,node[j].rank+4)<<" ";
				if(pos==0) cout<<'A';
				else if(pos==1) cout<<'C';
				else if(pos==2) cout<<'M';
				else if(pos==3) cout<<'E';
				cout<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"N/A"<<endl;
	}
}