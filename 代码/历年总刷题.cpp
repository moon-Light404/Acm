// 3181
//#include<iostream>
//using namespace std;
//int cnt[10], ans; 
//int main() {
//	for(int i = 0; i <= 9; i++)	cnt[i] = 2021;
//	
//	for(int i = 1; i; i++) {
//		int t = i;
//		while(t) {
//			cnt[t % 10]--;
//			if(cnt[t % 10] < 0) {
//				ans = i;
//				cout << ans - 1 << endl;
//				return 0;
//			}
//			t /= 10;
//		}
//	}

//	return 0;
//}

// 40257
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cmath>
//using namespace std;
//typedef pair<int,int> PII;
//vector<PII> point; // 存点 

//struct line {
//	double k, b;
//	bool operator < (const line& t) const {
//		if(k != t.k)	return k < t.k;
//		else return b < t.b;
//	}
//};
//vector<line> l;
//int main() {
//	for(int i = 0; i <= 19; i++)
//		for(int j = 0; j <= 20; j++)
//			point.push_back({i, j});
//	
//	int n = point.size();
//	for(int i = 0; i < n; i++)
//		for(int j = i + 1; j < n; j++) {
//			int x1 = point[i].first, y1 = point[i].second;
//			int x2 = point[j].first, y2 = point[j].second;
//			if(x1 != x2) {
//				double k = 1.0 * (y1 - y2) / (x1 - x2);
//				double b = y1 - k * x1;
//				l.push_back({k, b});
//			}
//		}
//	sort(l.begin(), l.end());
//	int ans = 1;
//	for(int i = 0; i < l.size() - 1; i++) {
//		if(fabs(l[i].k - l[i+1].k) < 1e-6 && fabs(l[i].b - l[i+1].b) < 1e-6) {
////			cout << l[i].k << " " << l[i+1].k << " " << l[i].b << " " << l[i+1].b << endl;
//			continue;
//		}
//		ans++;
//	}
//	cout << ans + 20<< endl;
//	return 0;
//}
//10266837
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//using namespace std;
//const int N = 2025;
//int g[N][N];

//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;	
//}

//int lcm(int a, int b) {
//	return a * b / gcd(a,b);
//}

//void flyod() {
//	for(int k = 1; k <= 2021; k++)
//		for(int i = 1; i <= 2021; i++)
//			for(int j = 1; j <= 2021; j++) {
//				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//			} 
//}

//int main() {
//	memset(g, 0x3f, sizeof g);
//	for(int i = 1; i <= 2021; i++)
//		for(int j = i + 1; j <= 2021; j++) {
//			if(abs(i - j) <= 21)	g[i][j] = g[j][i] = lcm(i, j);
//		}
//	flyod();
//	cout << g[1][2021];
//	return 0;
//}


//#include<iostream>
//using namespace std;

