//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[16] = {0,1,2,1,1,1,1,5,5,4,-1,-1,-2,-3,-1,-9};
//int score;

//// u表示当前的台阶，step表示步数, ans 表示当前的得分 
//void dfs(int u, int step, int ans) {
//	if(step == 7)	return;
//	if(u == 15) {
//		score = max(score, ans);
//		return;
//	}
//	for(int i = 1; i <= 4 && u + i <= 15; i++) {
//		dfs(u + i, step + 1, ans + a[u + i]);
//	}
//	
//}

//int main() {
//	dfs(0, 0, 0);
//	cout << score << endl;
//	return 0;
//} 


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//string t = "2021ABCD";

//int main() {
//	int sum = 0, tmp = 1;
//	for(int i = t.size() - 1; i >= 0; i--) {
//		if('A' <= t[i] && t[i] <= 'Z')	sum += (t[i] - 'A' + 10) * tmp;
//		else	sum += (t[i] - '0') * tmp;
//		tmp = tmp * 16;
//		cout << sum << endl;
//	}
//	cout << sum << endl;
//}

// 最大子数组和 
#//include<iostream>
//#include<algorithm>
//using namespace std;
//int a[21][21] = {
//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//0,6,9,8,5,9,2,4,1,8,3,9,3,8,7,8,6,8,9,4,1,
//0,1,7,6,1,5,8,7,6,9,6,3,1,3,1,7,5,9,2,8,4,
//0,3,7,3,4,7,3,4,8,3,2,6,6,2,7,4,8,3,4,8,5,
//0,5,3,6,7,1,2,5,6,5,5,6,1,6,7,8,6,4,7,4,3,
//0,1,6,1,2,1,6,8,6,9,2,7,4,3,2,3,2,9,4,7,9,
//0,1,3,5,4,7,4,1,3,3,4,9,9,6,2,7,7,3,4,4,7,
//0,2,7,9,7,9,9,4,5,9,2,9,8,4,8,8,2,4,6,8,7,
//0,5,3,7,7,6,9,8,3,3,4,6,8,3,8,7,9,1,3,7,9,
//0,5,6,4,9,3,4,2,1,3,6,5,3,6,5,7,1,7,7,4,5,
//0,2,1,9,2,4,3,7,9,2,9,3,8,7,2,6,1,1,3,8,2,
//0,9,3,9,1,9,3,5,3,2,1,6,2,4,3,5,6,1,2,7,7,
//0,5,4,2,9,6,1,4,4,7,6,3,9,6,9,2,5,7,7,8,8,
//0,9,6,2,3,3,9,7,2,5,1,3,7,9,4,7,3,2,9,3,3,
//0,8,1,4,4,3,4,9,4,5,3,3,1,2,9,9,3,9,9,7,5,
//0,6,1,1,7,1,8,8,2,9,8,8,8,7,7,5,9,3,4,9,9,
//0,6,1,2,1,6,8,6,8,8,9,5,7,2,1,3,4,8,5,2,2,
//0,5,5,4,8,5,3,4,5,9,5,9,2,9,4,7,2,6,8,9,6,
//0,3,2,1,2,4,9,6,3,3,1,8,2,4,2,5,5,4,9,2,2,
//0,1,3,5,9,3,6,4,7,1,9,1,9,3,4,2,7,2,6,9,6,
//0,5,6,4,3,6,8,9,5,9,4,4,9,1,9,8,9,9,2,4,6,
//};
//int sum[25][25];
//int main() {
//	
//	for(int i = 1; i <= 20; i++)
//		for(int j = 1; j <= 20; j++) {
//			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
//		}
//	int maxS = 0;
//	for(int i = 5; i <= 20; i++)
//		for(int j = 5; j <= 20; j++) {
//			int t = sum[i][j] - sum[i-5][j] - sum[i][j-5] + sum[i-5][j-5];
//			maxS = max(maxS, t);
//		}
//	cout << maxS << endl;
//	return 0;
//}

