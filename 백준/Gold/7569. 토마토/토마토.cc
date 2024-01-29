#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, h;
vector<vector<vector<int>>> arr;
queue<pair<pair<int, int>,int>> q;
queue<pair<pair<int, int>,int>> temp;

int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

int answer = 0;

void bfs(int x, int y, int z) {
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];

		if (nx >= 0 && nx < n&&ny >= 0 && ny < m&& nz>=0 && nz< h&& arr[nx][ny][nz] == 0) {
			arr[nx][ny][nz] = 1;
			temp.push(pair<pair<int, int>, int> (pair<int, int>(nx, ny),nz));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	arr.resize(n, vector<vector<int>>(m, vector<int> (h)));

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push(pair<pair<int, int>, int> (pair<int, int> (i, j), k));
				}
			}
		}
	}

	while (!q.empty()) {
		bfs(q.front().first.first, q.front().first.second, q.front().second);
		q.pop();
		if (q.empty()) {//한번 돌았음을 의미
			answer++;
			while (!temp.empty()) {
				q.push(pair<pair<int, int>, int> (pair<int, int> (temp.front().first.first, temp.front().first.second),temp.front().second));
				temp.pop();
			}
		}
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer - 1;

	return 0;
}