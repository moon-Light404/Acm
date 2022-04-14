// ���ˢ��



//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//const int N = 1e6 + 10, M = 2 * 1e6 + 10;
//const int mod = 100003;
//vector<int> g[N];
//bool st[N];
//int dist[N], cnt[N];
//int n, m;
//
//void bfs() {
//	queue<int> q;
//	q.push(1);
//	dist[1] = 0;
//	st[1] = true;
//	cnt[1] = 1;
//	while (q.size()) {
//		int u = q.front();
//		q.pop();
//		for (auto v : g[u]) {
//			if (!st[v]) {
//				st[v] = true;
//				dist[v] = dist[u] + 1;
//				q.push(v);
//			}
//			if (dist[u] + 1 == dist[v])
//				cnt[v] = (cnt[v] + cnt[u]) % mod;
//		}
//	}
//}
//
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	bfs();
//	for (int i = 1; i <= n; i++)
//		cout << cnt[i] << endl;
//	return 0;
//}



//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//const int N = 1e6 + 10, mod = 100003;
//vector<int> g[N];
//int dist[N], cnt[N];
//bool st[N];
//
//void spfa() {
//	memset(dist, 0x3f, sizeof dist);
//	queue<int> q;
//	q.push(1);
////	st[1] = true;
//	dist[1] = 0;
//	cnt[1] = 1;
//	while (q.size()) {
//		auto u = q.front();
//		q.pop();
//
//		for (auto v : g[u]) {
//			if (dist[v] > dist[u] + 1) { // �����С
//				dist[v] = dist[u] + 1;
//				cnt[v] = cnt[u]; // cnt����ֱ�ӱ��u���
//				q.push(v);
//			} else if (dist[v] == dist[u] + 1) { // �������,����u���cnt����
//				cnt[v] = (cnt[v] + cnt[u]) % mod;
//			}
//		}
//	}
//}
//
//int main() {
//	int n, m;
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	spfa();
//	for (int i = 1; i <= n; i++)
//		cout << cnt[i] << endl;
//	return 0;
//}





//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int N = 200010, M = 1010;
//int n, m;
//int fa[M];
//
//typedef struct Node {
//	int a, b, t;
//	bool operator < (const Node &k) const {
//		return t < k.t;
//	}
//} node;
//vector<node> edge;
//
//int find(int x) {
//	if (x != fa[x])
//		fa[x] = find(fa[x]);
//	return fa[x];
//}
//int sum, ans;
//
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		fa[i] = i;
//	for (int i = 0; i < m; i++)  {
//		int a, b, t;
//		scanf("%d%d%d", &a, &b, &t);
//		edge.push_back({a, b, t});
//	}
//	sort(edge.begin(), edge.end()); // ������·ʱ������
//
//	for (int i = 0; i < edge.size(); i++) {
//		int x = find(edge[i].a), y = find(edge[i].b);
//		if (x == y)
//			continue; // �Ѿ���һ��������
//		fa[x] = y;
//		sum++; // �ϲ�һ�μ�1
//		ans = edge[i].t;
////		if (sum == n - 1)
////			cout << ans << endl;
//	}
//	if (sum != n - 1)
//		puts("-1");
//	else
//		cout << ans << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//const int N = 5010;
//int n, m; // �к���
//int s, w; // �к�Ů
//bool row[N], col[N];// ����к���
//
//int main() {
//	scanf("%d%d%d%d", &n, &m, &s, &w);
//	int row_num = 0, col_num = 0;
//	while(s--) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		for(int i = a; i <= b;i++) {
//			if(!row[i]) {
//				row[i] = true; // �����
//				row_num++; // ������1
//			}
//		}
//	}
//	while(w--) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		for(int i = a; i <= b;i++) {
//			if(!col[i]) {
//				col[i] = true;
//				col_num++; // ������1
//			}
//		}
//	}
//	int ans = n * row_num + col_num * (n - row_num);
//	cout << ans << endl;
//	return 0;
//}







// ��������
//#include <iostream>
//using namespace std;
//int ans;
//// 4���� 4����
//void dfs(string cur, int left, int right) {
//	if (left > 4 || right > 4)
//		return;
//	if (left == 4 & right == 4) {
//		ans++;
//		return;
//	}
//	if (left > right) {
//		dfs(cur + '(', left + 1, right);
//		dfs(cur + ')', left, right + 1);
//	} else
//		dfs(cur + '(', left + 1, right);
//}
//
//int main() {
//	string t = "";
//	dfs(t, 0, 0);
//	cout << ans;
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//char s[110];
//int main() {
//	cin >> s;
//	int n = strlen(s);
//	for (int i = 0; i < n; i++) {
//		printf("%c", s[i] + 3);
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int n, a, b, c;
//	int ans = 0;
//	cin >> n >> a >> b >> c;
//	for (int i = 1; i <= n; i++) {
//		if (i % a && i % b && i % c)
//			ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//const int N = 1010;
//int g[N][N];
//
//int main() {
//	int n, m;
//	int l, r;
//	cin >> n >> m;
//	int x = 1, y = 1, t = 1;
//	g[x][y] = t;
//	while (1) {
//		while (y < m)	{
//			g[x][++y] = ++t;
//			if (g[x][y + 1])
//				break;
//		}
//		if (t == n * m)
//			break;
//		while (x < n) {
//			g[++x][y] = ++t;
//			if (g[x + 1][y])
//				break;
//		}
//		if (t == n * m)
//			break;
//		while (y > 1) {
//			g[x][--y] = ++t;
//			if (g[x][y - 1])
//				break;
//		}
//		if (t == n * m)
//			break;
//		while (x > 1) {
//			g[--x][y] = ++t;
//			if (g[x - 1][y])
//				break;
//		}
//		if (t == n * m)
//			break;
//	}
//	cin >> l >> r;
//	cout << g[l][r] << endl;
//	//	for (int i = 1; i <= n; i++) {
////		for (int j = 1; j <= m; j++)
////			cout << g[i][j] << " ";
////		cout << endl;
////	}
//	return 0;
//}