// H停车 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int h1, h2, m1, m2, s1, s2;

//int main() {
//	scanf("%d:%d:%d", &h1, &m1, &s1);
//	scanf("%d:%d:%d", &h2, &m2, &s2);
//	int t1 = h1 * 3600 + m1 * 60 + s1;
//	int t2 = h2 * 3600 + m2 * 60 + s2;
//	int gp = t2 - t1;
//	printf("%02d:%02d:%02d", gp / 3600, gp % 3600 / 60, gp % 60);
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int g[20][20];

//void flyod() {
//	for(int k = 1; k <= 19; k++)
//		for(int i = 1; i <= 19; i++)
//			for(int j = 1; j <= 19;j++) {
//				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//			}
//}

//int main() {
////	memset(dist, 0x3f, sizeof dist);
//	memset(g, 0x3f, sizeof g);
//	g[1][2] = 2, g[1][3] = g[1][4] = g[1][5] = 1;
//	g[2][1] = g[2][10] = 2, g[2][7] = 1;
//	g[3][1] = 1, g[3][6] = g[3][7] = g[3][4] = 3;
//	g[4][1] = g[4][5] = g[4][8] = 1, g[4][7] = g[4][9] = 2, g[4][3] = 3;
//	g[5][1] = g[5][4] = g[5][8] = 1, g[5][9] = 3;
//	g[6][7] = g[6][10] = 1, g[6][3] = 3;
//	g[7][2] = g[7][6] = 1, g[7][4] = g[7][11] = 2, g[7][3] = g[7][9] = 3;
//	g[8][4] = g[8][5] = g[8][9] = 1, g[8][12] = 2;
//	g[9][8] = 1, g[9][4] = 2, g[9][5] = g[9][7] = g[9][13] = 3;
//	g[10][6] = 1, g[10][2] = g[10][19] = 2;
//	g[11][14] = 1, g[11][7] = g[11][16] = 2, g[11][12] = 3;
//	g[12][13] = g[12][18] = 1, g[12][8] = 2, g[12][11] = 3;
//	g[13][12] = g[13][17] = g[13][19] = 1, g[13][14] = 2, g[13][9] = 3;
//	g[14][11] = g[14][16] = 1, g[14][13] = 2;
//	g[15][17] = g[15][16] = 1, g[15][18] = 3;
//	g[16][15] = g[16][14] = 1, g[16][11] = 2;
//	g[17][13] = g[17][15] = 1;
//	g[18][12] = g[18][19] = 1, g[18][15] = 3;
//	g[19][13] = g[19][18] = 1, g[19][10] = 2;
//	flyod();
//	cout << g[1][19] << endl;
//	return 0;
//}

// 约数 
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//typedef long long LL;
//LL n = 2021041820210418;
//vector<LL> yue; // 存储约数 

//void getYue(LL x) {
//	for(LL i = 1; i <= x / i; i++) {
//		if(x % i == 0) {
//			yue.push_back(i);
//			if(x / i != i)	yue.push_back(x / i);
//		}
//	}
//} 
//int main() {
//	getYue(n);
//	for(int i = 0; i < yue.size(); i++) {
//		cout << yue[i] << endl;
//	}
//	sort(yue.begin(), yue.end());
//	LL ans = 0;
//	for(int i = 0; i < yue.size(); i++)
//		for(int j = 0; j < yue.size(); j++) {
//			if(n % (LL)(yue[i] * yue[j]) == 0)	ans++;	
//		}
//	cout << ans << endl;
//	return 0;
//}


// 跳蚱蜢 
//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//#include<set>
//using namespace std;
//string start = "-87654321", en = "-12345678";
//set<string> se; // 存储string,防止重复 

//typedef struct Node {
//	string s;
//	int step; // 步数 
//}node;

