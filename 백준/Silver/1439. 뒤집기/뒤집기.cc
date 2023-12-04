#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int count=0;
	char now = str[0];
	for (int i = 1; i < str.length(); i++) {
		if (now != str[i]) {
			count++;
			now = str[i];
		}
	}

	if (count % 2 == 1) {
		count /= 2;
		count++;
	}
	else {
		count /= 2;
	}

	cout << count;

	return 0;
}