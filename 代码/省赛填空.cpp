// 蓝桥杯填空题

















// 数青蛙353
//#include <iostream>
//using namespace std;
//
////
//int get(int n) {
//	if (n >= 1 && n <= 10)
//		return 1;
//	if (n >= 11 && n <= 20 || n % 10 == 0)
//		return 2;
//	return 3;
//}
//
//int main() {
//	int sum = 0;
//	for (int i = 1; i <= 20; i++)
//		sum += get(i);
//	for (int i = 1; i <= 20; i++)
//		sum += get(i);
//	for (int i = 2; i <= 40; i += 2)
//		sum += get(i);
//	for (int i = 4; i <= 80; i += 4)
//		sum += get(i);
//	cout << sum + 200 << endl;
//	return 0;
//}


















// 车牌
//#include <iostream>
//using namespace std;
//int ans;
//
//void dfs(int u, int a, int b) {
//	if (u > 6) {
//		ans++;
//		return;
//	}
//	int n = u <= 3 ? 15 : 9;
//	for (int i = 0; i <= n; i++) {
//		if (a == b && b == i)
//			continue;
//		dfs(u + 1, b, i);
//	}
//}
//
//int main() {
//	dfs(1, -1, -1); // 第1位
//	cout << ans << endl;
//	return 0;
//}





















// 41269  Fibonacci集合
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//
//using namespace std;
//
//priority_queue<int, vector<int>, greater<int>> q;
//set<int> s;
//
//void bfs() {
//	int cnt = 0;
//	q.push(1), s.insert(1);
//	q.push(2), s.insert(2);
//	q.push(3), s.insert(3);
//	q.push(5), s.insert(5);
//	q.push(8), s.insert(8);
//	while (q.size()) {
//		cnt++;
//
//		int t = q.top();
//		q.pop();
//		if (cnt == 2020) {
//			cout << t;
//			return;
//		}
//
//		int w[] = {3 * t + 2, 5 * t + 3, 8 * t + 5};
//		for (int i = 0; i < 3; i++) {
//			if (!s.count(w[i])) {
//				q.push(w[i]);
//				s.insert(w[i]);
//			}
//		}
//	}
//}
//
//int main() {
//	bfs();
//	return 0;
//}


























// 上升子串 (记忆化搜索)
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 35;
//typedef long long LL;
//char g[N][N];
//int f[N][N]; // f[i][j]出发的上升子串数量
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//int n, m;
//
//int dfs(int x, int y) {
//	if (f[x][y] != -1)
//		return f[x][y];
//	f[x][y] = 1;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dir[i][0], ny = y + dir[i][1];
//		if (nx < 1 || nx > n || ny < 1 || ny > m)
//			continue;
//		if (g[nx][ny] <= g[x][y])
//			continue;
//		f[x][y] += dfs(nx, ny);
//	}
//	return f[x][y];
//}
//
//int main() {
//	memset(f, -1, sizeof f);
//
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		cin >> g[i] + 1;
//	int res = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			res += dfs(i, j);
//		}
//	cout << res;
//	return 0;
//}















