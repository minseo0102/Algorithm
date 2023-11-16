#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
//상하좌우 접근을 위한
void dfs(vector<vector<int>>& arr, int row, int col, int &size) {//&매우 중요 => 값이 수정되야 하기 때문에
	arr[row][col] = 0;
	size++;

	for (int i = 0; i < 4; i++) {//상하좌우로 4번 탐색
		int ix = row + dx[i];
		int iy = col + dy[i];

		if ((ix >= 0) && ix < arr.size() && iy >= 0 && iy < arr[0].size() && arr[ix][iy] == 1) {//행렬 안 유효하면
			dfs(arr, ix, iy, size);
		}
	}
}
int main() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> sizes;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int size = 0;
				dfs(arr, i, j, size);
				sizes.push_back(size);
			}
		}
	}

	sort(sizes.begin(), sizes.end());

	cout << sizes.size() << "\n";
	for (int i = 0; i < sizes.size(); i++) {
		cout << sizes[i] << " ";
	}

	return 0;
}