//int bfs() {
//	queue<node> q;
//	q.push({start, 0});
//	
//	while(q.size()) {
//		node t = q.front();
//		q.pop();
//		if(t.s == en)	return t.step;
//		int x = t.s.find('-');
//		
//		int x1 = (x - 2 + 9) % 9;
//		string tmp = t.s;
//		swap(tmp[x], tmp[x1]);
//		if(!se.count(tmp)) {
//			se.insert(tmp);
//			q.push({tmp, t.step + 1});
//		}
//		int x2 = (x + 2) % 9;
//		tmp = t.s;
//		swap(tmp[x2], tmp[x]);
//		if(!se.count(tmp)) {
//			se.insert(tmp);
//			q.push({tmp, t.step + 1});
//		}
//		int x3 = (x + 1) % 9;
//		tmp = t.s;
//		swap(tmp[x], tmp[x3]);
//		if(!se.count(tmp)) {
//			se.insert(tmp);
//			q.push({tmp, t.step + 1});
//		}
//		int x4 = (x - 1 + 9) % 9;
//		tmp = t.s;
//		swap(tmp[x], tmp[x4]);
//		if(!se.count(tmp)) {
//			se.insert(tmp);
//			q.push({tmp, t.step + 1});
//		}
//	}
//	return -1;
//}

//int main() {
//	cout << bfs();
//	
//	return 0;
//}

// 日期问题 
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int d[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

//bool is_leap(int year) {
//	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;	
//}

//int checkdate(int year, int month, int day) {
//	if(month < 1 || month > 12 || !day)	return 0;
//	if(month != 2) {
//		if(day > d[month])	return 0;
//	}else {
//		if(day > d[month] + is_leap(year))	return 0;
//	}
//	year += (year < 60) ? 2000 : 1900;
//	return year * 10000 + month * 100 + day;
//}
//int main() {
//	int y, m, d;
//	scanf("%d/%d/%d", &y, &m, &d);
//	int a = y, b = m, c = d;	
//	int ans = checkdate(a, b, c);
//	if(ans)	printf("%02d-%02d-%02d\n", ans / 10000, ans % 10000 / 100, ans % 100);

//	a = d, b = min(y, m), c = max(y, m);
//	ans = checkdate(a, b, c);
//	if(ans)	printf("%02d-%02d-%02d\n", ans / 10000, ans % 10000 / 100, ans % 100);	
//	if(y != m) {
//		a = d, b = max(y, m), c = min(y, m);
//		ans = checkdate(a, b, c);
//		if(ans)	printf("%02d-%02d-%02d\n", ans / 10000, ans % 10000 / 100, ans % 100);
//	}
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 10005, INF = 0x3f3f3f3f;
//int f[N][4];

//void init() {
//	for(int i = 0; i < N; i++)
//		for(int j = 0; j < 4; j++) {
//			if(i == 0 || j == 0)	f[i][j] = 0;
//			else	f[i][j] = INF;
//		}
//	for(int i = 1; i <= 1000; i++) {
//		f[i][1] = i;
//	}
//}

//int main() {
//	init();
//	int n;
//	cin >> n;
//	for(int j = 2; j <= 3; j++)
//		for(int i = 1; i <= n; i++) {
//			for(int x = 1; x <= i; x++)
//				f[i][j] = min(f[i][j], max(f[i-x][j], f[x-1][j-1]) + 1);
//		}
//	cout << f[n][3] << endl;
//	return 0;
//}

// 平面切分 
//#include<iostream>
//#include <cstdio>
//#include<algorithm>
//#include<set>
//#include<cstdio>
//using namespace std;
//typedef pair<double, double> PII;
//set<PII> line; // 存储斜率和截距
//int res = 1;

//void computer(double a, double b) {
//	set<PII> point; // 存储相交的节点
//	
//	set<PII>::iterator l;
//	// 遍历所有直线, 看有多少个不同的交点 
//	for(l = line.begin(); l != line.end(); l++) {
//		double A = l->first, B = l->second;
//		if(A != a) { // 不平行 
//			// 求交点
//			double x = (b - B) / (A - a);
//			double y = a * x + b;
//			point.insert(make_pair(x, y));
//		}
//	}
//	res += point.size();
//}

//int main() {
//	int n;
//	cin >> n;
//	while(n--) {
//		double a, b;
//		cin >> a >> b;
//		PII t = make_pair(a, b);
//		if(line.count(t) == 0) {
//			res++; // 不是重边区域+1
//			computer(a, b); // 计算这条直线与其他直线的交点个数 
//			line.insert(t);
//		}
//	}
//	cout << res << endl;
//	return 0;
//} 

//#include<iostream>
//using namespace std;
//const int N = 15;
//int n, a[N];
//bool col[N], du[N], fu[N];
//int ans;

//void dfs(int u) { // u表示行 
//	if(u > n) {
//		ans++;
//		return;
//	}
//	// 遍历这行中的各列 
//	for(int i = 1; i <= n; i++) {
//		if(col[i])	continue;
//		if(du[u - i + n] && (a[u - 1] == i - 1 || a[u - 2] == i - 2)) continue;
//		if(fu[u + i] && (a[u - 1] == i + 1 || a[u - 2] == i + 2))	continue;
//		a[u] = i;
//		col[i] = true;
//		du[u - i + n] = true;
//		fu[u + i] = true;
//		dfs(u + 1);
//		col[i] = false;
//		du[u - i + n] = false;
//		fu[u + i] = false;
//	}
//}

//int main() {
//	cin >> n;
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}

