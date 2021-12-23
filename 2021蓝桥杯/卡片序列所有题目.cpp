// 卡片













//#include <iostream>
//using namespace std;
//int a[10];
//
//int main() {
//	for (int i = 0; i < 10; i++)
//		a[i] = 2021;
//	int s = 1;
//	bool flag = true;
//	int tmp;
//	while (flag) {
//		tmp = s;
//		while (tmp) {
//			int d = tmp % 10;
//			if (a[d] <= 0) {
//				flag = false;
//				break;
//			}
//			a[d]--;
//			tmp /= 10;
//		}
//		s++;
//	}
//	cout << (s - 2);
//	return 0;
//}
//
//#include <iostream>
//#include <set>
//#include <cmath>
//#define x first
//#define y second
//using namespace std;
//typedef pair<int, int> PII;
//PII p[1000];
//struct line {
//	int a, b, c; // 直线的系数
//	bool operator <(const line &p) const {
//		if (a == p.a)
//			return b == p.b ? c < p.c : b < p.b;
//		return a < p.a;
//	}
//	bool operator ==(const line &p) const {
//		return a == p.a && b == p.b && c == p.c;
//	}
//};
//int cnt;
//
//set<line> se; // 存储直线去重
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int gcdd(int a, int b, int c) {
//	return gcd(gcd(a, b), c);
//}
//
//int main() {
//	int n = 20, m = 21;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			p[++cnt] = {i, j}; // 记录每个点
//		}
//	for (int i = 1; i <= cnt; i++)
//		for (int j = i + 1; j <= cnt; j++) {
//			int a = p[i].y - p[j].y;
//			int b = p[j].x - p[i].x;
//			int c = p[i].y * (p[i].x - p[j].x) + p[i].x * (p[j].y - p[i].y);
//			int t = gcdd(fabs(a), fabs(b), fabs(c));
//			se.insert({a / t, b / t, c / t});
//		}
//	cout << se.size();
//	return 0;
//}




// 3.货物摆放

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL yue[101000], cnt;

int main() {
	LL n = 2021041820210418;
	for (LL i = 1; i <= n / i; i++) { // 求所有的约数
		if (n % i == 0) {
			yue[++cnt] = i;
			if (i * i != n)
				yue[++cnt] = n / i;
		}
	}
	sort(yue + 1, yue + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		cout << yue[i] << endl;
	cout << cnt << endl;
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			if (n % (yue[i]*yue[j]) == 0)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
