#include <iostream>
using namespace std;
const int M = 1000;
const int N = 1000;

int n, m;       // n表示点数，m表示边数
int dist[N];        // dist[x]存储1到x的最短路距离
int backup[N]; // 拷贝数组,这样就保证轮数与边数一致
struct Edge {   // 边，a表示出点，b表示入点，w表示边的权重
	int a, b, w;
} edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	// 初始时，1号点到其他点的距离为inf
	dist[1] = 0;

	// 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
	for (int i = 0; i < n; i ++ ) {
		memcpy(backup, dist, sizeof dist); // 拷贝数组,因为更新其他点时候会影响其他点的更新信息
		for (int j = 0; j < m; j ++ ) { // 遍历每条边边
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			if (dist[b] > backup[a] + w)
				dist[b] = backup[a] + w;
		}
		for (int k = 1; k <= n; k++)
			cout << dist[k] << "   ";
		cout << endl;
	}

	if (dist[n] > 0x3f3f3f3f / 2)
		return -1;
	return dist[n];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w}; // 构造一条边
	}
	bellman_ford();
	return 0;
	/*输出
	5 8
	1 2 -1
	1 3 4
	2 5 2
	2 4 2
	4 2 1
	5 4 -3
	4 3 5
	2 3 3
	0   -1   4   1061109564   1061109567
	0   -1   2   1   1
	0   -1   2   -2   1
	0   -1   2   -2   1
	0   -1   2   -2   1
	*/
}
