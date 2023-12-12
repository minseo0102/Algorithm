#include<iostream>

using namespace std;

bool solution(int n) {
	
	if (n < 100) return true;
	else {
		int a1, a2, a3;
		a3 = n % 10;
		a2 = (n / 10) % 10;
		a1 = n / 100;

		if ((a3 - a2) == (a2 - a1)) return true;
		else return false;
	}
}
int main() {
	int n;
	int result=0;
	cin >> n;
	bool *res = new bool[n];

	for (int i = 0; i < n; i++) {
		res[i] = solution(i + 1);
		if (res[i]==true) result++;
	}

	cout << result;

	return 0;
}