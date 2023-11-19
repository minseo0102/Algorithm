#include<iostream>
#include<string>
#include<vector>
using namespace std;

void quadtree(int x, int y, int size, vector<vector<int>> &arr) {//기준이 되는 값이 arr[x][y]
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != arr[x][y]) {//size 크기의 정사각형 안에서 값이 달라지는 순간이 오면
				cout << "(";
				quadtree(x, y, size / 2, arr);//왼쪽 위
				quadtree(x, y + size / 2, size / 2, arr);//오른쪽 위
				quadtree(x + size / 2, y, size / 2, arr);//왼쪽 아래
				quadtree(x + size / 2, y + size / 2, size / 2, arr);//오른쪽 아래
				cout << ")";
				return;//이걸 해줘야 모두 탐색하고 끝낼 수 있음.
			}
		}
	}
	cout << arr[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	quadtree(0, 0, N, arr);
}