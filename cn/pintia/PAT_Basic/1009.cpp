#include "bits/stdc++.h"
using namespace std;
int main(){
	string a;
	deque<string> sentence;
	while (cin.peek()!='\n'){
		cin >> a;
		sentence.push_front(a);
	}
	deque<string> ::iterator it;
	cout << sentence[0];
	for (it = sentence.begin() + 1; it < sentence.end(); it++){
		cout <<' '<< *it;
	}
	return 0;
}
