#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int *A = new int[N];
	int *B = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);//오름차순
	sort(B, B + N, compare);//내림차순

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	
	cout << answer;

	return 0;

}