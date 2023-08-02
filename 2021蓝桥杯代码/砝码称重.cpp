//// 砝码沉重
////1 4 6
////1 4 6 3 5 11 2 7 10 9
#include <iostream>
#include <cmath>
using namespace std;
// dp[i][j]表示前i种砝码是否可以称出j重量来 t or f
const int M = 100005;
bool dp[106][M];

int a[M]; // 每个砝码的重量
int main() {
	int N, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= N; i++) { // 前i个砝码
		for (int j = 1; j <= sum; j++) { // 1~sum的重量
			dp[i][j] = dp[i - 1][j];
			if (!dp[i][j]) {
				if (a[i] == j)
					dp[i][j] = true;
				if (dp[i - 1][j + a[i]])
					// 上一个状态可以称出比j大a[i]的重量，这个状态只要把a[i]放在不同侧就可以称出j重量
					dp[i][j] = true;
				if (dp[i - 1][abs(j - a[i])])
					// 上一状态可以称出比j小a[i]的重量,这此只要把a[i]放在同侧就可以称出j重量
//				j = 10, a[i] = 6, dp[i-1][4] = 1,可以放6即可称出10,设左边比右边重4(+4),左边再加6就是(+10)
//				j = 6, a[i] = 10,dp[i-1][4] = 1,上一个状态可以称出4(-4),设左边比右边轻4(-4),左边加上10后就是+6
					dp[i][j] = true;
			}
		}
	}
	long long ans = 0;
	for (int k = 1; k <= sum; k++) { // 遍历总重量,前N个砝码可以称到的重量
		if (dp[N][k])
			ans++;
	}
	cout << ans << endl;

	return 0;
}

