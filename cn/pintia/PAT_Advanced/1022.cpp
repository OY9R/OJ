#include<bits/stdc++.h>
using namespace std;
map<string,set<int>> title,autor,key,pub,year;
void query(map<string,set<int>> &m,string &str){
	if(m.find(str)!=m.end())
		for(auto it=m[str].begin();it!=m[str].end();it++)
			printf("%07d\n",*it);
	else cout<<"Not Found\n";
}
int main(){
	int n,m,id,num;
	cin>>n;
	string _title,_autor,_key,_pub,_year;
	for(int i=0;i<n;i++){
		scanf("%d\n",&id);
		getline(cin,_title);
		title[_title].insert(id);
		getline(cin,_autor);
		autor[_autor].insert(id);
		while(cin>>_key){
			key[_key].insert(id);
			if(getchar()=='\n')break;
		}
		getline(cin,_pub);
		pub[_pub].insert(id);
		getline(cin,_year);
		year[_year].insert(id);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d: ",&num);
		string tmp;
		getline(cin,tmp);
		cout<<num<<": "<<tmp<<'\n';
		switch(num){
			case 1:query(title,tmp);break;
			case 2:query(autor,tmp);break;
			case 3:query(key,tmp);break;
			case 4:query(pub,tmp);break;
			case 5:query(year,tmp);break;
		}
	}
	return 0;
}