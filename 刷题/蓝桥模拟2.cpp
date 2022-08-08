// 1、 539077581





















































































































































// 2、  3
//#include <iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//
//int main() {
//	int ans = 0;
//	for (int i = 1; i <= 2021; i++) {
//		if (lcm(i, 2021) == 4042)
//			ans++, cout << i << endl;
//	}
//	cout << ans << endl;
//	return 0;
//}












































































// 3、 624
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool f(int n) {
//	for (int i = 1; i <= n / i; i++) {
//		int k = n - i * i;
//		int s = sqrt(k);
//		if (s * s == k)	{
//			cout << n << " = " << i << " " << s << endl;
//			return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//	int ans = 0;
//	for (int i = 1; i <= 2021; i++) {
//		if (f(i))
//			ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}
































































// 4、最小生成树：待定
//#include <iostream>
//using namespace std;
//const int N = 15, INF = 0x3f3f3f3f;
//int dist[N];
//bool st[N];
//
//int prim() {
//
//
//}
//
//int main() {
//
//	return 0;
//}

























































// 5、 前缀和 154
//#include <iostream>
//using namespace std;
//const int N = 21;
//int g[N][N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//               0, 6, 9, 8, 5, 9, 2, 4, 1, 8, 3, 9, 3, 8, 7, 8, 6, 8, 9, 4, 1,
//               0, 1, 7, 6, 1, 5, 8, 7, 6, 9, 6, 3, 1, 3, 1, 7, 5, 9, 2, 8, 4,
//               0, 3, 7, 3, 4, 7, 3, 4, 8, 3, 2, 6, 6, 2, 7, 4, 8, 3, 4, 8, 5,
//               0, 5, 3, 6, 7, 1, 2, 5, 6, 5, 5, 6, 1, 6, 7, 8, 6, 4, 7, 4, 3,
//               0, 1, 6, 1, 2, 1, 6, 8, 6, 9, 2, 7, 4, 3, 2, 3, 2, 9, 4, 7, 9,
//               0, 1, 3, 5, 4, 7, 4, 1, 3, 3, 4, 9, 9, 6, 2, 7, 7, 3, 4, 4, 7,
//               0, 2, 7, 9, 7, 9, 9, 4, 5, 9, 2, 9, 8, 4, 8, 8, 2, 4, 6, 8, 7,
//               0, 5, 3, 7, 7, 6, 9, 8, 3, 3, 4, 6, 8, 3, 8, 7, 9, 1, 3, 7, 9,
//               0, 5, 6, 4, 9, 3, 4, 2, 1, 3, 6, 5, 3, 6, 5, 7, 1, 7, 7, 4, 5,
//               0, 2, 1, 9, 2, 4, 3, 7, 9, 2, 9, 3, 8, 7, 2, 6, 1, 1, 3, 8, 2,
//               0, 9, 3, 9, 1, 9, 3, 5, 3, 2, 1, 6, 2, 4, 3, 5, 6, 1, 2, 7, 7,
//               0, 5, 4, 2, 9, 6, 1, 4, 4, 7, 6, 3, 9, 6, 9, 2, 5, 7, 7, 8, 8,
//               0, 9, 6, 2, 3, 3, 9, 7, 2, 5, 1, 3, 7, 9, 4, 7, 3, 2, 9, 3, 3,
//               0, 8, 1, 4, 4, 3, 4, 9, 4, 5, 3, 3, 1, 2, 9, 9, 3, 9, 9, 7, 5,
//               0, 6, 1, 1, 7, 1, 8, 8, 2, 9, 8, 8, 8, 7, 7, 5, 9, 3, 4, 9, 9,
//               0, 6, 1, 2, 1, 6, 8, 6, 8, 8, 9, 5, 7, 2, 1, 3, 4, 8, 5, 2, 2,
//               0, 5, 5, 4, 8, 5, 3, 4, 5, 9, 5, 9, 2, 9, 4, 7, 2, 6, 8, 9, 6,
//               0, 3, 2, 1, 2, 4, 9, 6, 3, 3, 1, 8, 2, 4, 2, 5, 5, 4, 9, 2, 2,
//               0, 1, 3, 5, 9, 3, 6, 4, 7, 1, 9, 1, 9, 3, 4, 2, 7, 2, 6, 9, 6,
//               0, 5, 6, 4, 3, 6, 8, 9, 5, 9, 4, 4, 9, 1, 9, 8, 9, 9, 2, 4, 6
//              };
//
//int s[N][N]; // s[i][j]以 ij为右下角的子矩阵的和
//int main() {
//	for (int i = 1; i <= 20; i++) {
//		for (int j = 1; j <= 20; j++)
//			cout << g[i][j] << " ";
//		cout << endl;
//	}
//
//
//	for (int i = 1; i <= 20; i++)
//		for (int j = 1; j <= 20; j++)
//			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j]; // 前缀和
//
//	int ma = 0;
//	for (int i = 5; i <= 20; i++)
//		for (int j = 5; j <= 20; j++)
//			ma = max(ma, s[i][j] - s[i - 5][j] - s[i][j - 5] + s[i - 5][j - 5]);
//	cout << ma;
//	return 0;
//}

// 6、
//#include <iostream>
//using namespace std;
//
//int main() {
//	int t, a, p, s = 0;
//	scanf("%d %d %d", &t, &a, &p);
//	if (t % a)
//		s = t / a + 1; // 总共的页数
//	if (p < s)
//		cout << a * (p - 1) + 1 << " " << a *p << endl;
//	else
//		cout << a * (p - 1) + 1 << " " << t << endl;
//	return 0;
//}

// 7、
//#include <iostream>
//using namespace std;
//bool flag;
//int main() {
//	int n, t = 10;
//	scanf("%d", &n);
//	while (n) {
//		if ((n % 10) >= t) {
//			flag = true;
//			break;
//		}
//		t = n % 10;
//		n /= 10;
//	}
//	if (flag)
//		puts("NO");
//	else
//		puts("YES");
//	return 0;
//}
































































// 9、
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int res[25];
//struct sco {
//	int g;
//	int who;
//	bool operator < (const sco &t) const {
//		return g == t.g ? who < t.who : g > t.g;
//	}
//};
//vector<sco> score[25];
//
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			int w;
//			cin >> w;
//			score[j].push_back({w, i});  // i是人的编号, j是比赛的编号
//		}
//	}
//	for (int j = 1; j <= m; j++) {
//		sort(score[j].begin(), score[j].end());
//		int p = 1;
//		for (auto t : score[j]) {
//			int per = t.who;
//			res[per] += (k - p + 1);
//			p++;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		cout << res[i] << " ";
//	return 0;
//}

// 10、
//#include <iostream>
//using namespace std;
//
//int main() {
//
//	return 0;
//}














































// *数字三角形*
//#include <iostream>
//using namespace std;
//const int N = 110;
//int n;
//int a[N][N];
//
//struct Node {
//	int v;
//	int l = 0;
//	int r = 0;
//} f[N][N];
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= i; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	f[1][1].v = a[1][1];
//	for (int i = 2; i <= n; i++)
//		for (int j = 1; j <= i; j++) {
//			if (f[i - 1][j - 1].v > f[i - 1][j].v) {
//				f[i][j].v += f[i - 1][j - 1].v + a[i][j];
//				f[i][j].l = f[i - 1][j - 1].l;
//				f[i][j].r = f[i - 1][j - 1].r + 1;
//			} else {
//				f[i][j].v += f[i - 1][j].v + a[i][j];
//				f[i][j].r = f[i - 1][j].r;
//				f[i][j].l = f[i - 1][j].l + 1;
//			}
//		}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (abs(f[n][i].l - f[n][i].r) <= 1)
//			ans = max(ans, f[n][i].v);
//	}
//	cout << ans << endl;
//	return 0;
//}







































//#include <iostream>
//using namespace std;
//
//int get_maxyue(int n) {
//	for (int i = 2; i * i <= n; i++) {
//		if (n % i == 0) {
//			return n / i;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	if (n == 1)
//		puts("-1");
//	else {
//		int res = 0;
//		while (n != 1) {
//			n = get_maxyue(n);
//			res += n;
//		}
//		cout << res << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <queue>
using namespace std;
const int N = 310;
char g[N][N];
int n, k;
bool st[N][N];
typedef struct Node {
	int x, y, time; // 坐标和当前的时间
} pos;

int dir[3] = {2, 1, 0}; // 半径
int dre[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int bfs() {
	queue<pos> q;
	q.push({3, 3, 0});
	st[3][3] = true;

	while (q.size()) {
		auto t = q.front();
		q.pop();
		if (t.x == n - 2 && t.y == n - 2)
			return t.time;
		q.push({t.x, t.y, t.time + 1}); // 原地不动
		for (int i = 0; i < 4; i++) {
			int nx = t.x + dre[i][0], ny = t.y + dre[i][1];
			if (st[nx][ny])
				continue;
			// 求出胖子的半径
			int r = t.time / k >= 2 ? 0 : dir[t.time / k];
			if (nx - r < 1 || nx + r > n || ny - r < 1 || ny + r > n)
				continue;
			bool flag = false; // 判断身体区域内有没有障碍物
			for (int sx = nx - r; sx <= nx + r; sx++)
				for (int sy = ny - r; sy <= ny + r; sy++) {
					if (g[sx][sy] == '*') {
						flag = true;
						break;
					}
				}
			if (flag)
				continue;
			st[nx][ny] = true;
			q.push({nx, ny, t.time + 1});
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		cin >> g[i] + 1;
	cout << bfs() << endl;
	return 0;
}