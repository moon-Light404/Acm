// 记忆化搜索


















//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int N = 310;
//int h[N][N]; // 高度
//int n, m;
//
//int f[N][N]; // 从(i,j)出发可以滑行的最大高度
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//
//int dp(int x, int y) {
//	int &v = f[x][y];
//	if (v != -1)
//		return v;
//	v = 1;
//
//	for (int i = 0; i < 4; i++) {
//		int a = x + dir[i][0], b = y + dir[i][1];
//		if (a < 1 || a > n || b < 1 || b > m || h[a][b] > h[x][y])
//			continue;
//		v = max(v, dp(a, b) + 1);
//	}
//	return v;
//}
//
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			scanf("%d", &h[i][j]);
//	memset(f, -1, sizeof f);
//	int res = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			res = max(res, dp(i, j));
//	printf("%d\n", res);
//	return 0;
//}









// 洛谷Function
//#include <iostream>
//#include <cstring>
//using namespace std;
//typedef long long LL;
//LL f[25][25][25];
//
//LL dp(LL x, LL y, LL k) {
////	LL &v = ;
//	if (x <= 0 || y <= 0 || k <= 0)
//		return 1;
//	else if (f[x][y][k] != 0)
//		return f[x][y][k]; // 已经计算过
//	else if (x > 20 || y > 20 || k > 20)
//		f[x][y][k] = dp(20, 20, 20);
//
//	else if (x < y && y < k)
//		f[x][y][k] = dp(x, y, k - 1) + dp(x, y - 1, k - 1) - dp(x, y - 1, k);
//	else
//		f[x][y][k] = dp(x - 1, y, k) + dp(x - 1, y - 1, k) + dp(x - 1, y, k - 1) - dp(x - 1, y - 1, k - 1);
//	return f[x][y][k];
//}
//
//int main() {
//	LL a, b, c;
//	while (scanf("%lld%lld%lld", &a, &b, &c)) {
//
//		if (a == -1 && b == -1 && c == -1)
//			break;
//		printf("w(%lld，%lld，%lld) = ", a, b, c);
//		if (a > 20)
//			a = 21;
//		if (b > 20)
//			b = 21;
//		if (c > 20)
//			c = 21;
//		LL ans = dp(a, b, c);
//		printf("%lld\n", ans);
//	}
//	return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct zzz {
	int t, nex;
} e[500010 << 1];
int head[500010], tot;

void add(int x, int y) {
	e[++tot].t = y;
	e[tot].nex = head[x];
	head[x] = tot;
}
int depth[500001], fa[500001][22], lg[500001];

void dfs(int now, int fath) {
	fa[now][0] = fath;
	depth[now] = depth[fath] + 1;
	for (int i = 1; i <= lg[depth[now]]; ++i)
		fa[now][i] = fa[fa[now][i - 1]][i - 1];
	for (int i = head[now]; i; i = e[i].nex)
		if (e[i].t != fath)
			dfs(e[i].t, now);
}

int LCA(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);
	while (depth[x] > depth[y])
		x = fa[x][lg[depth[x] - depth[y]] - 1];
	if (x == y)
		return x;
	for (int k = lg[depth[x]] - 1; k >= 0; --k)
		if (fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int main() {
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; ++i)
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs(s, 0);
	cout << fa[4][lg[depth[4]] - 1] << endl;
	cout << fa[5][lg[depth[5]] - 1] << endl;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", LCA(x, y));
	}
//5 1 1
//1 2
//1 3
//2 4
//3 5
	return 0;
}