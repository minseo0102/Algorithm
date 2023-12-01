#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void divide(int x, int y, int size, int &count, int &r, int&c) {
	while (size >= 1) {
		int set = pow(size / 2, 2);
		if (r < x + size / 2 && c < y + size / 2) {

		}
		else if (r < x + size / 2 && c >= y + size / 2 && c < y + size) {
			count += set;
			y += size / 2;
		}
		else if (r >= x + size / 2 && r < x + size && c < y + size / 2) {
			count += set * 2;
			x += size / 2;
		}
		else {
			count += set * 3;
			x += size / 2;
			y += size / 2;
		}
		size /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, r, c;

	cin >> N >> r >> c;

	int size = pow(2, N);//처음 행,열의 크기

	int count = 0;

	divide(0, 0, size, count, r, c);

	cout << count;

}