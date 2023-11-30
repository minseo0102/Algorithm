#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	bool is[10001];
	int i, j;
	for (i = 2; i <= 10000; i++) {
		is[i] = true;
	}
	is[1] = false;
	for (i = 2; i <= sqrt(10000); i++) {
		if (is[i] == true) {
			for (j = 2 * i; j <= 10000; j+=i) {
				is[j] = false;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int temp = n / 2;
		for (int j = 0; j < temp; j++) {
			if (is[temp - j] == true && is[temp + j] == true) {
				cout << temp - j << " " << temp + j << "\n";
				break;
			}
		}
	}
	
	return 0;
}