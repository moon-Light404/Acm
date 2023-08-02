#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100010;
int a[N];
int n, m;

int quick_select(int p[], int l, int r, int k) {
	cout << l;
	if (l >= r)
		return p[l];
	int i = l - 1, j = r + 1;
	int x = p[l + r >> 1];
	while (i < j) {
		do
			i++;
		while (p[i] < x);
		do
			j--;
		while (p[i] > x);
		if (i < j)
			swap(p[i], p[j]);
	}
	// k < ��ߵ�������˵����k���������
	if (k <= j - l + 1)
		return quick_select(p, l, j, k);
	// ��k�������ұߣ�ֱ�ӵݹ��ұߵ� (k -���)����
	else
		return quick_select(p, j + 1, r, k - (j - l + 1));
}

// ��ߵ�����<=x, �ұߵ��� >= x ,��� <= �ұ�
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	cout << quick_select(a, 0, n - 1, m);
	return 0;
}