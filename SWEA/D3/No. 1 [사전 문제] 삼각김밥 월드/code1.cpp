#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int s, e;
int sn, en;
int answer;

void func(int n, int now) {
	if (n == en) {
		answer = min(answer, abs(e - now));
		return;
	}

	func(n + 1, now + n);
	func(n + 1, now + n + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> s >> e;

		if (s > e) {//작은 것을 시작으로 두자
			int temp = e;
			e = s;
			s = temp;
		}

		sn = sqrt(s * 2);
		if (sn*(sn + 1)/2 < s) sn++;

		en = sqrt(e * 2);
		if (en*(en + 1)/2 < e) en++;

		//en-sn 만큼 연산할것

		answer = 100000;

		func(sn, s);

		answer += (en - sn);

		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}