// 生日蜡烛26
//#include<iostream>
//using namespace std;
//int ans;
//int main() {
//	for(int i = 1; i <= 80; i++) {
//		int sum = 0;
//		for(int j = i; ;j++) {
//			sum += j;
//			if(sum >= 236)	break;
//		}	
//		if(sum == 236)	ans = i;
//	}
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 10;
//bool st[N];
//int g[3][4], ans;

// 方格填数 
//bool check(int x, int y, int value) {
//	int v1 = value - 1, v2 = value + 1;
//	if(x - 1 >= 0 && (g[x - 1][y] == v1 || g[x - 1][y] == v2 ))	return false;
//	if(y - 1 >= 0 && (g[x][y-1] == v1 || g[x][y - 1] == v2))	return false;
//	//if(x + 1 < 3 && (g[x+1][y] == v1 || g[x+1][y] == v2))	return false;
////	if(y + 1 < 4 && (g[x][y+1] == v1 || g[x][y+1] == v2))	return false;
//	if(x - 1 >= 0 && y - 1 >= 0 && (g[x-1][y-1] == v1 || g[x-1][y-1] == v2))	return false;
////	if(x + 1 < 3 && y + 1 < 4 && (g[x+1][y+1] == v1 || g[x+1][y+1] == v2))	return false;
//	if(x - 1 >= 0 && y + 1 < 4 && (g[x-1][y+1] == v1 || g[x-1][y+1] == v2))	return false;
////	if(x + 1 < 3 && y - 1 >= 0 && (g[x+1][y-1] == v1 || g[x+1][y-1] == v2))	return false;
//	return true;
//}

//void dfs(int x, int y) {
//	if(x == 2 && y == 3) {
//		ans++;
//		return;
//	}
//	if(y > 3) {
//		x++;
//		y = 0;
//	}
//	for(int i = 0; i <= 9; i++) {
//		if(!st[i] && check(x, y, i)) {
//			st[i] = true;
//			g[x][y] = i;
//			dfs(x, y + 1);
//			st[i] = false;
//		}
//	}
//}
//int main() {
//	memset(g, 0x3f, sizeof g);
//	dfs(0, 1);
//	cout << ans << endl;
//	return 0;
//}


// 逃生 
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int N = 1010, INF = -0x3f3f3f3f;
//int a[N][N];
//int dp[N][N];

