// ���P1352û����˾�����
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 6010;
//int h[N], e[N], ne[N], idx, w[N];
//int n;
//int f[N][2], st[N];
//
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//
//void dfs(int u) {
//	f[u][1] = w[u], f[u][0] = 0; // ��ʼ����� u ѡ���߲�ѡ
//	for (int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		dfs(j);
//		f[u][0] += max(f[j][1], f[j][0]);
//		f[u][1] += f[j][0];
//	}
//}
//
//int main() {
//	memset(h, -1, sizeof h);
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> w[i];
//	for (int i = 0; i < n - 1; i++) {
//		int a, b;
//		cin >> a >> b;
//		add(b, a); // bָ��a
//		st[a] = true; // �и��ڵ�
//	}
//	int u = 1;
//	for (int i = 1; i <= n; i++) {
//		if (!st[i]) {
//			u = i;
//			break;
//		}
//	}
//	dfs(u);
//	cout << max(f[u][0], f[u][1]) << endl;
//	return 0;
//}

// https://vjudge.net/problem/POJ-1463ս�Բ���
