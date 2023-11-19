#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> vec(100001, 0);

	for (int i = 1; i <= N; i++) {
		cin >> vec[i];
	}

	int answer = 100001;
	int total = vec[1];//첫번째 값부터 담아서 시작
	int st = 1;//시작 포인터
	int en = 1;//끝 포인터

	while (st <= en && en <= N) {
		if (total >= S) answer = min(answer, en - st + 1);
		if (total < S) {
			en++;
			total += vec[en];
		}
		else {
			total -= vec[st];
			st++;
		}
	}

	if(answer!=100001) cout << answer;
	else cout << 0;

	return 0;
}