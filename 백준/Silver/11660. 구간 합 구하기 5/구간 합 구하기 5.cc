#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> sum(n+1, vector<int>(n+1));

	for (int i = 1; i < n+1; i++) {
		sum[i][0] = 0;
		for (int j = 1; j < n+1; j++) {
			cin >> sum[i][j];
			sum[i][j] += sum[i][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = 0;
		for (int j = x1; j <= x2; j++) {
			answer += (sum[j][y2] - sum[j][y1 - 1]);
		}

		cout << answer<<"\n";
	}

	return 0;
}