//int main(){
//	
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int N = 110, M = 200010;
//bool f[N][M];
//int n, w[N];
//int sum[N];
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)	{
//		cin >> w[i];
//		sum[i] = sum[i-1] + w[i];
//	}
//	int total = sum[n];
//	f[0][0] = 1;
//	for(int i = 1; i <= n; i++)
//		for(int j = 0; j <= total; j++) {
//			if(sum[i] < j)	continue;
//			f[i][j] = (f[i-1][j] || f[i-1][j+w[i]] || f[i-1][abs(j - w[i])] || w[i] == j);
//		}
//	int ans = 0;
//	for(int i = 1; i <= total; i++) {
//		if(f[n][i])	ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<cstdio>
//using namespace std;
//int cnt0[25], cnt1[25]; // 记录每一位0和1的个数 

//void query(int x) {
//	for(int i = 19; i >= 0; i--) {
//		int u = x >> i & 1;
//		if(u)	cnt1[i]++;
//		else	cnt0[i]++;
//	}
//}

//int main() {
//	int T;
//	cin >> T;
//	while(T--) {
//		int n, res  = 0;
//		cin >> n;
//		while(n--) {
//			int x;
//			cin >> x;
//			res = res ^ x;
//			query(x);
//		}
//		if(res == 0)	puts("0");
//		else {
//			for(int i = 19; i >= 0; i--) {
//				if(cnt1[i] % 2 == 0)	continue;
//				if(cnt1[i] == 1) {
//					puts("1");
//					break;
//				}
//				else if(cnt1[i] % 2){
//					if(cnt0[i] % 2 == 0) {
//						puts("1");
//						break;
//					}
//					else {
//						puts("0");
//						break;
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int N = 100010;
//int f[N], msize[N];
//int n;
//vector<int> g[N];

//void dfs(int u) {
//	f[u] = 0;
//	
//	for(auto v : g[u]) {
//		dfs(v);
//		f[u] = max(f[u], f[v] + msize[u]);
//	}
//}
//int main() {
//	cin >> n;
//	for(int i = 2; i <= n; i++) {
//		int x;
//		cin >> x; // x是父节点 
//		g[x].push_back(i);
//		msize[x]++;
//	}
//	dfs(1);
//	cout << f[1] << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N = 21, M = 1 << 21;
//ll f[M][N];
//bool g[N][N];

//int gcd(int a,int b) {
//	return b ? gcd(b, a % b) : a;
//}

//int main() {
//	for(int i = 1; i <= 21; i++)
//		for(int j = 1; j <= 21; j++) {
//			if(gcd(i, j) == 1)	g[i-1][j-1] = 1;
//		}
//	f[1][0] = 1;
//	for(int state = 1; state < M; state++)
//		if(state & 1) { // 必须先经过1 
//			for(int j = 0; j < 21; j++)
//				if(state >> j & 1)
//					for(int k = 0; k < 21; k++) {
//						if(state ^ (1 << j) >> k & 1 && g[k][j])
//							f[state][j] += f[state ^ (1 << j)][k];
//					}
//		}
//	ll res = 0;
//	for(int i = 0; i <= 20; i++)
//		res += f[M - 1][i];
//	cout << res << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 20210510;
//ll f[N];

//ll dfs(int u) {
//	if(u == 1)	return 1;
//	if(f[u] != -1)	return f[u];
//	f[u] = 0;
//	for(int i = 1; i * i <= u; i++){
//		if(u % i == 0) {
//			f[u] += dfs(i);
//			if(i != 1 && u / i != i)	f[u] += dfs(u / i);
//		}
//	}
//	return f[u];
//}

//int main() {
//	int n = 20210509;
//	memset(f, -1, sizeof f);
//	ll res = 0;
//	for(int i = 1; i <= n; i++) {
//		res += dfs(i);
//	}
//	cout << res;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int arr[17];
//int ans;

//void dfs(int u) {
//	if(u > 8) {
//		ans++;
//		for(int i = 1; i <= 16; i++)	cout << arr[i] << " ";
//		cout << endl;
//		return;
//	}

//	for(int j = 1; j + u + 1<= 16; j++) { // 枚举位置 
//		int l = j, r = j + u + 1;
//		if(arr[l] || arr[r]) continue;
//		arr[l] = u, arr[r] = u;
//		dfs(u + 1);
//		arr[l] = 0, arr[r] = 0;
//	}
//		
//}

//int main() {
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}



//#include<cstdio>
//#include<iostream>
//using namespace std;
//int arr[20];
//int ans = 0;
//bool st[10];
//void dfs(int u){ // u表示位置 
//	
//	if(u == 17) {
//		for(int i = 1; i <= 16; i++)	cout << arr[i] << " ";
//		cout << endl;
//		ans++;
//		return;
//	}
//	
//	if(arr[u] != 0)	dfs(u + 1);
//	else {
//		for(int i = 1; i <= 8; i++) {
//			if(!st[i] && u + i + 1 <= 16 && arr[u + i + 1] == 0 && arr[u] == 0) {
//				st[i] = true;
//				arr[u] = i;
//				arr[u + i + 1] = i;
//				dfs(u + 1);
//				st[i] = false;
//				arr[u] = 0;
//				arr[u + i + 1] = 0;
//			}

//		}
//	}

//	
//}
//int main(){
//	dfs(1);
//	cout<<ans<<endl;
//	return 0;
//}


// 乘法表 
//#include<iostream>
//#include<algorithm> 
//using namespace std;
//const int N = 36;
//char w[36];

//string change(int k, int x) { // k进制 
//	string s;
//	while(x) {
//		s += w[x % k];
//		x /= k;
//	}
//	reverse(s.begin(), s.end());
//	return s;
//}

//int main() {
//	for(int i = 0; i < 10; i++)	w[i] = i + '0';
//	for(int i = 10; i < 36; i++) {
//		w[i] = i - 10 + 'A';
//	}
//	int n;
//	cin >> n;
//	for(int i = 1; i < n; i++) {
//		for(int j = 1; j <= i; j++)
//			cout << change(n, i) << "*" << change(n,j) << "=" << change(n,i* j) << " ";
//		cout << endl;
//	}
//	
//	return 0;
//}

