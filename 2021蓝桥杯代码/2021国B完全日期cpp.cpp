/*
答案977
*/
#include <iostream>
#include <cmath>
using namespace std;
const int N = 10010;
bool f[N];

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year) { // 闰年
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool check(int year, int m, int d) {
	// 求各位之和
	int sum = 0;
	while (year) {
		sum += year % 10;
		year /= 10;
	}
	while (m) {
		sum += m % 10;
		m /= 10;
	}
	while (d) {
		sum += d % 10;
		d /= 10;
	}
	if (f[sum]) {
		cout << sum << " ";
		return true;

	}

	return false;

}

void init() {
	f[1] = 1;
	for (int i = 2; i * i <= N; i++) {
		f[i * i] = 1; // 完全平方数
	}
}

int main() {
	int res = 0;
	init();
	for (int i = 2001; i <= 2021; i++) {
		if (is_leap(i))
			day[2]++;
		for (int j = 1; j <= 12; j++) {
			for (int k = 1; k <= day[j]; k++)
				if (check(i, j, k)) {
					res++;
				}

		}
		day[2] = 28; // 恢复2月份的日期
	}
	cout << res;


	return 0;
}