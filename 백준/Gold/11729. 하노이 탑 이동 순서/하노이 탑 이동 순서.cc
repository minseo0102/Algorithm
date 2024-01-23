#include<iostream>
#include<math.h>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
	}
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	cout << int(pow(2, k)) - 1 << "\n";
	hanoi(k, 1, 2, 3);

	return 0;
}