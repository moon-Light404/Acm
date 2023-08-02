// 模板复习
#include <iostream>
using namespace std;






// 快速幂 a^b % mod
//int get_pow(int a, int b, int mod) {
//	int ans = 1;
//	while (b) {
//		if (b & 1)
//			ans = ans * a % mod;
//		a = a *  a % mod;
//		b >>= 1;
//	}
//	return ans;
//}
//
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	cout << get_pow(n, m, k) << endl;
//	return 0;
//}

// itoa函数
int main() {
	int n;
	while (cin >> n) {
		char a[100];
		itoa(n, a, 3);
		cout << a << endl;
	}

	return 0;
}