//acwing 乘积最大 
//#include<iostream>
//using namespace std;
//int n, k;
//char s[11];
//int ans;

//int get_num(int a, int b) {
//	int res = 0;
//	for(int i = a; i <= b; i++)	
//		res = res * 10 + (s[i] - '0');
//	return res; 
//}

//void dfs(int start, int more, int now) { // start表示当前处理到第几个字符、 more还剩下几个乘号、now现在乘积多大 
//	if(n - start < more)	return;
//	if(!more) {
//		now = now * get_num(start, n);
//		if(now > ans)	ans = now;
//		return;
//	}
//	for(int i = start; i < n; i++) {
//		dfs(i + 1, more - 1, now * get_num(start, i));
//	}
//}

//int main() {
//	cin >> n >> k;
//	cin >> s + 1;
//	dfs(1, k, 1);
//	cout << ans << endl;
//	return 0;
//} 

// LIS输出序列 

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int a[N], f[N];
//int g[N];// 
//int n;
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)	cin >> a[i];
//	
//	for(int i = 1;i <= n; i++) {
//		f[i] = 1;
//		g[i] = 0;
//		for(int j = 1; j < i; j++) {
//			if(a[i] > a[j]) {
//				if(f[i] <= f[j] + 1) {
//					f[i] = f[j] + 1;
//					g[i] = j; // i是从j转移过来的 
//				}
//			}
//		}
//	}
//	int k = 1;
//	for(int i = 1; i <= n; i++) {
//		if(f[i] > f[k]) {
//			k = i;
//		}
//	}
////	for(int i = 1; i <= n; i++)	cout << f[i] << " ";
////	for(int i = 1; i <= n; i++)  cout << g[i] << " ";
//	for(int i = 1, len = f[k]; i <= len; i++) {
////		cout << k << endl;
//		cout << a[k]<< " ";
//		k = g[k];
//	}
//	return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 20010;
//int h[N], e[N * 2], ne[N * 2], idx, w[N];
//int n, m;
//int lg[N]; // log(i) + 1的值 

//int fa[N][20]; // f[u][i]表示u的2^i级祖先 
//int depth[N]; // 结点的深度 
//int dist[N]; // 1-i的距离 

// 初始化结点的倍增祖先 
//void dfs(int u, int father) {
//	fa[u][0] = father, depth[u] = depth[father] + 1;
//	for(int i = 1; i <= lg[depth[u]] - 1; i++) {
//		fa[u][i] = fa[fa[u][i - 1]][i - 1];
//	}
//	for(int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		if(j != father)
//			dfs(j, u);
//	}
//}

// 初始化每个点到1点的距离 
//void dfs_dist(int u, int father) {
//	for(int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		if(j != father) {
//			dist[j] = dist[u] + w[i];
//			dfs(j, u);
//		}
//	}
//}

// 求x和y的最近公共祖先 
//int LCA(int x, int y) {
//	if(depth[x] < depth[y])	swap(x, y);
//	while(depth[x] > depth[y]){
//		int dis = depth[y] - depth[x];
//		x = fa[x][lg[dis] - 1];
//	}
//	if(x == y)	return x;
//	for(int k = lg[depth[x]] - 1; k >= 0; k--) {
//		if(fa[x][k] != fa[y][k]) {
//			x = fa[x][k], y = fa[y][k];
//		}
//	} 
//	return fa[x][0];
//}

//void init() {
//	memset(h, -1, sizeof h);
//	for(int i = 1; i <= n; i++)
//		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//	
//}

//void add(int a,int b, int c) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	w[idx] = c;
//	h[a] = idx;
//	++idx;
//}
//int main() {
//	cin >> n >> m;
//	init(); // 初始化 
//	for(int i = 0; i < n - 1; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	dfs(1, 0);
//	dfs_dist(1, -1);
//	while(m--) {
//		int a, b;
//		cin >> a >> b;
//		int fa = LCA(a, b);
//		int d = dist[a] + dist[b] - dist[fa];
//		cout << d << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 10010, INF = 0x3f3f3f3f;
//int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
//int n;
//int d1[N], d2[N], p1[N], p2[N]; // d1[u] u点向下的最长路径 d2 次长路径 
//int up[N];
//void add(int a, int b, int c) {
//    e[idx] = b;
//    ne[idx] = h[a];
//    w[idx] = c;
//    h[a] = idx;
//    ++idx;
//}

