
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2100;
int g[N][N], dist[N];
bool st[N];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < 2021; i++) {
		int t = -1;
		// �ҳ����������ξ���ĵ�
		for (int j = 1; j <= 2021; j++) {
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		st[t] = true;
		// ������ĵ�ȥ���������㵽���ľ���
		for (int i = 1; i <= 2021; i++)
			dist[i] = min(dist[t] + g[t][i], dist[i]);

	}
	return dist[2021];
}

int main() {
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= 2021; i++)
		g[i][i] = 0;
	for (int i = 1; i < 2021; i++)
		for (int j = i + 1; j <= 2021; j++) {
			if (j - i <= 21 && i != j) // ������ͬһ����
				g[i][j] = g[j][i] = lcm(i, j);
		}
	cout << dijkstra();
//	cout << dist[2021] << endl;
	return 0;
}
