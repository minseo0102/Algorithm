#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		int n;
		cin >> n;
		vector<int> arr(100);
		for (int j = 0; j < 100; j++) {
			cin >> arr[j];
		}
		
		int answer;
		for (int j = 0; j < n; j++) {
			sort(arr.begin(), arr.end());
			if (((arr[99] - arr[0]) == 1) || ((arr[99] - arr[0]) == 0)) {
				break;
			}
			else {
				arr[99]--;
				arr[0]++;
			}
		}
		sort(arr.begin(), arr.end());
		answer = arr[99] - arr[0];
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}