//int main() {
//	int n, m, x, y, v, c;
//	cin >> n >> m >> x >> y >> v >> c;
//	for(int i  = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)
//			cin >> a[i][j];
//	int dir[4][2] = {{-1,-1}, {-1,1}, {1,1}, {1,-1}};
//	for(int t = 0; t < 4; t++)
//		for(int i = x; i >0 && i <= n; i += dir[t][0])
//			for(int j = y; j > 0 && j <= m; j += dir[t][1]) {
//				if(i == x && j == y)
//					dp[i][j] = v;
//				else if(i == x) {
//					dp[i][j] = min(c, dp[i][j - dir[t][1]] + a[i][j]);
//				}else if(j == y) {
//					dp[i][j] = min(c, dp[i - dir[t][0]][j] + a[i][j]);
//				}else {
//					dp[i][j] = min(c, max(dp[i - dir[t][0]][j], dp[i][j - dir[t][1]] + a[i][j]));
//				}
//				if(dp[i][j] <= 0)	dp[i][j] = INF;
//			}
//	int ans = max(max(dp[1][1], dp[1][m]), max(dp[n][1], dp[n][m]));
//	if(ans <= 0)	cout << "-1" << endl;
//	else cout << ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 35;
//int f[N][N];

//int main() {
//	int n, m;
//	cin >> n >> m;
//	f[0][1] = 1;
//	for(int i = 1; i <= m; i++)
//		for(int j = 1; j <= n; j++) { // 球现在在j手上 
//			if(j == 1)	f[i][j] = f[i-1][2] + f[i-1][n];
//			else if(j == n)	f[i][j] = f[i-1][1] + f[i-1][n-1];
//			else f[i][j] = f[i-1][j-1] + f[i-1][j+1];
//		}
//	cout << f[m][1] << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int a[N], dp[N]; 


//int main() {
//	int n;
//	cin >> n;
//	for(int i = 1;i <= n; i++)	cin >> a[i];
//	// dp[i] = 1 + dp[i + a[i]]
//	for(int i = n; i >= 1; i--) {
//		dp[i] = dp[i + a[i]] + 1;
//	}	
//	for(int i = 1; i <= n; i++)	cout << dp[i] <<  " ";
////	cout << dp[1] << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 1010;
//int a[N], ans;
//int num;
//int main() {
//	int n;
//	cin >> n;
//	int t = 0;
//	for(int i = 1; i <= n; i++)	 {
//		cin >> a[i];
//		t = max(t, a[i]);	
//	}
//	if(t < 0) {
//		cout << t << endl;
//	}else {
//		int sum = 0;
//		for(int i = 1; i <= n; i++) {
//			if(sum + a[i] < 0) {
//				sum = 0;
//				num = 0;
//			}
//			else {
//				sum += a[i];
//				if(num == 0)	num = a[i];
//			}
//			ans = max(ans, sum);
//		}
//		cout << ans << endl;
//		cout << num << endl;
//	}

//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int a[N][N], pre[N][N];
//int ans;

//int main() {
//	int n, m;
//	cin >> n >> m;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}	
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			pre[i][j] = pre[i-1][j] + a[i][j];
//			cout << pre[i][j] << " ";
//		} 
//		cout << endl;
//	}
//	
//	for(int i = 1; i <= n; i++) // 上界 
//		for(int j = i; j <= n; j++) { // 下界 
//			int sum = 0;
//			for(int k = 1; k <= m; k++) {
//				if(sum + pre[j][k] - pre[i-1][k] < 0) {
//					sum = 0;
//				}else 
//					sum += pre[j][k] - pre[i-1][k];
//				ans = max(ans, sum);
//			}
//		}
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;

//int main() {
//	int n;
//	cin >> n;
//	for(int i = 1; i * i <= n; i++) {
//		if(n % i == 0) {
//			cout << i << " ";
//			if(n / i != i)	cout << n / i << " ";
//		}
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//const int N = 100010;
//bool st[N];
//int prime[100010], cnt;

//void find_prime() {
//	for(int i = 2;i <= N; i++) {
//		if(!st[i])	prime[cnt++] = i;
//		for(int j = 0; i * prime[j] <= N; j++) {
//			st[prime[j] * i] = true;
//			if(i % prime[j] == 0)	break;
//		}
//	}
//}

