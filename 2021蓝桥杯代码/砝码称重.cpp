//// �������
////1 4 6
////1 4 6 3 5 11 2 7 10 9
#include <iostream>
#include <cmath>
using namespace std;
// dp[i][j]��ʾǰi�������Ƿ���ԳƳ�j������ t or f
const int M = 100005;
bool dp[106][M];

int a[M]; // ÿ�����������
int main() {
	int N, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= N; i++) { // ǰi������
		for (int j = 1; j <= sum; j++) { // 1~sum������
			dp[i][j] = dp[i - 1][j];
			if (!dp[i][j]) {
				if (a[i] == j)
					dp[i][j] = true;
				if (dp[i - 1][j + a[i]])
					// ��һ��״̬���ԳƳ���j��a[i]�����������״ֻ̬Ҫ��a[i]���ڲ�ͬ��Ϳ��ԳƳ�j����
					dp[i][j] = true;
				if (dp[i - 1][abs(j - a[i])])
					// ��һ״̬���ԳƳ���jСa[i]������,���ֻҪ��a[i]����ͬ��Ϳ��ԳƳ�j����
//				j = 10, a[i] = 6, dp[i-1][4] = 1,���Է�6���ɳƳ�10,����߱��ұ���4(+4),����ټ�6����(+10)
//				j = 6, a[i] = 10,dp[i-1][4] = 1,��һ��״̬���ԳƳ�4(-4),����߱��ұ���4(-4),��߼���10�����+6
					dp[i][j] = true;
			}
		}
	}
	long long ans = 0;
	for (int k = 1; k <= sum; k++) { // ����������,ǰN��������ԳƵ�������
		if (dp[N][k])
			ans++;
	}
	cout << ans << endl;

	return 0;
}

