#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, int &count, vector<vector<int>> &arr) {
	arr[x][y] = 0;
	count++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&arr[nx][ny] == 1) {
			dfs(nx, ny, count, arr);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j]-'0';
		}
	}

	vector<int> cnt;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int count = 0;
				dfs(i, j, count, arr);
				sum++;
				cnt.push_back(count);
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	cout << sum<<"\n";
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << "\n";
	}

	return 0;
}