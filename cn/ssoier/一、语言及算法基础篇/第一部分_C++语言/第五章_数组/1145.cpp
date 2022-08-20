#include<string>
#include<iostream>
using namespace std;
    int main(){
    	string str;
    	cin>>str;
    	int len = str.length();
    	int count = 1;
    	for(int i = 0;i<len;i++){
    		if(str[i+1] == str[i]){
    			count++;
    			continue;
    		}
    		cout<<count<<str[i];
    		count = 1;
    	}
    	return 0;
    }