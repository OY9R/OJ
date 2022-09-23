#include<bits/stdc++.h>
using namespace std;
int main() {
	int _;
	cin>>_;
	while(_--) {
		int a,b,c;
		cin>>a>>b>>c;
		for(int i=0; i<b*2+1+c*2; i++) {
			if(i<b*2+1) {
				for(int j=i; j<b*2; j++)
					cout<<'.';
				for(int j=0; j<a*2+1; j++) {
					if(i&1)
						if(j&1)cout<<'.';
						else cout<<'/';
					else if(j&1)cout<<'-';
					else cout<<'+';
				}
				if(i<c*2+1){
					for(int j=0;j<i;j++){
						if(i&1)
							if(j&1)cout<<'/';
							else cout<<'|';
						else if(j&1)cout<<'+';
						else cout<<'.';
					}
				}else{
					for(int j=0;j<c*2;j++){
						if(i&1)
							if(j&1)cout<<'/';
							else cout<<'|';
						else if(j&1)cout<<'+';
						else cout<<'.';
					}
					for(int j=0;j<i-c*2;j++)
						cout<<'.';
				}
			}else{
				for(int j=0; j<a*2+1; j++) {
					if(i&1)
						if(j&1)cout<<'.';
						else cout<<'|';
					else if(j&1)cout<<'-';
					else cout<<'+';
				}
				if(i<c*2+1){
					for(int j=0;j<b*2;j++){
						if(i&1)
							if(j&1)cout<<'|';
							else cout<<'/';
						else if(j&1)cout<<'+';
						else cout<<'.';
					}
				}else{
					for(int j=i;j<b*2+1+c*2-1;j++){
						if(i&1)
							if(j&1)cout<<'/';
							else cout<<'|';
						else if(j&1)cout<<'+';
						else cout<<'.';
					}
					for(int j=0;j<i-c*2;j++)
						cout<<'.';
				}
			}
			cout<<endl;
		}
	}
	return 0;
}