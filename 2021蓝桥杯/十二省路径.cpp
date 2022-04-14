#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 2050;
int g[N][N];
const int inf = 0x3f3f3f3f;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	int gc = gcd(a, b);
	return a * b / gc;
}

// 绝对值小于等于21
bool f(int a, int b) {
	if (abs(a - b) <= 21)
		return true;
	return false;
}

//int dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
////	st[1] = true;
//	for (int i = 0; i < 2020; i++) {
//		int t = -1;
//		for (int j = 1; j <= 2021; j++) {
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		}
//
//		for (int j = 1; j <= 2021; j++)
//			if (!st[j])
//				dist[j] = min(dist[j], dist[t] + g[t][j]);
//		st[t] = true;
//	}
//	if (dist[2021] == 0x3f3f3f3f)
//		return -1;
//	return dist[2021];
//}

void floyd() {
	for (int k = 1; k <= 2021; k++)
		for (int j = 1; j <= 2021; j++)
			for (int  i = 1; i <= 2021; i++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

}

int main() {
	for (int i = 1; i <= 2021; i++)
		for (int j = 1; j <= 2021; j++)
			g[i][j] = (i == j ? 0 : inf);
	for (int i = 1; i < 2021; i++)
		for (int j = i + 1; j <= 2021; j++) {
			if (f(i, j))
				g[i][j] = g[j][i] = lcm(i, j);

		}
//	cout << dijkstra();
	floyd();
	cout << g[1][2021] << endl;
	return 0;
}