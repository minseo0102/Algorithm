#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void dfs(int s, vector<vector<int>> arr, vector<bool> &visited, vector<int> &dfs_result) {
	for (int i = 0; i < arr[s].size(); i++) {
		if (!visited[arr[s][i]]) {
			visited[arr[s][i]] = true;//방문
			dfs_result.push_back(arr[s][i]);
			dfs(arr[s][i], arr, visited, dfs_result);
		}
	}
}
void bfs(int S, vector<vector<int>> arr, vector<bool> &visited, vector<int> &bfs_result, queue<int> &q) {
	for (int i = 0; i < arr[S].size(); i++) {
		if (!visited[arr[S][i]]) {
			visited[arr[S][i]] = true;//방문
			q.push(arr[S][i]);
			bfs_result.push_back(arr[S][i]);
		}
	}
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		bfs(next, arr, visited, bfs_result, q);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S;
	cin >> N >> M >> S;

	vector<vector<int>> arr(N+1);
	vector<bool> visited1(N + 1, false);//dfs에서사용
	vector<bool> visited2(N + 1, false);//bfs에서사용
	queue<int> q;//bfs에서 사용
	vector<int> dfs_result;
	vector<int> bfs_result;
	for (int i = 0; i < M; i++) {//간선 정보 입력받기
		int n1, n2;
		cin >> n1 >> n2;

		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}

	for (int i = 1; i < N + 1; i++) {//노드별로 간선 정보를 오름차순 정렬
		sort(arr[i].begin(), arr[i].end());
	}


	visited1[S] = true;
	visited2[S] = true;
	dfs_result.push_back(S);
	bfs_result.push_back(S);

	dfs(S, arr, visited1, dfs_result);
	bfs(S, arr, visited2, bfs_result, q);

	for (int i = 0; i < dfs_result.size(); i++) {
		cout << dfs_result[i]<<" ";
	}
	cout << "\n";
	for (int i = 0; i < bfs_result.size(); i++) {
		cout << bfs_result[i] << " ";
	}
	
	return 0;
}