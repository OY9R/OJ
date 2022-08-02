#include <iostream>
using namespace std;
int main() {
	double x, y;
	cin >> x >> y;
	if (x == 0 && y == 0) {
		cout << "yes" << endl;
		return 0;
	}
	if (x >= -1 && y >= -1 && x <= 1 && y <= 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
