#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25;
int w[N], sum[N]; // Сè����, ÿ��С��è������
int n, m;
int ans = N;

// ���ڴ����uֻè��d ��ʾ��d�����λ�û��(ǰd-1�������Ѿ��ź�)
void dfs(int u, int d) {
	if (d >= ans)
		return;
	if (u > n) {
		ans = d;
		return;
	}
	// �����еĳ� 1~d-1 ��ѡһ����Сè
	for (int i = 1; i < d; i++) {
		if (sum[i] + w[u] <= m) {
			sum[i] += w[u];
			dfs(u + 1, d);
			sum[i] -= w[u];
		}
	}
	// �¿�һ����
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
	dfs(1, 1); // �ӵ�1ֻСè��ʼ����
	cout << ans - 1  << endl;
	return 0;
}