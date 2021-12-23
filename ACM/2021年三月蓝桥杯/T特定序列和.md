### 输入一个数找出所有加起来等于这个数的子序列，从小到大排列

#### DFS递归求解

```c++
// 输入一个数找出所有加起来等于这个数的子序列，从小到大排列
#include <iostream>
using namespace std;
int n;

const int N = 10;
int res[N];

void dfs(int u, int x, int c) { // u表示数组下标位置,x表示当前的和，c表示当前开始的数，后面的数要比前面的大于或等于
	if (x > n)
		return;

	if (x == n) {
		for (int i = 0; i < u; i++)
			cout << res[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = c; i <= n; i++) {
		res[u] = i;
		dfs(u + 1, x + i, i);
	}
}

int main() {
	cin >> n;
	dfs(0, 0, 1);
	return 0;
}
```

