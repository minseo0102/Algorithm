#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>> arr(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int count = 0;

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (1) {
		if (arr[r][c] == 0) {//현재 위치가 벽이 아니고, 청소가 안된 곳이라면
			count++;
			arr[r][c] = 2;//청소를 완료하면 2로 채운다
		}
		
		bool clean = true;

		for (int i = 0; i < 4; i++) {
			int x = r + dx[i];
			int y = c + dy[i];
			
			if (arr[x][y] == 0) {
				clean = false;//하나라도 청소안된 곳이있으면 바로 빠져나옴
				break;
			}
			
		}
		if (clean) {//주변에 청소할데가 없으면
			int bx, by;
			if (d == 0) {//북
				bx = r + 1;
				by = c;
			}
			else if (d == 1) {//동
				bx = r;
				by = c - 1;
			}
			else if (d == 2) {//남
				bx = r - 1;
				by = c;
			}
			else {//서
				bx = r;
				by = c + 1;
			}

			if (arr[bx][by] != 1) {//후진할 수 있으면
				r = bx;
				c = by;
			}
			else {
				cout << count;
				return 0;//중단
			}
		}
		//0>>3>>2>>1>>0
		else{//청소할데가 있으면
			d = (d + 3) % 4;//회전=반시례로 90도는 시계로 270도니까
			if (d == 0) {//북
				if (arr[r - 1][c] == 0) {
					r = r - 1;
				}
			}
			else if (d == 1) {//동
				if (arr[r][c + 1] == 0) {
					c = c + 1;
				}
			}
			else if (d == 2) {//남
				if (arr[r + 1][c] == 0) {
					r = r + 1;
				}
			}
			else {//서
				if (arr[r][c - 1] == 0) {
					c = c - 1;
				}
			}
		}
	}

	cout << count;

	return 0;
}

