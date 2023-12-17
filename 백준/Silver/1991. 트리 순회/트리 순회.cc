#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;


void preorder(int n, vector<vector<int>> &arr) {
	if (n == -1) return;
	cout << (char)(n + 'A');
	preorder(arr[n][0], arr);
	preorder(arr[n][1], arr);
}
void inorder(int n, vector<vector<int>> &arr) {
	if (n == -1) return;
	inorder(arr[n][0], arr);
	cout << (char)(n + 'A');
	inorder(arr[n][1], arr);
}
void postorder(int n, vector<vector<int>> &arr) {
	if (n == -1) return;
	postorder(arr[n][0], arr);
	postorder(arr[n][1], arr);
	cout << (char)(n + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> arr(n);

	for (int i = 0; i < n; i++) {
		char node, l, r;
		cin >> node >> l >> r;
		int x = node - 'A';
		if (l == '.') {
			arr[x].push_back(-1);
		}
		else arr[x].push_back(l-'A');
		if (r == '.') {
			arr[x].push_back(-1);
		}
		else arr[x].push_back(r - 'A');
	}

	preorder(0, arr);
	cout << "\n";
	inorder(0, arr);
	cout << "\n";
	postorder(0, arr);
	cout << "\n";

	return 0;
}