//int dfs_down(int u, int father) {
//	d1[u] = -INF, d2[u] = -INF;
//	for(int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		if(j != father) {
//			int d = dfs_down(j, u) + w[i];
//			if(d >= d1[u]) {
//				d2[u] = d1[u], d1[u] = d;
//				p2[u] = p1[u], p1[u] = j; // u的最长路径往子节点j走 
//			} else if(d > d2[u]) {
//				d2[u] = d, p2[u] = j;
//			}
//		}
//	}	
//	if(d1[u] == -INF)	d1[u] = d2[u] = 0;
//	return d1[u];
//}

//void dfs_up(int u, int father) {
//	for(int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		if(j != father) {
//			if(p1[u] == j) {
//				up[j] = max(up[u], d2[u]) + w[i];
//			}else 
//				up[j] = max(up[u], d1[u]) + w[i];
//			dfs_up(j, u);
//		}
//	}
//}

//int main() {
//	memset(h, -1, sizeof h);
//    cin >> n;
//    for(int i = 0; i < n - 1; i++) {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        add(a, b, c), add(b, a, c);
//    }
//    dfs_down(1, -1);
//    dfs_up(1, -1);
//    int res = INF;
//    for(int i = 1; i <= n;i++)	res = min(res, max(d1[i], up[i]));
//    cout << res << endl;
//    return 0;
//}

// 糖果：取余dp 
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int N = 110, inf = 0x3f3f3f3f;
//int w[N];
//int f[N][N];
//int n, k;
//int main() {
//	cin >> n >> k;
//	for(int i = 1; i <= n; i++)	cin >> w[i];
//	memset(f, -0x3f, sizeof f);
//	f[0][0] = 0;
//	for(int i = 1; i <= n; i++)
//		for(int j = 0; j < k; j++) {
//			f[i][j] = max(f[i - 1][j], f[i - 1][((j - w[i]) % k + k) % k] + w[i]);
//		}
//	cout << f[n][0] << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, m;
//int ans;
//int a[10];

//void dfs(int sum, int cnt, int pre) { // 苹果数、第几个盘子、pre起点 
//	if(sum > n)	return;
//	if(cnt > m) {  // 盘子装完了 
//		if(sum == n) {
//		for(int i = 1; i <= m; i++)	cout << a[i] << " ";
//		cout << endl;
//		ans++;
//		}
//		return;
//	}
//	for(int i = pre; i <= n; i++) {
//		a[cnt] = i; 
//		dfs(sum + i, cnt + 1, i);
//		a[cnt] = 0;
//	}
//		
//} 
//int main() {
//	cin >> n >> m; // n个苹果、m个盘子
//	dfs(0, 1, 0);
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int N = 25;
//string s[N];
//int ans, g[N][N]; // g[i][j]表示字符串i和k可拼接的最小长度 
//int n;
//int used[N]; // 剩余使用次数 

//void dfs(string now, int k) { // 字符串、字符串编号 
//	ans = max(ans, (int)now.size());
//	for(int i = 1; i <= n; i++) {
//		if(g[k][i] && used[i] < 2) {
//			used[i]++;
//			dfs(now + s[i].substr(g[k][i]), i);
//			used[i]--;
//		}
//	}
//}

