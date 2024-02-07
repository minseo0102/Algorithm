#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int n, m;
vector<bool> visited;
vector<vector<int>> arr;
vector<int> d;

int nextIndex() {
	int small = 100000001;
	int index=0;
	for (int i = 0; i < n; i++) {
		if (d[i]<small&&!visited[i]) {
			small = d[i];
			index = i;
		}
	}
	
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < n; i++) {
		d[i] = arr[start][i];
	}

	visited[start] = true;
	for (int i = 0; i < n-2; i++) {
		int current = nextIndex();
		visited[current] = true;
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				if (d[current] + arr[current][j] < d[j]) {
					d[j] = d[current] + arr[current][j];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	arr.resize(n, vector<int>(n, 100000001));
	visited.resize(n, false);
	d.resize(n,0);

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;

		arr[s-1][e-1] = min(arr[s-1][e-1], v);
	}

	for (int i = 0; i < n; i++) {
		arr[i][i] = 0;
	}

	int start, end;
	cin >> start >> end;
	dijkstra(start-1);

	cout << d[end - 1];

	return 0;
}