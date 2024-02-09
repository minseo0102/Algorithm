#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

vector<bool> number(10,false);

bool is_possible(int num) {
	string str = to_string(num);

	for (int i = 0; i < str.size(); i++) {
		if (number[str[i] - 48]) {
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		number[temp] = true;
	}

	if (n == 100) {
		cout << 0;
		return 0;
	}

	int ans = abs(100 - n);

	for (int i = 0; i <= 1000000; i++) {
		if (is_possible(i)) {
			int temp = abs(i - n) + to_string(i).size();
			ans = min(ans, temp);
		}
	}

	cout << ans;

	return 0;
}