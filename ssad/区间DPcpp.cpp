//#include <cstdio>

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int N = 2010;
//char s[N];
//int n, m;
//int cost[30];
//int dp[N][N];//dp[i][j] �洢�� i �� j ��һ��ת���ɻ�����������Ҫ����С����
//
//int main() {
//	ios::sync_with_stdio(false);//��stdio�����,ʹ��cin��scanfЧ������޼�
//	int a, b;
//	char t;
//	while (cin >> n >> m) {
//		cin >> s + 1;
//		while (n--) {
//			cin >> t >> a >> b;
//			cost[t - 'a'] = min(a, b);
//		}
////		for (int i = m; i >= 1; i--) {
////			dp[i][i] = 0;
////			for (int j = i + 1; j <= m; j++) {
////				if (s[i] == s[j]) {
////					if (j - i <= 2)
////						dp[i][j] = 0;
////					else
////						dp[i][j] = dp[i + 1][j - 1];
////				} else
////					dp[i][j] = min(dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
////			}
////		}
//		for (int i = 1; i <= m; i++)
//			dp[i][i] = 0;
//		for (int len = 2; len <= m; len++) // ����,�Ӷ̵���
//			for (int i = 1; i + len - 1 <= m; i++) { // ���
//				int j = i + len - 1; // �յ�
//				if (s[i] == s[j]) {
//					if (j - i <= 2)
//						dp[i][j] = 0;
//					else
//						dp[i][j] = dp[i + 1][j - 1];
//				} else {
//					if (j - i <= 1)
//						dp[i][j] = min(cost[s[i] - 'a'], cost[s[j] - 'a']);
//					else
//						dp[i][j] = min(dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
//				}
//			}
//
//		printf("%d\n", dp[1][m]);
//	}
//	return 0;
//}
