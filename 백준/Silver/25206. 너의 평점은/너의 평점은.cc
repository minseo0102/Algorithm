#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	float sum = 0;//총 들은 학점 합계
	float grade=0;//학점*성적의 합

	for (int i = 0; i < 20; i++) {
		string str;
		float div;//학점
		string point;//성적

		cin >> str >> div >> point;

		if (point != "P") {
			if (point == "A+") grade += 4.5*div;
			else if (point == "A0") grade += 4.0*div;
			else if (point == "B+") grade += 3.5*div;
			else if (point == "B0") grade += 3.0*div;
			else if (point == "C+") grade += 2.5*div;
			else if (point == "C0") grade += 2.0*div;
			else if (point == "D+") grade += 1.5*div;
			else if (point == "D0") grade += 1.0*div;

			sum += div;
		}
	}

	printf("%.6lf", grade / sum);

	return 0;
}