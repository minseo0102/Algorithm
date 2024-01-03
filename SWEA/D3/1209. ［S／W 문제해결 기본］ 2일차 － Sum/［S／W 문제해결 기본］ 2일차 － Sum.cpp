#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;//test case number

		vector<int> col(100,0);
		int rcross = 0;
		int lcross = 0;

		int m = 0;

		for (int j = 0; j < 100; j++) {
			int row = 0;
			for (int k = 0; k < 100; k++) {
				int temp;
				cin >> temp;
				row += temp;
				col[k] += temp;
				if (j == k) rcross += temp;
				else if ((j + k) == 99) lcross += temp;
			}
			m = max(m, row);
		}
		
		for (int j = 0; j < 100; j++) {
			m = max(m, col[j]);
		}

		m = max(m, max(rcross, lcross));
		
		cout << "#" << t << " " << m << "\n";

	}
	return 0;
}