//bool check(int a, int d) { // 首项和公差 
//	for(int i = 1; i < 10; i++) {
//		int a1 = a + i * d;
//		if(a1 > N ||st[a1])	return false;
//	}
//	for(int i = 0;i < 10; i++)	cout << a + i * d << " ";
//	cout << endl;
//	return true;
//}

//int main() {
//	find_prime();
//	for(int d = 10; ; d++)
//		for(int j = 0; j < cnt; j++) {
//			if(check(prime[j], d)) {
//				cout << d << endl;
//				return 0;
//			}
//		}	
//	return 0;
//}

// 微博转发 
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int N = 1010;
//vector<int> head[N]; // head[i]表示i被哪些人关注了 
//int n, L, k;
//int dist[N]; // 某个点的层数 
//bool st[N];

//int bfs(int u) { // u发帖子，层数lay 
//	queue<int> q;
//	q.push(u);
//	int res = 0;
//	st[u] = true;
//	
//	while(q.size() && dist[q.front()] < L) {
//		auto t = q.front();
//		q.pop();
//		
//		for(int i = 0; i < head[t].size(); i++) {
//			int v = head[t][i];
//			if(!st[v]) {
//				res += 1;
//				st[v] = true;
//				q.push(v); // 将t的关注者加入队列 
//				dist[v] = dist[t] + 1;
//			}
//		}
//	}
//	return res;
//}

//int main() {
//	cin >> n >> L;
//	for(int i = 1; i <= n; i++) {
//		int s, x;
//		cin >> s;
//		while(s--) {
//			cin >> x;
//			head[x].push_back(i); // i关注x 
//		}
//	}
//	cin >> k;
//	while(k--) {
//		memset(st, false, sizeof st);
//		memset(dist, 0, sizeof dist);
//		int x;
//		cin >> x; // x发帖子 
//		cout << bfs(x) << endl;
//	}	
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 1010;
typedef pair<string, int> PII; // 存储团伙头目和人数 
vector<PII>ans; // 存储答案 
int fa[N];
int w[N], cnt[N]; // 每个点的权值, 每个连通块的点数 
int n, k, idx = 1; // idx用来转换下标 
unordered_map<string,int> ToInt;
unordered_map<int,string> ToName;
bool st[N];
 
int find(int x) {
	if(x != fa[x])	fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	fa[i] = i;
	for(int i = 1; i <= n; i++)	cnt[i] = 1;
	
	for(int i = 0; i < n; i++) {
		string a, b;
		int t;
		cin >> a >> b >> t;
		// 转换下标 
		if(!ToInt.count(a)) {
			ToInt[a] = idx;
			ToName[idx] = a;
			++idx;
		}if(!ToInt.count(b)) {
			ToInt[b] = idx;
			ToName[idx] = b;
			++idx;
		}
		w[ToInt[a]] += t, w[ToInt[b]] += t;
		int x1 = find(ToInt[a]), x2 = find(ToInt[b]);
		if(x1 != x2) {
			fa[x1] = x2;
			cnt[x2] += cnt[x1]; // 连通块的人数 
		}
	}
	int allNum = ToInt.size();
	for(int i = 1; i <= allNum; i++) {
		if(st[i])	continue;
		int head = find(i); // 先找该集合的根节点,根节点cnt记录了该连通块的人数 
		int maxhead = head, sum = 0;
		
		for(int j = 1; j <= allNum; j++) {
			if(st[j]) continue;
			if(find(j) == head) {
				st[j] = true;
				sum += w[j];
				if(w[j] > w[maxhead])	maxhead = j;
			}
		}
		if(cnt[head] >= 3 && sum / 2 > k) ans.push_back({ToName[maxhead], cnt[head]});
	}
	sort(ans.begin(), ans.end()); // 字典序排序
	cout << ans.size() << endl;
	for(auto t : ans) {
		cout << t.first << " " << t.second << endl;
	} 
	return 0;
}
