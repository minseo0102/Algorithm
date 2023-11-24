#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) {
			return true;//swap
		}
		else if (abs(a) == abs(b)) {
			if (a > b) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
};
int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int,vector<int>, compare> pq;
	
	int a,b;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> b;
		if (b != 0) {
			pq.push(b);
		}
		else
		{
			if (pq.empty()) {
				cout << 0<<"\n";
			}
			else
			{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
	}
}