//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)	cin >> s[i];	
//	char start;
//	cin >> start;
//	// j接到i的后面 
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= n; j++) {
//			string a = s[i], b = s[j];
//			for(int k = 1; k <= min(a.size(), b.size()); k++){
//				if(a.substr(a.size() - k, k) == b.substr(0, k)) {
//					g[i][j] = k;
//					break;
//				}
//			}
//		}
//	for(int i = 1; i <= n; i++) {
//		if(s[i][0] == start) {
//			used[i]++;
//			dfs(s[i], i);
//			used[i]--;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

// 509方格分割 
//#include<iostream>
//using namespace std;
//const int N = 8;
//bool st[N][N];
//int ans;

//void dfs(int x, int y) {
//	if(st[x][y])	return;
//	if(x == 0 || y == 0 || x == 6 || y == 6) {
//		ans++; 
//		return;
//	}
//	st[x][y] = true;
//	st[6 - x][6 - y] = true;
//	dfs(x + 1, y);	
//	dfs(x, y + 1);
//	dfs(x - 1,y);
//	dfs(x, y - 1);
//	st[x][y] = false;
//	st[6 - x][6 - y] = false;
//}
//int main() {
//	dfs(3, 3);
//	cout << ans / 4 << endl;	
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//double a[9] = {1,2,3,4,5,6,7,8,9};
//int ans;

//int main() {
//	do {
//		if(a[0] + (a[1] / a[2]) + (a[3] * 100 + a[4]*10 + a[5]) / (a[6]*100 + a[7]*10 + a[8]) == 10.0)
//			ans++;
//	}while(next_permutation(a, a + 9));
//	cout << ans << endl;
//}

//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//int mask[15] = {9090400, 8499400, 5926800, 8547000, 4958200, 4422600, 5751200, 4175600, 6309600, 5865200, 6604400, 4635000, 10663400, 8087200, 4554000};
//int ans = 0x3f3f3f3f;
//void dfs(int u, int s1, int s2) {
//	if(u == 15) {
//		ans = min(ans, abs(s1 - s2));
//		return;
//	}
//	dfs(u + 1, s1 + mask[u], s2);
//	dfs(u + 1, s1, s2 + mask[u]);
//}

//int main() {
//	dfs(0, 0 ,0);
//	cout << ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[10] = {0,1,2,3,4,5,6,7,8,9};

//bool check(int a[]) {
//	if(a[0] < a[1] && a[0] < a[2] && a[1] < a[3] && a[1] < a[4]
//	&& a[2] < a[4] && a[2] < a[5] && a[3] < a[6] && a[3] < a[7] &&
//	a[4] < a[7] && a[4] < a[8] && a[5] < a[8] && a[5] < a[9])	return true;
//	return false;	
//}

//int main() {
//	int ans =0;
//	do {
//		if (check(a)) ans++;
//	}while(next_permutation(a, a + 10));
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int ans;

//void dfs(int n, int step) {
//	if(n < 0)	return;
//	if(n == 0) {
//		if(step % 2 == 0)
//			ans++;
//		return;
//	}
//	dfs(n - 1, step + 1);
//	dfs(n - 2, step + 1);
//}

//int main() {
//	dfs(39, 0); // 还剩下39级台阶、现在走了0步 
//	cout << ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<queue>
//using namespace std;
//string s = "010101010010110010010101100101101001000010001010100000100010000010101001000010000000100110011010010101111011010010001000001101001011100011000000010000010000000010101000110100001010000010101010110010110001111100000010100001001010001010000010110000000011001000110101000010101100011010011010101011110111000110110101010010010010100000010001010011100000001010000010100010011010101011111001100001000011101000111000001010100001100010000001000101001100001001110001101000011100100010010101010101010100011010000001000010010000010100101010111010001010101000010111100100101001001000010000010101010100100100010100000000100000001010110011110100011000001010101000111010101001110000100001100001011001111011010000100010101010100001101010100101000010100000111011101001100000001011000100001011001011010010111000000001001010100100000001010010000100010000010001111010100100101001010101101001010100011010101101110000110101110010100001000011000000101001010000010001110000100000100011000011010110100000010010100100100001110110100101000101000000001110110010110101101010100001001010000100001101010100001000100010010001000101011010000100011001000100001010100101010101111101001000000100101000000110010100101001000001000000000010110100000010011101110010010000111010010110111010000000011010001000100010000000100001110100000011001110101000101000100010001111100010101001010000001000100000101001010010101100000001001010100010111010000011110000100001000000011011100000000100000000101110000001100111010111010001000110111010101101111000";
//char g[30][50];
//int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
//char de[4] = {'D', 'L', 'R', 'U'};
//bool st[50][50];
//typedef struct Node {
//	int x, y;
//	string state;
//}node;


//string bfs() {
//	queue<node> q;
//	q.push({0, 0, ""});
//	st[0][0] = true;
//	while(q.size()) {
//		auto t = q.front();
//		q.pop();
//		if(t.x == 29 && t.y == 49)	return t.state;
//		for(int i = 0; i < 4; i++) {
//			int nx = t.x + dir[i][0], ny = t.y + dir[i][1];
//			if(nx < 0 || nx >= 30 || ny < 0 || ny >= 50 || st[nx][ny])	continue;
//			if(g[nx][ny] == '1')	continue;
//			q.push({nx, ny, t.state + de[i]});
//			st[nx][ny] = true;
//		}
//	}	
//	return "";
//}

//int main() {
//	for(int i = 0; i < 30; i++)
//		for(int j = 0; j < 50; j++) {
//			g[i][j] = s[i * 50 + j];
//		}
//	cout << bfs();
//		
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//using namespace std;
//const int N = 100010, mod = 100003;
//int h[N], e[N * 2], ne[N * 2], idx;
//int n, m, dist[N];
//int cnt[N]; // cnt[i]从1到i的最短路条数
//bool st[N];
// 
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;	
//}

//void spfa() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	cnt[1] = 1;
//	queue<int> q;
//	q.push(1);
//	st[1] = true;
//	
//	while(q.size()) {
//		int u = q.front();
//		q.pop();
//		st[u] = false;
//		for(int i = h[u]; i != -1; i = ne[i]) {
//			int j = e[i];
//			if(dist[j] > dist[u] + 1) {
//				dist[j] = dist[u] + 1;
//				cnt[j] = cnt[u];
//				if(!st[j]) {
//					q.push(j);
//					st[j] = true;
//				}
//			}else if(dist[j] == dist[u] + 1) {
//				cnt[j] = (cnt[j] + cnt[u]) % mod;
//			}
//		}
//	}
//}

//int main() {
//	scanf("%d%d", &n, &m);
//	memset(h, -1, sizeof h);
//	for(int i = 0; i < m; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//	}
//	spfa();
//	for(int i = 1; i <= n; i++) {
//		printf("%d\n", cnt[i]);
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int a[N], f[N];
//int n;
//int ans;
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)	cin >> a[i];
//	for(int i = 1; i <= n; i++) {
//		f[i] = a[i];
//		for(int j = 1; j < i; j++) {
//			if(a[j] < a[i])	f[i] = max(f[i], f[j] + a[i]);
//		}
//		ans = max(ans, f[i]);
//	}
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int N = 210;
//int g[N][N];
//int n, m, k;

