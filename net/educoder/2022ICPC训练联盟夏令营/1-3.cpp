#include<iostream>
#include<string>
using namespace std;
char str[27]={0,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
	long long num;
	string ans = ""; 
	while(cin>>num){
		ans="";
		while(num) {	//num转换为26进制，
			//***********Begin*********//
			ans+=str[num%26];//当前位num%26数值对应的字母取出，放在字符串ans的后面。
			num/=26;
			
			//***********End***********//
		}
		
		//***********Begin*********//
		for(int i=ans.length()-1;i>=0;i--){//输出ans，从高位开始输出
			cout<<ans[i];
		}
		cout<<endl;
		//***********End***********//
	}
	return 0;
}
