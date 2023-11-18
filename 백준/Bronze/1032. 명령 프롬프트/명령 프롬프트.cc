#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string str;//기준이 되는 str
	cin >> str;

	if (T == 1) {
		cout << str;
		return 0;
	}

	int len = str.length();

	//중복값을 넣지 않는 set을 선언해서, 값이 다른 인덱스를 넣는다
	set<int> index;

	for (int i = 1; i < T; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < len; j++) {
			if (str[j] != s[j]) {
				index.insert(j);
			}
		}
	}

	for (auto it = index.begin(); it != index.end(); it++) {
		str.replace(*it, 1, "?");
	}
	//replace(인덱스, 몇글자, "대체문자")

	cout << str;

	return 0;
}