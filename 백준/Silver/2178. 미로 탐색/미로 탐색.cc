#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;

int answer = 10000;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void miro(vector<vector<int>> &arr) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });
	arr[0][0] = 0;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int count = q.front().second;

		q.pop();

		if (r == n - 1 && c == m - 1) {
			answer = min(answer, count);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int x = r + dx[i];
			int y = c + dy[i];
			if (x >= 0 && x < n&&y >= 0 && y < m&&arr[x][y] == 1) {
				q.push({ {x,y}, count + 1 });
				arr[x][y] = 0;
			}
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

	miro(arr);

	cout << answer;
    
    return 0;
}