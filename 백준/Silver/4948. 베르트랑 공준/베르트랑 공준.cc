#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int m,n;
	bool is[250001];
	int i, j;
	for (i = 2; i <= 250000; i++) {
		is[i] = true;
	}
	is[1] = false;
	for (i = 2; i <= sqrt(250000); i++) {
		if (is[i] == true) {
			for (j = 2 * i; j <= 250000; j+=i) {
				is[j] = false;
			}
		}
	}
	cin >> m;
	n = 2 * m;
	while (m != 0) {
		int cnt = 0;
		for (int i = m + 1; i <= n; i++) {
			if (is[i] == true) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		cin >> m;
		n = 2 * m;
	}
	return 0;
}