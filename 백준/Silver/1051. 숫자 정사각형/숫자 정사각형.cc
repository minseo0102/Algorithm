#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int m = min(N, M);//작은 값이 정사각형의 한 변의 max가 됨

	vector<vector<int>> rec(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			rec[i][j] = str[j]-'0'; //char 문자를 숫자로 바꾸는 함수는 atoi를 쓰지만, string으로 되어 있는 경우엔 인자가 맞지 않으므로,'0'을 뻬주어서 구한다.
		}
	}

	if (m == 1) {
		cout << 1;
		return 0;
	}

	int answer = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < m; k++) {
				if (i + k < N && j + k < M) {//사각형이 범위에 들어오는지 확인
					int t = rec[i][j];//기준이 되는 값을 저장
					if (rec[i][j + k] == t && rec[i + k][j] == t && rec[i + k][j + k] == t) {
						answer = max(k + 1, answer);
					}
				}
			}
		}
	}

	cout << answer * answer;//크기는 변의 제곱

	return 0;
}