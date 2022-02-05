// 3181

//#include <iostream>
//using namespace std;
//int cnt[10];
//
//int main() {
//	for (int i = 0; i <= 9; i++)
//		cnt[i] = 2021;
//
//	for (int i = 1; ; i++) {
//
//		int t = i;
//		while (t) {
//			int a = t % 10;
//			if (!cnt[a]) {
//				cout << i << endl; // 3182拼不了
//				return 0;
//			}
//			cnt[a]--;
//			t /= 10;
//		}
//	}
//	return 0;
//}





























// 答案：40257
// 直线一般方程：(y1-y2)x + (x2-x1)y + x1y2 - x2y1 = 0
//#include <iostream>
//#include <set>
//#include <cmath>
//#include <unordered_set>
//#include <vector>
//#define x first
//#define y second
//using namespace std;
//const int N = 500;
//using T = pair<int, int>;
//vector<T> p;
//
//
//struct Line {
//	int a, b, c;
//	bool operator < (const Line &t) const {
//		if (a == t.a)
//			return b == t.b ? c < t.c : b < t.b;
//		return a < t.a;
//	}
//
//	bool operator == (const Line &t) const {
//		if (a == t.a && b == t.b && c == t.c)
//			return true;
//		return false;
//	}
//};
//set<Line> ss;
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int gcdd(int a, int b, int c) {
//	return gcd(gcd(a, b), c);
//}
//
//int main() {
//	for (int i = 0; i <= 19; i++)
//		for (int j = 0; j <= 20; j++) {
//			p.push_back({i, j}); // 记录点的坐标
//		}
//
//	int n = p.size() - 1;
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j <= n; j++) {
//			int a = p[i].y - p[j].y;
//			int b = p[j].x - p[i].x;
//			int c = p[i].x * p[j].y - p[j].x * p[i].y;
//			int d = gcdd(fabs(a), fabs(b), fabs(c));
//			ss.insert({a / d, b / d, c / d});
//		}
//	cout << ss.size();
//	return 0;
//}





























//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int N = 2100;
//int g[N][N], dist[N];
//bool st[N];
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//
//int dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0; i < 2021; i++) {
//		int t = -1;
//		// 找出距离起点最段距离的点
//		for (int j = 1; j <= 2021; j++) {
//			if (!st[j] && (t == -1 || dist[j] < dist[t]))
//				t = j;
//		}
//		st[t] = true;
//		// 用最近的点去更新其他点到起点的距离
//		for (int i = 1; i <= 2021; i++)
//			dist[i] = min(dist[t] + g[t][i], dist[i]);
//
//	}
//	return dist[2021];
//}
//
//int main() {
//	memset(g, 0x3f, sizeof g);
//	for (int i = 1; i <= 2021; i++)
//		g[i][i] = 0;
//	for (int i = 1; i < 2021; i++)
//		for (int j = i + 1; j <= 2021; j++) {
//			if (j - i <= 21 && i != j) // 不能是同一个点
//				g[i][j] = g[j][i] = lcm(i, j);
//		}
//	cout << dijkstra();
////	cout << dist[2021] << endl;
//	return 0;
//}



// 直线2
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//using namespace std;
//using T = pair<int, int>;
//
//struct line {
//	double k; // 斜率
//	double b; // 截距
//	bool operator < (const line &t) const {
//		if (k != t.k)
//			return k < t.k;
//		return b < t.b;
//	}
//};
//vector<T> P; // 存储点
//vector<line> Line;
//
//int main() {
//	for (int i = 0 ; i < 20; i++)
//		for (int j = 0; j < 21; j++) {
//			P.push_back({i, j});
//		}
//	int n = P.size() - 1;
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= n; j++) {
//			int x1 = P[i].first, x2 = P[j].first;
//			int y1 = P[i].second, y2 = P[j].second;
//			// 斜率存在时
//			if (x1 != x2) {
//				double k = (double)(y1 - y2) / (x1 - x2);
//				double b = y2 - k * x2;
//				Line.push_back({k, b});
//			}
//		}
//	sort(Line.begin(), Line.end());
//	int res = 1;
//	for (int i = 1; i < Line.size(); i++) {
//		if (fabs(Line[i].k - Line[i - 1].k) > 1e-8 || fabs(Line[i].b - Line[i - 1].b) > 1e-8)
//			res++;
//	}
//	cout << res + 20 << endl; // 还要加上竖直的没有斜率的直线
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int f[N][N]; // f[i][j]从 1-i 中选数总和为 j 的方案数
int mod = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		f[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if (j >= i)
				f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
			else
				f[i][j] = f[i - 1][j] % mod;
		}
	cout << f[n][n] << endl;
	return 0;
}


