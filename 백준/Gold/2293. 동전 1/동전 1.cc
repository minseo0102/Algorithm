#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> value(n);
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	vector<long long> dp(k + 1,0);

	dp[0] = 1;//0원을 만드는 데 필요한 경우의 수 1

	for (int i = 0; i < n; i++) {
		for (int j = value[i]; j <= k; j++) {
			dp[j] += dp[j - value[i]];//j원을 만드는데, value[i]원을 사용하려면 j에서 value[i]를 뺀 값이 필요하고, 이것의 경우의 수를 더해주면 됨.
		}
	}

	cout << dp[k];

	return 0;
}