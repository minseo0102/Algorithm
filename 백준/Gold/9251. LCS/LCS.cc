#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;

	cin >> str1 >> str2;

	int r = str1.length();
	int c = str2.length();

	vector<vector<int>> dp(r+1, vector<int>(c+1,0));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int m = max(dp[i][j + 1], dp[i + 1][j]);
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = m;
			}
		}
	}

	cout << dp[r][c];
	
	return 0;
}