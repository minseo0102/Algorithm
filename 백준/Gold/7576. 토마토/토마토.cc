#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> arr;
queue<pair<int, int>> q;
queue<pair<int, int>> temp;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int answer = 0;

void bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&arr[nx][ny] == 0) {
			arr[nx][ny] = 1;
			temp.push(pair<int, int>(nx, ny));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	arr.resize(n,vector<int>(m));

	bool end = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(pair<int,int>(i, j));
			}
		}
	}

	while (!q.empty()) {
		bfs(q.front().first, q.front().second);
		q.pop();
		if (q.empty()) {//한번 돌았음을 의미
			answer++;
			while(!temp.empty()) {
				q.push(pair<int,int>(temp.front().first, temp.front().second));
				temp.pop();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << answer-1;

	return 0;
}