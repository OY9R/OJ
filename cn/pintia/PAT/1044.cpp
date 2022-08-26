#include "bits/stdc++.h"
#define ll long long
using namespace std;
string mars[2][13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec","tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string s;
	cin>>t;
	getline(cin,s); // remove\n
	while(t--){
		int n=0;
		getline(cin,s);
		if(s[0]>='0'&&s[0]<='9'){
			for(int i=0;i<s.length();i++)
				n=n*10+s[i]-'0';
			if(n<13)
				cout<<mars[0][n]<<endl;
			else{
				cout<<mars[1][n/13];
				if(n%13)cout<<' '<<mars[0][n%13];
				cout<<endl;
			}
		}else{
			if(s.length()>4){
				string s1=s.substr(0,3);
				string s2=s.substr(4,3);
				if(s1=="tre"){
					s1=s.substr(0,4);
					s2=s.substr(5,3);
				}
				if(s2=="tre")
					s2=s.substr(5,4);
				for(int i=0;i<13;i++){
					if(mars[1][i]==s1)
						n+=13*i;
					if(mars[0][i]==s2)
						n+=i;
				}
			}else{
				for(int i=0;i<2;i++)
					for(int j=0;j<13;j++)
						if(mars[i][j]==s)
							n=pow(13,i)*j;
			}
			cout<<n<<endl;
		}
	}
	return 0;
}
