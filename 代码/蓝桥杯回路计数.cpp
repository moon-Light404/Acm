// ���ű���·����
#include <iostream>
using namespace std;
int e[30][30]; // e[i][j]��ʾi��j֮���Ƿ���·
// ���0~20 ��0��ʼ�������е�ص�0
// f[i][j]��ʾ��1�ߵ� j ���Ҿ������·��Ϊi������

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
	f[1][0] = 1; // ��ǰ����0�㣬·��ֻ��һ����...0001
	for (int state = 1; state < (1 << 21); state++) // ״̬
		for (int j = 0; j <= 20; j++) { // ��
			if (state >> j & 1) { // ״̬���е�j����
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