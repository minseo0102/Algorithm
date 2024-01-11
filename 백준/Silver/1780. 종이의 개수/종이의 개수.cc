#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n;
vector<vector<int>> arr;
map<int, int> m;

void func(int size, int x, int y) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[x][y] != arr[i][j]) {
				int new_size = size / 3;
				func(new_size, x, y);
				func(new_size, x, y + new_size);
				func(new_size, x, y + new_size * 2);
				func(new_size, x + new_size, y);
				func(new_size, x + new_size, y + new_size);
				func(new_size, x + new_size, y + new_size * 2);
				func(new_size, x + new_size * 2, y);
				func(new_size, x + new_size * 2, y + new_size);
				func(new_size, x + new_size * 2, y + new_size * 2);
				return;
			}
		}
	}
	m[arr[x][y]]++; //해당 키가 map에 없으면, 자동으로 키 생성 및 0으로 초기화하고 증가시킴.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(n, 0, 0);

	cout << m[-1] << "\n" << m[0] << "\n" << m[1];

	return 0;
}