//시간 초과 발생 코드
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, m;

int answer = 10000;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void miro(int r, int c, int count, vector<vector<int>> arr) {
	count++;
	if (r == n - 1 && c == m - 1) {
		answer = min(answer, count);
		return;
	}
	arr[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int x = r + dx[i];
		int y = c + dy[i];
		if (x >= 0 && x < n&&y >= 0 && y < m&&arr[x][y] == 1) {
			miro(x, y, count, arr);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> arr(n);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			arr[i].push_back(str[j] - '0');
		}
	}

	
	miro(0, 0, 0, arr);

	cout << answer;

  return 0;
}
//recursive function 때문에
