#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int arr[10000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = arr[0];
	int answer = 0;
	for (int s = 0, e = 0; s <= e;) {
		if (sum < M) {
			e++;
			if (e < N) sum += arr[e];
			else break;
		}
		if (sum == M) {
			answer++;
			sum -= arr[s];
			s++;
			e++;
			if (e < N) sum += arr[e];
			else break;
		}
		if (sum > M) {
			sum -= arr[s];
			if (s == e && e < N - 1) {
				s++;
				e++;
				sum += arr[e];
			}
			else {
				s++;
			}
		}
	}

	cout << answer;
}