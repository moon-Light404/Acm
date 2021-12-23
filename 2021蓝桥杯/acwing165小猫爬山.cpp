#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25;
int w[N], sum[N]; // 小猫重量, 每辆小车猫得重量
int n, m;
int ans = N;

// 现在处理第u只猫，d 表示第d个轮椅还没放(前d-1个轮椅已经放好)
void dfs(int u, int d) {
	if (d >= ans)
		return;
	if (u > n) {
		ans = d;
		return;
	}
	// 在已有的车 1~d-1 中选一辆放小猫
	for (int i = 1; i < d; i++) {
		if (sum[i] + w[u] <= m) {
			sum[i] += w[u];
			dfs(u + 1, d);
			sum[i] -= w[u];
		}
	}
	// 新开一辆车
	sum[d] = w[u];
	dfs(u + 1, d + 1);
	sum[d] = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	sort(w + 1, w + n + 1);
	reverse(w + 1, w + n + 1);
	dfs(1, 1); // 从第1只小猫开始搜索
	cout << ans - 1  << endl;
	return 0;
}