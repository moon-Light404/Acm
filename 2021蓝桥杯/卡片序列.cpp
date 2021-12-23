// 卡片序列











//#include <iostream>
//using namespace std;
//const int N = 10;
//int cnt[N];
//
//bool check(int num) { // num是否能拼出来
//	while (num) {
//		int x = num % 10; // 取个位
//		cnt[x]--; // x卡片减去1
//		if (cnt[x] < 0)
//			return false;
//		num /= 10;
//	}
//	return true; // 能拼出来
//}
//
//int main() {
//	for (int i = 0; i < 10; i++)
//		cnt[i] = 2021; // 数字i的卡片数量都是2021
//
//	int j = 1;
//	while (1) {
//		if (check(j)) {
//			j++;
//		} else
//			break;
//	}
//	cout << j - 1 ;
//	return 0;
//}


// 3.货物摆放

//#include <iostream>
//#include <algorithm>
//using namespace std;
//typedef long long LL;
//LL yue[101000], cnt;
//
//int main() {
//	LL n = 2021041820210418;
//	for (LL i = 1; i <= n / i; i++) { // 求所有的约数
//		if (n % i == 0) {
//			yue[++cnt] = i;
//			if (i * i != n)
//				yue[++cnt] = n / i;
//		}
//	}
//	sort(yue + 1, yue + cnt + 1);
//	for (int i = 1; i <= cnt; i++)
//		cout << yue[i] << endl;
//	cout << cnt;
////    int ans=0;
//    for(int i=1;i<=cnt;i++){
//        for(int j=1;j<=cnt;j++){
//            if(n%(yue[i]*yue[j])==0)
//                ans++;
//        }
//    }
//    cout<<ans;
//	return 0;
//}




































// 4.路径
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int N = 2100;
//int g[N][N];
//bool st[N];
//int dist[N];
//int n = 2021; // 2021个点
//int gcd(int a, int b) {
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//
//void dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0; i < n; i++) { // n次遍历
//		int t = -1;
//		for (int j = 1; j <= n; j++) {
//			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
//				t = j;
//			}
//		}
//		st[t] = true;
//
//		for (int j = 1; j <= n; j++) {
//			dist[j] = min(dist[j], dist[t] + dist[j]);
//		}
//	}
//}
//
//int main() {
//	memset(g, 0x3f, sizeof g);
//	for (int i = 1; i <= 2021; i++)
//		for (int j = 1; j <= 2021; j++) {
//			if (j - i <= 21)
//				g[i][j] = g[j][i] = lcm(i, j);
//		}
//	dijkstra();
//	cout << dist[n];
//	return 0;
//}

// 5.砝码称重

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//bool dp[101][300001];
//int n;
//vector<int> v;
//unordered_map<int, bool>ans;
//const int shift = 100000;
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; ++i) {
//		int temp;
//		cin >> temp;
//		v.push_back(temp);
//	}
//
//	//偏移量shift为150000(当作零点)，原因是砝码总重量最大100000，偏移后的砝码重量范围在[50000,250000]，数组开300000即可
//
//	//第0个砝码放右边，放左边，不放
//	dp[0][shift + v[0]] = dp[0][shift - v[0]] = dp[0][shift] = true;
//
//	for (int i = 1; i < n; ++i) {
//		for (int j = 1; j <= 2 * shift; ++j) {
//			dp[i][j] |= dp[i - 1][j];//不放第i个砝码
//			dp[i][j] |= dp[i - 1][j + v[i]];//放右边
//			if (j - v[i] >= 1)
//				dp[i][j] |= dp[i - 1][j - v[i]];//放左边
//		}
//	}
//
//	for (int i = 1; i <= 2 * shift; ++i) {
//		if (dp[n - 1][i]) {
//			ans[abs(shift - i)] = true;//砝码放左边和右边可能存在重复情况，使用unordered_map和abs去重
//		}
//	}
//
//	cout << ans.size() - 1 << endl;//减去所有砝码都不选即砝码重量为0的特殊情况
//}

// 直线
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 22, inf = 0x3f3f3f3f;
bool vis[N], flag[N][N][N][N];
bool flag1;
unordered_map<double, unordered_map<double, int> >vis1;
bool judge(int x1, int y1, int x2, int y2) {
	if (x2 == x1) { // 垂直于x轴
		if (!vis[x1]) {
			vis[x1] = 1;
//			cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
			return 1;
		}
		return 0;
	}
	double k = (double(y2 - y1)) / (double(x2 - x1));
	double b = y1 - k * x1;
	if (!vis1[k][b]) {
		vis1[k][b] = 1;
//		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
//		cout << "k的值: " << k << endl << "b的值: " << b << endl;
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int x1 = 0; x1 <= n; x1++) {
		for (int y1 = 0; y1 <= m; y1++) {
			for (int x2 = 0; x2 <= n; x2++) {
				for (int y2 = 0; y2 <= m; y2++) {
					if (!flag[x1][y1][x2][y2]) { // 去重 (x1,y1)(x2,y2) (x2,y2)(x1,y1)
						flag[x1][y1][x2][y2] = flag[x2][y2][x1][y1] = 1;
						ans += judge(x1, y1, x2, y2);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
1 2
ans:11

19 20
ans:41509
*/

//if(a == p.a) {
//	if(b == p.b) {
//		return c < p.c;
//	}else 
//		return b < p.b;
//}else 
//	return a < p.a;
