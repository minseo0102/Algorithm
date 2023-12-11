#include<iostream>
#include<deque>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	deque<int> d;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		d.push_back(i+1);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		deque<int> dr(d);
		deque<int> dl(d);
		int rcnt = 0;
		int lcnt = 0;

		while (dr.front() != num) {
			dr.push_back(dr.front());
			dr.pop_front();
			rcnt++;
		}
		while (dl.front() != num) {
			dl.push_front(dl.back());
			dl.pop_back();
			lcnt++;
		}

		if (num == d.front()) {
			d.pop_front();
		}
		else if (rcnt >= lcnt) {
			while (d.front() != num) {
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
			d.pop_front();
		}
		else if (rcnt < lcnt) {
			while (d.front() != num) {
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
			d.pop_front();
		}
	}

	cout << cnt;

	return 0;
}