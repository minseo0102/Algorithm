#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int s, e;
int sn, en;
int answer;

void func() {
	for (int i = sn; i < en; i++) {
		s += i;
	}
	int end = s + (en - sn);
	//s와 end의 범위는 가로 이동 범위

	for (int i = s; i <= end; i++) {
		answer = min(answer, abs(i - e));//최종 e까지 가로 이동 횟수 최소 구하기
	}
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
		if (sn*(sn + 1) / 2 < s) sn++;

		en = sqrt(e * 2);
		if (en*(en + 1) / 2 < e) en++;

		//en-sn 만큼 연산할것

		answer = 100000;

		func();

		answer += (en - sn);

		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}
