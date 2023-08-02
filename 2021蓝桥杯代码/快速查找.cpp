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
	// k < 左边的数量，说明第k个数在左边
	if (k <= j - l + 1)
		return quick_select(p, l, j, k);
	// 第k个数在右边，直接递归右边第 (k -左边)个数
	else
		return quick_select(p, j + 1, r, k - (j - l + 1));
}

// 左边的数是<=x, 右边的数 >= x ,左边 <= 右边
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	cout << quick_select(a, 0, n - 1, m);
	return 0;
}