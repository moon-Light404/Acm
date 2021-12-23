#include <iostream>
using namespace std;
bool st[10];
int n;

void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= u; i++)
			if (st[i])
				cout << i << " ";
		cout << endl;
		return;
	}
	st[u] = 1;
	dfs(u + 1);
	st[u] = 0;
	// 递归下一个位置
	dfs(u + 1);
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}