//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//const int N = 1e5 + 10;
//vector<int> g[N];
//int n, m;
//int f[N]; // ��f[u]Ϊu����Ե�������ĵ�(��������)


//// ���򽨱ߣ��Ӵ��ŵ�����������ܵ�����Щ�㣬��1������ɢ�������
//void dfs(int u, int d) {
//	if(f[u])	return;
//	f[u] = d;
//	
//	for(int i = 0; i < g[u].size(); i++) {
//		int j = g[u][i];
//		dfs(j, d); // d�Ǹ����ڵ㣬�൱�ڴ���������������������	
//	}
//	
//}

//int main() {
//	scanf("%d%d", &n, &m);
//	while (m--) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		g[b].push_back(a); // b->a ���򽨱�
//	}
//	for (int i = n; i >= 1; i--)
//		dfs(i);
//	for (int i = 1; i <= n; i++)
//		cout << f[i] << " ";
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<set>
//using namespace std;
//const int N = 20;
//int f[N][70000];
//string s[N];
//int n;
//bool g[N][N];


//int dfs(int now, int S) { // now ��ʾ��ǰ���һ�����ʣ�S��ʾ��ǰ���ϵ�״̬ 
//	if(f[now][S] != -1) return f[now][S];
//	f[now][S] = s[now].size();
//	int t = 0;
//	for(int i = 0; i < n; i++) {
//		if(g[now][i] && !(S & (1 << i))) { // S�����в������õ������ܽӵ����� 
//			t = max(t, dfs(i, S | (1 << i)));
//		}
//	}
//	f[now][S] += t;
//	return f[now][S];
//}

//int main() {
//	memset(f, -1, sizeof f);
//	cin >> n;
//	for(int i = 0; i < n; i++) {
//		cin >> s[i];
//	}
//	for(int i = 0; i < n; i++)
//		for(int j = 0; j < n; j++) {
//			if(i == j)	continue;
//			int len = s[i].size();
//			if(s[i][len - 1] == s[j][0])	g[i][j] = 1; // j���Խӵ�i�ĺ��� 
//		}
//	
//	int maxlen = 0;
//	for(int i = 0; i < n; i++) {
//		maxlen = max(maxlen, dfs(i, 1 << i)); // �Ե�i�����ʿ�ͷ 
//	}
//	cout << maxlen << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 100010;
//int fa[N];
//struct Edge {
//	int a, b, t;
//	bool operator < (const Edge& k) const {
//		return t < k.t;
//	}
//}edges[N];
//int n, m;

//int find(int x) {
//	if(x != fa[x])	fa[x] = find(fa[x]);
//	return fa[x];
//}

//int main() {
//	scanf("%d%d", &n, &m);
//	for(int i = 1; i <= n; i++)	fa[i] = i;
//	for(int i = 0; i < m; i++) {
//		scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].t);
//	}
//	sort(edges, edges + m);
//	int ans = 0, cnt = 0;
//	for(int i = 0; i < m; i++) {
//		int a = edges[i].a, b = edges[i].b, t = edges[i].t;
//		int na = find(a), nb = find(b);
//		if(na != nb) {
//			fa[na] = nb; // ��ͨ������
//			cnt++; // ����һ����
//			ans = t; 
//		}
//	}
//	if(cnt != n - 1)	puts("-1");
//	else cout << ans << endl;
//	
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//const int N = 15;
//bool col[N], du[N * 2], au[N * 2];
//int n;
//vector<vector<int>> g;
//vector<int> res;

//void dfs(int u) {
//	if(u > n) {
//		g.push_back(res);
//		return;
//	}
//	
//	for(int i = 1; i <= n; i++) {
//		if(!col[i] && !du[u + i] && !au[u - i + n]) {
//			col[i] = true;
//			du[u + i] = true;
//			au[u - i + n] = true;
//			res.push_back(i);
//			dfs(u + 1);
//			res.pop_back();
//			col[i] = false;
//			du[u + i] = false;
//			au[u - i + n] = false;
//		}
//	}	
//}

//int main() {
//	cin >> n;
//	dfs(1);
//	
//	for(int j = 0; j < 3; j++){
//		auto t = g[j];
//		for(int i = 0; i < t.size(); i++)
//			cout << t[i] << " ";
//		cout << endl;
//	}
//	cout << g.size();
//		
//	return 0;
//}


#include<iostream>
using namespace std;

int main() {
	
	return 0;
}