//void flyod() {
//	for(int k = 1; k <= n; k++)
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= n; j++)
//				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);	
//}

//int main() {
//	cin >> n >> m >> k;
//	memset(g, 0x3f, sizeof g);
//	for(int i = 1; i <= n; i++)	g[i][i] = 0;
//	for(int i = 0; i < m; i++) {
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		g[a][b] = min(g[a][b], c);
//	}
//	flyod();
//	while(k--) {
//		int x, y;
//		scanf("%d%d", &x, &y);
//		if(g[x][y] > 0x3f3f3f3f / 2)	puts("impossible");
//		else printf("%d\n", g[x][y]);
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#include<cstdio>
//using namespace std;
//typedef pair<int,int> PII;
//const int N = 150010;
//int h[N], e[N], ne[N], w[N], idx;
//int n, m;
//bool st[N];
//int dist[N];

//void add(int a, int b,int c) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	w[idx] = c;
//	h[a] = idx;
//	++idx; 	
//}

//int dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	priority_queue<PII, vector<PII>, greater<PII>> q;
//	q.push({0, 1});
//	dist[1] = 0;
//	
//	while(q.size()) {
//		PII t = q.top();
//		q.pop();
//		int distance = t.first, u = t.second;
//		if(st[u])	continue;
//		st[u] = true;
//		for(int i = h[u]; i != -1; i = ne[i]) {
//			int j = e[i];
//			if(dist[j] > dist[u] + w[i]) {
//				dist[j] = dist[u] + w[i];
//				q.push({j, dist[j]});
//			}
//		}
//	}
//	if(dist[n] == 0x3f3f3f3f)	return -1;
//	return dist[n];
//	 
//}

//int main() {
//	scanf("%d%d", &n, &m);
//	memset(h, -1, sizeof h);
//	for(int i = 0; i < m; i++) {
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		add(a, b, c);
//	}
//	cout << dijkstra() << endl;
//	return 0;
//}


#include<iostream>
#include<queue>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N = 200010;
priority_queue<PII, vector<PII>, greater<PII>> q[N]; // 每台计算机的任务 
int s[N]; // 每台计算机的算力
int n, m;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	cin >> s[i];
	for(int i = 0; i < m; i++) {
		int a, b, c, d; // 开始时间、计算机编号、耗时、消耗算力 
		scanf("%d%d%d%d", &a, &b, &c, &d);
		while(q[b].size() && q[b].top().x <= a) {
			s[b] += q[b].top().y; // 回收算力 
			q[b].pop();
		}
		if(s[b] < d)	puts("-1");
		else {
			s[b] -= d;
			q[b].push({a + c, d});
			printf("%d\n", s[b]);
		}
	}
	
	return 0;
}
