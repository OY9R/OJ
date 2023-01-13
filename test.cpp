#include<iostream>
#include<stack>
using namespace std;
int n,a[1010];
int main(){
	while(cin>>n&&n){
		while(cin>>a[1]&&a[1]){
			for(int i=2;i<=n;i++)cin>>a[i];
			stack<int> s;
			int ai=1,ls=1;
			while(ls<=n)
				if(ai==a[ls])ai++,ls++;
				else if(s.size()&&s.top()==a[ls])s.pop(),ls++;
				else if(ai<=n)s.push(ai++);
				else break;
			if(ls==n+1)cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<endl;
	}
}