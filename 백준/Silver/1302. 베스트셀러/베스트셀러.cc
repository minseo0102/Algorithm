#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<string, int> bs;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		auto it = bs.find(str);//find는 iterator를 반환하니까
		if (it==bs.end()) {
			bs.insert(pair<string, int>(str, 1));
		}
		else {//이미 존재하면
			it->second++;//개수를 늘린다
		}
	}

	//sort(bs.begin(), bs.end(), compare);//map은 sort 사용 불가

	auto maxIt = bs.begin();
	for (auto it = bs.begin(); it != bs.end(); it++) {
		if (it->second > maxIt->second) {
			maxIt = it;
		}
	}//정렬할 수 없으니 직접 max찾기

	cout << maxIt->first;

	return 0;
}