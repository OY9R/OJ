#include<bits/stdc++.h>
using namespace std;
vector<long long> paths;
vector<int> nodes[200002];
vector<int> values;
int n,k;
void dfs(int root,long long value){
	value+=values[root];
	if(nodes[root].size()==1){
		paths.push_back(value);
	}
	for(int i=1;i<nodes[root].size();i++){
		dfs(nodes[root][i],value);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		paths.clear();
		for(int i=1;i<=n;i++){
			nodes[i].clear();
			nodes[i].push_back(0);
		}
		for(int i=2;i<=n;i++){
			cin>>nodes[i][0];
			nodes[nodes[i][0]].push_back(i);
		}
		values.resize(n+1);
		for(int i=1;i<=n;i++){
			cin>>values[i];
		}
		dfs(1,0);
		sort(paths.begin(),paths.end(),greater<int>());
		long long sum=0;
		for(int i=0;i<paths.size();i++){
			sum+=paths[i];
			//cout<<paths[i]<<' ';
		}
		sum*=k/paths.size();
		for(int i=0;i<k%paths.size();i++){
			sum+=paths[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}