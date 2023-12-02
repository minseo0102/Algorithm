#include<iostream>

using namespace std;

int N, S, answer=0;
int *arr;

void func(int num, int sum) {
	if (num == N) {
		if (sum == S) {
			answer++;
		}
		return;
	}
	func(num + 1, sum);
	func(num + 1, sum + arr[num]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	func(0, 0);

	if (S == 0) answer--;

	cout << answer;

	return 0;
}