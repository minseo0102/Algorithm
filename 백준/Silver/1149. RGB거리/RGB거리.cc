#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	vector<vector<int>> d(t + 1, vector<int>(3, 0));
	vector<vector<int>> a(t + 1, vector<int>(3, 0));

	for (int i = 1; i <= t; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}

	int answer = min(min(d[t][0], d[t][1]), d[t][2]);

	cout << answer;

	return 0;
}