#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	
	int cnt = 50;

	for (int i = 0; i < b.length() - a.length() + 1; i++) {
		string str = b.substr(i, a.length());
		int now = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != str[j]) now++;
		}
		cnt = min(cnt, now);
	}

	cout << cnt;
}