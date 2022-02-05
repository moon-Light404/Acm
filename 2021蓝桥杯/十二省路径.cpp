#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 2050;
int g[N][N];
int dist[N];
bool st[N];

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

int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
//	st[1] = true;
	for (int i = 0; i < 2020; i++) {
		int t = -1;
		for (int j = 1; j <= 2021; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}

		for (int j = 1; j <= 2021; j++)
			if (!st[j])
				dist[j] = min(dist[j], dist[t] + g[t][j]);
		st[t] = true;
	}
	if (dist[2021] == 0x3f3f3f3f)
		return -1;
	return dist[2021];
}

int main() {
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i < 2021; i++)
		for (int j = i + 1; j <= 2021; j++) {
			if (f(i, j))
				g[i][j] = g[j][i] = lcm(i, j);

		}
	cout << dijkstra();
	return 0;
}