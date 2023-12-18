#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	cin >> c;
	if(c >= 'A' && c <= 'Z')
		cout << c << "是大写字母";
	else
		cout << c << "不是大写字母";
	if(c >= 'a' && c <= 'z')
		cout << c << "是小写字母";
	else
		cout << c << "不是小写字母";
	if(c >= '0' && c <= '9')
		cout << c << "是数字";
	else
		cout << c << "不是数字";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n == 100)
		cout << "100满分";
	else if(n >= 90)
		cout << "90-99优秀";
	else if(n >= 80)
		cout << "80-89良好";
	else if(n >= 60)
		cout << "60-79及格";
	else
		cout << "<60不及格";
	return 0;
}

if(条件表达式1){
	当条件1成立时需要执行的语句;
}
if(!条件表达式1 && 条件表达式2){
	当条件2成立时需要执行的语句;
}
if(!条件表达式1 && !条件表达式2 && 条件表达式3){
	当条件3成立时需要执行的语句;
}else{
	当所有条件都不成立时需要执行的语句;
}

if(条件表达式1){
	当条件1成立时需要执行的语句;
}else if(条件表达式2){
	当条件2成立时需要执行的语句;
}else if(条件表达式3){
	当条件3成立时需要执行的语句;
}else{
	当所有条件都不成立时需要执行的语句;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	if(N>0) cout<<"positive";
	else if(N==0) cout<<"zero";
	else cout<<"negative";
}