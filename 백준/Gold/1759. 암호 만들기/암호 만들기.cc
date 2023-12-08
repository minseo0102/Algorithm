#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<string> res;
void des(vector<string> alp, string sum, int cnt) {
	if (sum.length() == L) {
		res.push_back(sum);
		return;
	}
	if (cnt < C) {
		des(alp, sum + alp[cnt], cnt + 1);
		des(alp, sum, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	vector<string> alp;
	for (int i = 0; i < C; i++) {
		string ch;
		cin >> ch;
		alp.push_back(ch);
	}

	sort(alp.begin(), alp.end());

	des(alp, "", 0);
	
	
	for (int i = 0; i < res.size(); i++) {
		int moem=0;
		int jaem = 0;
		for (int j = 0; j < res[i].length(); j++) {
			if (res[i][j] == 'a' || res[i][j] == 'e' || res[i][j] == 'i' || res[i][j] == 'o' || res[i][j] == 'u') moem++;
			else jaem++;

			if (moem >= 1 && jaem >= 2) {
				cout << res[i] << "\n";
				break;
			}
		}
	}

	return 0;
}