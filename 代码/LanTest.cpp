// 蓝桥杯练习系统

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> q;
int main() {
	q.push_back(1);
	q.push_back(2);
	for(int i = 0; i < q.size(); i++)	cout << q[i];
	return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 210;
//int a[N];
//
//void quick_sort(int q[], int l, int r) {
//	if (l >= r)
//		return;
//
//	int i = l - 1, j = r + 1, x = q[l + r >> 1];
//	while (i < j) {
//		while (q[++i] < x);
//		while (q[--j] > x);
//		if (i < j)
//			swap(q[i], q[j]);
//
//	}
//	quick_sort(q, l, j);
//	quick_sort(q, j + 1, r);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	quick_sort(a, 0, n);
//	for (int i = 0 ; i < n; i++)
//		cout << a[i] << " ";
//	return 0;
//}






//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n;
//
//// 十六进制转八进制
//void hex_to_de(string hex) {
//	vector<int> num;
//	vector<int> res;
//	for (auto c : hex) {
//		if (c >= '0' && c <= '9')
//			num.push_back(c - '0');
//		if (c >= 'A' && c <= 'Z')
//			num.push_back(c - 'A' + 10);
//	}
//	reverse(num.begin(), num.end());
//	while (num.size()) {
//		int r = 0;
//		for (int i = num.size(); i >= 0; i--) {
//			num[i] += r * 16;
//			r = num[i] % 8;
//			num[i] /= 8;
//		}


















//		res.push_back(r); // 余数
//		while (num.size() && num.back() == 0)
//			num.pop_back();
//	}
//	reverse(res.begin(), res.end());
//	for (int i = 0 ; i < res.size(); i++)
//		cout << res[i];
//	cout << endl;
//}
//
//int main() {
//	scanf("%d", &n);
//	while (n--) {
//		string hex;
//	}
//	return 0;
//}



// 印章-蓝桥杯训练

//#include <iostream>
//#include <cmath>
//using namespace std;
//const int N = 25;
//double dp[N][N];
//int n, m;
//int main() {
//	cin >> n >> m;
//	double p = 1.0 / n;
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= n; j++) {
//			if (i < j)
//				dp[i][j] = 0;
//			if (j == 1)
//				dp[i][j] = pow(p, i - 1);
//			else
//				dp[i][j] = dp[i - 1][j] * (j * 1.0 / n) + dp[i - 1][j - 1] * (n - (j - 1)) * 1.0 / n;
//		}
//	printf("%.4lf", dp[m][n]);
//
//	return 0;
//}


// 金币
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1010;
//int w[N][N], dp[N][N];
//int n;
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) {
//			cin >> w[i][j];
//			if (i == 1 && j == 1)
//				dp[i][j] = w[i][j];
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + w[i][j];
//		}
//	cout << dp[n][n];
//	return 0;
//}



// 数字游戏
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main() {
//// n是数的个数， num是被分解的数字
//	int n, sum;
//	int a[20],  b[20];
//	cin >> n >> sum;
//	int j = n;
//	int k = 0;
//	for (int i = 1; i <= n; i++)
//		a[i] = i;
//	do {
//		for(int i = 1;i <= n;i++)	b[i] = a[i];
//		while (j > 1) {
//			for (int i = 1; i < n; i++)
//				b[i] = b[i] + b[i + 1];
//			j--;
//		}
//		j = n;
//		if (b[1] == sum) {
//			k = 1;
//			break;
//		}
//	} while (next_permutation(a+1, a + n+1)); // 全排列
//	if (k == 1) {
//		for (int i = 1; i <= n; i++)
//			cout << a[i] << " ";
//	}
//	return 0;
//}



// 无聊的逗
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 210;
//int a[N], n, sum;
//bool dp[N][N];
//int main() {
//	dp[0][0] = false;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//		sum += a[i];
//	}
//	if (sum & 1 == 1) { // 和为奇数不符合题意
//		cout << "false";
//		return 0;
//	}
//	int target = sum / 2; // 计算数组和的一半
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= target; j++) {
//			dp[i][j] = dp[i - 1][j];
//
//			if (a[i] == j) {
//				dp[i][j] = true;
//				continue;
//			}
//
//			if (a[i] < j)
//				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
//		}
//	}
//
//	cout << dp[n][target];
//	return 0;
//}

































// 括号生成
// 暴力枚举法:遍历所有可能的括号序列判断是否合法
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//bool valid(const string &str) {
//	int balance = 0;
//	for (char c : str) {
//		if (c == '(')
//			balance++;
//		else
//			balance--;
//		if (balance < 0)
//			return false;
//	}
//	return balance == 0;
//}
//
//void generate_all(string cur, int n, vector<string> &result) {
//	// 递归终点
//	if (cur.size() == n) {
//		if (valid(cur))
//			result.push_back(cur);
//		return;
//	}
//	cur += '(';
//	generate_all(cur, n, result);
//	cur.pop_back();
//	cur += ')';
//	generate_all(cur, n, result);
//	cur.pop_back();
//}
//
//int main() {
//	int n;
//	vector<string> res;
//	string cur;
//	cin >> n;
//	generate_all(cur, n * 2, res);
//	for (string a : res)
//		cout << a << ",";
//	return 0;
//}
















//#include <bits/stdc++.h>
//using namespace std;
//
//int getLen(string s) {
//	int n = s.length();
//	if (n <= 1)
//		return n;
//	unordered_set<char> loop;
//	int maxl = 0;
//	int left = 0; // 滑动窗口的左端点
//	for (int i = 0; i < n; i++) {
//		while (loop.find(s[i]) != loop.end()) { // 有重复的数字向右边移动
//			loop.erase(s[left]);
//			left++;
//		}
//		maxl = max(maxl, i - left + 1);
//		loop.insert(s[i]);
//	}
//	return maxl;
//}
//
//int main() {
//	string ss;
//	cin >> ss;
//	cout << getLen(ss);
//	return 0;
//}




























































































//#include <iostream>
//using namespace std;
//typedef int ElemType;
////定义树结构
//typedef struct BiTNode {
//	ElemType data;
//	struct BiTNode *left, *right;
//} BiTNode, *BiTree; // BiTree是指针类型的
//
//
//// 中序遍历
//void InorderTraverse(BiTree T) {
//	if (T) {
//		InorderTraverse(T->left);
//		cout << T->data << " ";
//		InorderTraverse(T->right);
//	}
//}
//
//// 前序遍历
//void PreorderTraverse(BiTree T) {
//	if (T) {
//		cout << T->data << " ";
//		PreorderTraverse(T->left);
//		PreorderTraverse(T->right);
//	}
//}
//
//// 后序遍历
//void LastorderTraverse(BiTree T) {
//	if (T) {
//		LastorderTraverse(T->left);
//		LastorderTraverse(T->right);
//		cout << T->data << " ";
//	}
//}
//
////二叉树创建
//void createBiTree(BiTree &T) {
//	ElemType d;
//	cin >> d;
//	if (d == -1)
//		T = NULL;
//	else {
//		T = new BiTNode;
//		T->data = d;
//		createBiTree(T->left);
//		createBiTree(T->right);
//	}
//}
//
//void Copy(BiTree T, BiTree &newT) {
//	if(T == NULL) {
//		newT = NULL;
//		return;
//	}
//	else {
//		newT = new BiTNode;
//		newT->data = T->data; // 复制根节点
//		Copy(T->left, newT->left);
//		Copy(T->right, newT->right);
//	}
//}
//int main() {
//	BiTree T;
//	cout << " 请输入你要创建的树" << endl;
//	createBiTree(T);
//	cout << "中序遍历" << endl;
//	InorderTraverse(T);
//	cout << endl;
//	cout << "前序遍历" << endl;
//	PreorderTraverse(T);
//	cout << endl;
//	cout << "后序遍历" << endl;
//	LastorderTraverse(T);
//	return 0;
//}


// 无聊的逗
//#include <iostream>
//#include <vector>
//using namespace std;
//int n;
//vector<int> tick;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		tick.push_back(a);
//	}
//	// 1 >> n 个组合数量, v存储不同状态下对应组合的总长度
//	vector<int> v(1 << n);
//	for (int i = 0; i < (1 << n); i++)
//		for (int j = 0; j < n; j++) {
//			if (i & (1 << j))
//				v[i] += tick[j];
//		}
//	int res = 0;
//	for (int i = 0; i < (1 << n); i++)
//		for (int j = 0; j < (1 << n); j++) {
//			if (!(i & j) && v[i] == v[j])
//				res = max(res, v[i]);
//		}
//	cout << res << endl;
//	return 0;
//}


















//#include <iostream>
//#define LL long long
//using namespace std;
//const int N = 1e6 + 10;
//int w[N];
//LL s[N], sum;
//int n;
//
//bool check(int mid) {
//	for (int i = mid; i + mid <= n; i++) {
//		if (s[i] - s[i - mid] <= sum && s[i + mid] - s[i] <= sum)
//			return true;
//		// 说明长度为mid的长度符合
//	}
//	return false;
//}
//
//int main() {
//	cin >> n >> sum;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//		s[i] = s[i - 1] + w[i];
//	}
//
//	int l = 1, r = n;
//	while (l < r) {
//		int mid = (l + r + 1) >> 1;
//		if (check(mid))
//			l = mid;
//		else
//			r = mid - 1;
//	}
//	cout << 2 * l << endl;
//	return 0;
//}






























































//#include <iostream>
//#include <queue>
//using namespace std;
//typedef struct point {
//	int a, b;
//	int step;
//} T;
//int ex, ey; // 终点
//bool st[9][9];
//
//int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
//
//int bfs(int x, int y) {
//	queue<T> q;
//	T sta, temp;
//	sta.a = x, sta.b = y;
//	sta.step = 0;
//	q.push(sta);
//	st[x][y] = true;
//	while (q.size()) {
//		T t = q.front();
//		q.pop();
//		if (t.a == ex && t.b == ey) {
//			return t.step;
//		}
//		for (int i = 0; i < 8; i++) {
//			int nx = t.a + dx[i];
//			int ny = t.b + dy[i];
//			if (nx < 1 || nx > 8 || ny < 1 || ny > 8 || st[nx][ny])
//				continue;
//			temp.a = nx, temp.b = ny, temp.step = t.step + 1;
//			q.push(temp);
////			q.push({nx, ny, t.step + 1});
//			st[nx][ny] = true;
//		}
//	}
//	return -1;
//}
//
//int main() {
//	int a, b;
//	cin >> a >> b >> ex >> ey;
//	cout << bfs(a, b);
//	return 0;
//}
















// 粘木棍
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 10;
//int a[N];
//int n, m;
//int res = INT_MAX;
//// 还剩下n根木棍
//void dfs(int k) {
//	// 还剩下m根木棍,合并完成
//	if (k == m) {
//		int pm = INT_MAX, pa = 0;
//		for (int i = 0; i < m; i++) {
//			if (pm > a[i])
//				pm = a[i];
//			if (pa < a[i])
//				pa = a[i];
//		}
//		res = min(res, pa - pm);
//		return;
//	}
//	for (int i = 0; i < k - 1; i++)
//		for (int j = i + 1; j < k; j++) {
//			a[i] += a[j]; // 合并i和j两根木棍到第i根
//			swap(a[j], a[k - 1]); // 第j根没用了和最后一根交换，数量-1
//			dfs(k - 1); // 合并减少一根木棍
//			// 恢复状态
//			swap(a[j], a[k - 1]);
//			a[i] -= a[j];
//		}
//
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	dfs(n);
//	cout << res << endl;
//	return 0;
//}



















// 车的位置
//#include <iostream>
//using namespace std;
//int n;
//bool st[10];
//long long  ans;
//void dfs(int k) { // 从第n行开始放
//	if (k > n)	{
//		ans++;
//		return;
//	}
//	// 这行不放
//	dfs(k + 1);
//	// 遍历该行的每一列
//	for (int i = 1; i <= n; i++) {
//		if (!st[i]) {
//			st[i] = true;
//			dfs(k + 1); // 下一行
//			st[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}
















// 24点
//#include <iostream>
//using namespace std;
//
//int ans;
//void dfs(int q[], int n) {
//	if (n == 4) {
//		for (int i = 0; i < 4; i++) {
//			if (q[i] && q[i] <= 24)	{
//				ans = max(ans, q[i]);
//				break;
//			}
//		}
//		return;
//	}
//	// 四个数中选两个数的组合
//	for (int i = 0; i < 4; i++)
//		if (q[i] != 0)
//			for (int j = 0; j < 4; j++) {
//				if (i != j && q[j] != 0) {
//					int l = q[i], r = q[j];
//					q[i] = 0;
//					q[j] = l + r;
//					dfs(q, n + 1);
//
//					q[j] = l - r;
//					dfs(q, n + 1);
//
//					q[j] = l * r;
//					dfs(q, n + 1);
//
//					if (l % r == 0) {
//						q[j] = l / r;
//						dfs(q, n + 1);
//					}
//					// 恢复状态
//					q[i] = l;
//					q[j] = r;
//				}
//			}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		int q[4]; // 存储4个数字
//		ans = INT_MIN;
//		for (int i = 0; i < 4; i++)
//			cin >> q[i];
//		dfs(q, 1); // 第1次运算
//		cout << ans << endl;
//	}
//	return 0;
//}













//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int N = 80;
//int s[N];
//bool st[N];
//int sum = 0, cnt, Len;
//int n; // 段数
//// cab当前第几段、 len当前段的长度 start开始的位置
//bool dfs(int cab, int len, int start) {
//	if (cab > cnt)
//		return true; // 拼完了所有根数的原木棒
//	if (len == Len)
//		return dfs(cab + 1, 0, 0); // 拼完了一根原木棒
//	// 正在拼一根木棒,从start位置开始
//	for (int i = start; i < n; i++) {
//		if (st[i])
//			continue;
//		if (len + s[i] <= Len) {
//			st[i] = true;
//			if (dfs(cab, len + s[i], start + 1))
//				return true;
//			st[i] = false;
//
//			if (len == 0 || len + s[i] == Len)
//				return false;
//			while (s[i] == s[i + 1])
//				i++;
//		}
//	}
//	return false;
//}
//
//int main() {
//	while (cin >> n && n) {
//		sum = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> s[i];
//			sum += s[i];
//		}
//		sort(s, s + n);
//		reverse(s, s + n); // 从大到小排序
//		// 遍历长度i
//		for (Len = s[0]; Len <= sum / 2; Len++) {
//			if (sum % Len)
//				continue;
//			cnt = sum / Len; // 原木棒数量
//			memset(st, 0, sizeof st);
//			if (dfs(1, 0, 0)) {
//				cout << Len << endl;
//				break;
//			}
//		}
//		if(Len > sum / 2)	cout << sum << endl;
//	}
//	return 0;
//}

























//#include <iostream>
//using namespace std;
//const int N = 110;
//char g[N][N];
//int n;
//int sx, sy, ex, ey;
//bool st[N][N];
//
//int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
//
//bool dfs(int x, int y) {
//	if (x == ex && y == ey)
//		return true;
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i], ny = y + dy[i];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
//			continue;
//		if (g[nx][ny] == '#' || st[nx][ny])
//			continue;
//		st[nx][ny] = true;
//		if (dfs(nx, ny))
//			return true;
//		st[nx][ny] = false;
//	}
//	return false;
//}
//
//int main() {
//	int k;
//	cin >> k;
//	while (k--) {
//		cin >> n;
//		for (int i = 0; i < n; i++)
//			cin >> g[i];
//		cin >> sx >> sy >> ex >> ey;
//		if (g[sx][sy] == '#' || g[ex][ey] == '#') {
//			cout << "NO" << endl;
//		}
//		else if (sx == ex && sy == ey) {
//			cout << "YES" << endl;
//		} else {
//			if (dfs(sx, sy))
//				cout << "YES" << endl;
//			else
//				cout << "NO" << endl;
//		}
//	}
//	return 0;
//}

// 最大分解
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main() {
//	int n, len = 0;
//	vector<int> yue;
//	cin >> n;
//	if (n == 1)
//		cout << "1" << endl;
//	else {
//		int sum = 0;
//		for (int i = 2; i * i <= n; i++) {
//			if (n % i == 0) {
//				yue.push_back(i);
//				len++;
//				if (i * i != n) {
//					yue.push_back(n / i);
//					len++;
//				}
//			}
//		}
//		sort(yue.begin(), yue.end());
//		reverse(yue.begin(), yue.end());
//
//		int t = n;
//		for (int i = 0; i < len; i++) {
//			if (t % yue[i] == 0) {
//				sum += yue[i];
//				t = yue[i];
//			}
//		}
//		cout << sum + 1 << endl;
//	}
//
//	return 0;
//}




