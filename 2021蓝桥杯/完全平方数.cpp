// 完全平方数
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;







//const int N = 10010;
//int dp[N];
//
//int min(int a, int b) {
//	return a > b ? b : a;
//}
////vector<int> yin;
//int main() {
//	dp[0] = 0;
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		dp[i] = i; // 关键初始化
//		for (int j = 1; j <= sqrt(i); j++)
//			if(dp[i - j * j] + 1 < dp[i]) {
//				dp[i] = dp[i - j * j] + 1;
//			}
////			dp[i] = min(dp[i - j * j] + 1, dp[i]);
//	}
//	cout << dp[n];
//	return 0;
//}
int maxa = 0x7fffffff;

bool isP(int n) {
	int num = 1;
	while (n > 0) {
		n = n - num;
		num += 2;
	}
	if (n == 0)
		return true;
	return false;
}

int main() {
	for (int i = 1; i < maxa; i++) {
		if (isP(100 + i) && isP(168 + i)) {
			cout << i;
			break;
		}
	}
	return 0;
}