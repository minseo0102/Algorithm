#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int temp = 0;
	int res = 0;
	//한번 마이너스가 발생하고 나면 그 뒤로는 +에 대해서는 다 -로 묶을수 있으니까 마이너스 발생 후에는 모두 -로 계산

	vector<int> arr;
	int cnt = 0;
	int cntbreak = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '+'&&str[i] != '-') {//숫자이면
			temp *= 10;
			temp += str[i] - '0';
		}
		else {
			arr.push_back(temp);
			temp = 0;

			if (!cntbreak&&str[i] == '+') cnt++;
			else if (str[i] == '-') cntbreak = true;
		}
	}

	arr.push_back(temp);

	for (int i = 0; i < arr.size(); i++) {
		if (i <= cnt) {
			res += arr[i];
		}
		else {
			res -= arr[i];
		}
	}

	cout << res;

	return 0;
}