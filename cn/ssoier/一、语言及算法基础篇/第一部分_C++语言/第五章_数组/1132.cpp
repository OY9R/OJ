#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string player1,player2;
	
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> player1 >> player2;
		if(player1==player2)
			cout << "Tie" << endl;
		else if((player1=="Rock" && player2=="Scissors") ||
				(player1=="Scissors" && player2=="Paper") ||
				(player1=="Paper" && player2=="Rock"))
				cout << "Player1" << endl;
		else
			cout << "Player2" << endl;
	}
	return 0;
}