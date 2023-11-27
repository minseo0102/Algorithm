#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--) {
		string f;
		cin >> f;
		int size;
		cin >> size;
		deque<int> d;

		string arr;
		cin >> arr;

		int i = 0;
		while (arr[i]!='\0') {
			int num = 0;
			while (arr[i] >= '0'&&arr[i] <= '9') {
				num *= 10;
				num += (arr[i]-'0');
				i++;
			}
			if (num != 0) {
				d.push_back(num);
			}
			i++;
		}

		i = 0;
		bool exit = false;
		bool rl = false;
		while (f[i]!='\0') {
			if (f[i] == 'R') {
				rl = !rl;
			}
			else if (f[i] == 'D') {
				if (d.empty()) {
					cout << "error" << "\n";
					exit = true;
					break;
				}
				else {
					if (rl) {
						d.pop_back();
					}
					else {
						d.pop_front();
					}
				}
			}
			i++;
		}

		if (exit == false) {
			cout << "[";
		}
		while (!d.empty()) {
			if (!rl) {
				cout << d.front();
				d.pop_front();
			}
			else {
				cout << d.back();
				d.pop_back();
			}
			if (!d.empty()) {
				cout << ",";
			}
		}
		if (exit == false) {
			cout << "]" << "\n";
		}
	}
	return 0;
}