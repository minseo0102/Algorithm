#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;
vector<vector<int>> arr1;
vector<vector<int>> arr2;

int answer1 = 0;
int answer2 = 0;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int i, int j, int num, vector<vector<int>> &arr) {
	arr[i][j] = 0;
	
	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 && x < n&&y >= 0 && y < n&&arr[x][y] == num) {
			dfs(x, y, num, arr);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr1.resize(n, vector<int>(n));
	arr2.resize(n, vector<int>(n));

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'R') {
				arr1[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if (str[j] == 'G') {
				arr1[i][j] = 2;
				arr2[i][j] = 1;
			}
			else {
				arr1[i][j] = 3;
				arr2[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] != 0) {
				dfs(i, j, arr1[i][j], arr1);
				answer1++;
			}
			if (arr2[i][j] != 0) {
				dfs(i, j, arr2[i][j], arr2);
				answer2++;
			}
		}
	}
	
	cout << answer1 << " " << answer2;

	return 0;
}