// 日期识别
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int get(string month) {
//	if (month == "Jan")
//		return 1;
//	if (month == "Feb")
//		return 2;
//	if (month == "Mar")
//		return 3;
//	if (month == "Apr")
//		return 4;
//	if (month == "May")
//		return 5;
//	if (month == "Jun")
//		return 6;
//	if (month == "Jul")
//		return 7;
//	if (month == "Aug")
//		return 8;
//	if (month == "Sep")
//		return 9;
//	if (month == "Oct")
//		return 10;
//	if (month == "Nov")
//		return 11;
//	if (month == "Dec")
//		return 12;
//
//}
//
//int main() {
//	string date;
////	cin >> date;
//	cout << get(date.substr(0, 3)) << " " << stoi(date.substr(3, 2)) << endl;
////	int a = 2112;
////
////	string s = to_string(a);
////	cout << s;
//	return 0;
//}

// 双阶乘
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n = 2021, ans = 1;;
//	while (n >= 1) {
//		ans = ans * n % 100000;
//		n -= 2;
//	}
//	cout << ans;
//	return 0;
//}

// 格点
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int ans = 0;
//	for (int i = 1; i <= 2021; i++)
//		for (int j = i + 1; j <= 2021; j++) {
//			if (i * j <= 2021)
//				ans++;
//		}
//	cout << ans * 2 + 44;
//	return 0;
//}
















// 整数分解
//#include <iostream>
//#include <cstring>
//using namespace std;
//typedef long long LL;
//LL f[2030][10]; // f[i][j]表示把j个数拼成i的方案数
//
//LL dfs(int n, int k) {
//	if (n < k)
//		return 0;
//	if (f[n][k] != -1)
//		return f[n][k];
//	if (k == 0) { // 拼完了k个数
//		if (n == 0)
//			return 1;
//		return 0;
//	}
//	f[n][k] = 0;
//	for (int i = 1; i <= n; i++) {
//		f[n][k] += dfs(n - i, k - 1);
//	}
//	return f[n][k];
//}
//
//int main() {
//	memset(f, -1, sizeof f);
//	cout << dfs(2021, 5);
//	return 0;
//}





































// 城邦 ans:4046
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 2025;
//int g[N][N]; //i和j的距离
//int dist[N];
//bool st[N];
//
//int get_dist(int x, int y) {
//	if (g[y][x] != 0)
//		return g[y][x];
//	int dis = 0;
//	int t1, t2;
//	while (x && y) {
//		t1 = x % 10, t2 = y % 10;
//		if (t1 != t2)
//			dis += (t1 + t2);
//		x /= 10, y /= 10;
//	}
//	if (x)
//		while (x) {
//			dis += x % 10;
//			x /= 10;
//		}
//	if (y)
//		while (y) {
//			dis += y % 10;
//			y /= 10;
//		}
//	return dis;
//}
//
//void init() {
//	for (int i = 1; i <= 2021; i++)
//		for (int j = 1; j <= 2021; j++) {
//			if (i == j)
//				g[i][j] = 0;
//			else
//				g[i][j] = get_dist(i, j);
//		}
//}
//
//int prim() {
//	memset(dist, 0x3f, sizeof dist);
//	int res = 0;
//	for (int i = 0; i < 2021; i++) {
//		int t = -1;
//		for (int j = 1; j <= 2021; j++)
//			if (!st[j] && (t == -1 || dist[j] < dist[t]))
//				t = j;
//		st[t] = true; // 加入到已连接的集合
//		if (i)
//			res += dist[t];
//		for (int j = 1; j <= 2021; j++)
////			if (!st[j])
//			dist[j] = min(dist[j], g[t][j]);
//	}
//	return res;
//}
//
//int main() {
//	init();
//	cout << prim() << endl;
//	return 0;
//}















// 游戏 记忆化搜索
//#include <iostream>
//#include <cstring>
//using namespace std;
//typedef long long LL;
//LL f[20210515];
//
//LL dfs(int x) {
//	if (f[x] != -1)
//		return f[x];
//	if (x == 1)
//		return 1;
//	f[x] = 0;
//	for (int i = 1; i <= x / i; i++) {
//		if (x % i == 0) {
//			f[x] += dfs(i);
//			if (x / i != i && i != 1)
//				f[x] += dfs(x / i);
//		}
//	}
//	return f[x];
//}
//
//int main() {
//	memset(f, -1, sizeof f);
//	LL ans = 0;
//	for (int i = 1; i <= 20210509; i++)
//		ans += dfs(i);
//	cout << ans << endl;
//	return 0;
//}


#include <iostream>
#include <unordered_map>
using namespace std;
char c;
int cnt;
string s;
unordered_map<char, int> mp;
int main() {
	cin >> s;
	for (auto t : s) {
		mp[t]++;
		if (mp[t] > cnt) {
			cnt = mp[t];
			c = t;
		}
	}
	cout << c << " " << cnt << endl;
	return 0;
}


