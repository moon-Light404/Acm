// 蓝桥杯倍数问题

//#include <iostream>
//using namespace std;
//const int N = 100010;
//int a[N];
//bool st[N];
//int n, k;
//int se[4], ans;
//
//void dfs(int u, int last) {
//	if (u == 3) {
//		if ((se[0] + se[1] + se[2]) % k == 0)
//			ans = max(ans, se[0] + se[1] + se[2]);
//		return;
//	}
//	for (int i = last; i <= n; i++) {
//		if (!st[i]) {
//			st[i] = true;
//			se[u] = a[i];
//			dfs(u + 1, i);
//			se[u] = 0;
//			st[i] = false;
//		}
//	}
//}
//
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//	dfs(0, 1);
//	printf("%d\n", ans);
//	return 0;
//}


// 乘法表
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//char w[36];
//unordered_map<char, int> mp;
//int M, P;
//
//// 十进制转P进制
//string change(int s) {
//	string res;
//	while (s) {
//		res += w[s % P];
//		s /= P;
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//// M进制转成10进制
//int changeTo10(string s) {
//	int res = 0, n = s.size();
//	for (int i = n - 1, r = 1; i >= 0; i--, r *= M) {
//		if (s[i] >= '0' && s[i] <= '9')
//			res += r * (s[i] - '0');
//		else if (s[i] >= 'a' && s[i] <= 'z')
//			res += r * (s[i] - 'a' + 10);
//		else
//			res += r * (s[i] - 'A' + 36);
//	}
//	return res;
//}
//
//int main() {
//	cin >> M >> P;
//	for (int i = 0; i <= 9; i++)
//		w[i] = i + '0';
//	for (int i = 10; i < 36; i++)
//		w[i] = 'A' + (i - 10);
//	string m1;
//	cin >> m1;
//	cout << changeTo10(m1) << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//typedef long long LL;
//const int N = 3010;
//
//LL dfs(int x, int t, int m) {
//	if (x <= 0 || t < 0)
//		return 0;
//	if (m == 0) {
//		if (x - t > 0) {
//			return 1;
//		}
//
//		return 0;
//	}
//
//	return dfs(x + 1, t - 1, m - 1) + dfs(x - 1, t - 1, m);
//}
//
//
//int main() {
//	int D, T, M;
//	cin >> D >> T >> M;
//	cout << dfs(D, T, M) << endl;
//	return 0;
//}



