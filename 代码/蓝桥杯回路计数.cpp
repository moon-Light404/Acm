// 蓝桥杯回路计数
#include <iostream>
using namespace std;
int e[30][30]; // e[i][j]表示i和j之间是否有路
// 编号0~20 从0开始遍历所有点回到0
// f[i][j]表示从1走到 j 点且经过点的路径为i的数量

long long f[1 << 21][21];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	for (int i = 1; i <= 21; i++)
		for (int j = 1; j <= 21; j++) {
			if (gcd(i, j) == 1)
				e[i - 1][j - 1] = 1;
		}
	f[1][0] = 1; // 当前到达0点，路径只有一个点...0001
	for (int state = 1; state < (1 << 21); state++) // 状态
		for (int j = 0; j <= 20; j++) { // 点
			if (state >> j & 1) { // 状态中有第j个点
				for (int k = 0; k <= 20; k++)
					if (state ^ (1 << j) >> k & 1 && e[k][j] == 1)
						f[state][j] += f[state ^ (1 << j)][k];
			}
		}
	long long ans = 0;
	int s = (1 << 21) - 1;
	for (int i = 1; i <= 20; i++) {
		ans += f[s][i];
	}
	cout << ans << endl;
	return 0;
}