#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int>&b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> m;
	vector<int> bag(K, 0);
	priority_queue<int> pq;//기본이 max heap
	
	for (int i = 0; i< N; i++) {
		int w, v;
		cin >> w >> v;
		m.push_back(pair<int,int>(w, v));
	}

	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	sort(m.begin(), m.end(), compare);//보석 무게에 따른 오름차순
	sort(bag.begin(), bag.end());//가방 무게에 따른 오름차순

	long long answer = 0;
	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && m[j].first <= bag[i]) {
			pq.push(m[j].second);
			j++;
		}
		if (!pq.empty()) {
			answer += (long long)pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}