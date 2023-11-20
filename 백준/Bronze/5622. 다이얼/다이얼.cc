#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int time[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	char in[16];
	cin >> in;
	int size = strlen(in);
	int sec=0;
	for (int i = 0; i < size; i++) {
		sec += time[in[i] - 65];
	}
	cout << sec;
	return 0;
	
}