// ���ű���ϰϵͳ

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
//// ʮ������ת�˽���
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


















//		res.push_back(r); // ����
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



// ӡ��-���ű�ѵ��

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


// ���
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



// ������Ϸ
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main() {
//// n�����ĸ����� num�Ǳ��ֽ������
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
//	} while (next_permutation(a+1, a + n+1)); // ȫ����
//	if (k == 1) {
//		for (int i = 1; i <= n; i++)
//			cout << a[i] << " ";
//	}
//	return 0;
//}



// ���ĵĶ�
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
//	if (sum & 1 == 1) { // ��Ϊ��������������
//		cout << "false";
//		return 0;
//	}
//	int target = sum / 2; // ��������͵�һ��
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

































// ��������
// ����ö�ٷ�:�������п��ܵ����������ж��Ƿ�Ϸ�
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
//	// �ݹ��յ�
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
//	int left = 0; // �������ڵ���˵�
//	for (int i = 0; i < n; i++) {
//		while (loop.find(s[i]) != loop.end()) { // ���ظ����������ұ��ƶ�
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
////�������ṹ
//typedef struct BiTNode {
//	ElemType data;
//	struct BiTNode *left, *right;
//} BiTNode, *BiTree; // BiTree��ָ�����͵�
//
//
//// �������
//void InorderTraverse(BiTree T) {
//	if (T) {
//		InorderTraverse(T->left);
//		cout << T->data << " ";
//		InorderTraverse(T->right);
//	}
//}
//
//// ǰ�����
//void PreorderTraverse(BiTree T) {
//	if (T) {
//		cout << T->data << " ";
//		PreorderTraverse(T->left);
//		PreorderTraverse(T->right);
//	}
//}
//
//// �������
//void LastorderTraverse(BiTree T) {
//	if (T) {
//		LastorderTraverse(T->left);
//		LastorderTraverse(T->right);
//		cout << T->data << " ";
//	}
//}
//
////����������
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
//		newT->data = T->data; // ���Ƹ��ڵ�
//		Copy(T->left, newT->left);
//		Copy(T->right, newT->right);
//	}
//}
//int main() {
//	BiTree T;
//	cout << " ��������Ҫ��������" << endl;
//	createBiTree(T);
//	cout << "�������" << endl;
//	InorderTraverse(T);
//	cout << endl;
//	cout << "ǰ�����" << endl;
//	PreorderTraverse(T);
//	cout << endl;
//	cout << "�������" << endl;
//	LastorderTraverse(T);
//	return 0;
//}


// ���ĵĶ�
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
//	// 1 >> n ���������, v�洢��ͬ״̬�¶�Ӧ��ϵ��ܳ���
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
//		// ˵������Ϊmid�ĳ��ȷ���
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
//int ex, ey; // �յ�
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
















// ճľ��
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 10;
//int a[N];
//int n, m;
//int res = INT_MAX;
//// ��ʣ��n��ľ��
//void dfs(int k) {
//	// ��ʣ��m��ľ��,�ϲ����
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
//			a[i] += a[j]; // �ϲ�i��j����ľ������i��
//			swap(a[j], a[k - 1]); // ��j��û���˺����һ������������-1
//			dfs(k - 1); // �ϲ�����һ��ľ��
//			// �ָ�״̬
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



















// ����λ��
//#include <iostream>
//using namespace std;
//int n;
//bool st[10];
//long long  ans;
//void dfs(int k) { // �ӵ�n�п�ʼ��
//	if (k > n)	{
//		ans++;
//		return;
//	}
//	// ���в���
//	dfs(k + 1);
//	// �������е�ÿһ��
//	for (int i = 1; i <= n; i++) {
//		if (!st[i]) {
//			st[i] = true;
//			dfs(k + 1); // ��һ��
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
















// 24��
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
//	// �ĸ�����ѡ�����������
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
//					// �ָ�״̬
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
//		int q[4]; // �洢4������
//		ans = INT_MIN;
//		for (int i = 0; i < 4; i++)
//			cin >> q[i];
//		dfs(q, 1); // ��1������
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
//int n; // ����
//// cab��ǰ�ڼ��Ρ� len��ǰ�εĳ��� start��ʼ��λ��
//bool dfs(int cab, int len, int start) {
//	if (cab > cnt)
//		return true; // ƴ�������и�����ԭľ��
//	if (len == Len)
//		return dfs(cab + 1, 0, 0); // ƴ����һ��ԭľ��
//	// ����ƴһ��ľ��,��startλ�ÿ�ʼ
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
//		reverse(s, s + n); // �Ӵ�С����
//		// ��������i
//		for (Len = s[0]; Len <= sum / 2; Len++) {
//			if (sum % Len)
//				continue;
//			cnt = sum / Len; // ԭľ������
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

// ���ֽ�
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




