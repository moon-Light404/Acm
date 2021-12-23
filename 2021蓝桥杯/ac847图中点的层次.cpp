#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m;
int e[N], h[2 * N + 1], ne[N], idx;
queue<int> q;
int d[N];
bool st[N];
void add(int a, int b) {
	e[idx] = b; // 边的终点
	ne[idx] = h[a];
	h[a] = idx++;
}

void bfs(int u) {
	q.push(u);
	d[u] = 0;
	st[u] = true;
	while (!q.empty()) {
		int s = q.front(); // 取出队头
		q.pop();
		// 从s出发的边
		for (int i = h[s]; i != -1; i = ne[i]) {
			int j = e[i]; // 记录终点
			if (!st[j]) {
				q.push(j);
				d[j] = d[s] + 1;
				st[j] = true; // 标记访问过
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);
	memset(d, 0x3f3f3f3f, sizeof d);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	bfs(1);
	if (d[n] != 0x3f3f3f3f)
		cout << d[n] << endl;
	else
		cout << "-1" << endl;


	return 0;
}