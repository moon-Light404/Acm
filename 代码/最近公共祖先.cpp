// tarjin算法
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 500010;
int h[N], e[N], ne[N], idx;
int n, m, s; // s为根节点
int f[N]; // 指的是根节点
bool st[N]; // 标记该根节点的子树是否搜索完毕
// 集合的根节点

int g[N][N]; // i和j的最小公共祖先
int find(int i) {
	if(i != f[i])	return f[i] = find(f[i]);
	return f[i];
}

void merge(int i, int j) {
	f[i] = find(f[j]);
}

void add(int a,int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u) {
	for(int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];
		dfs(v);
		merge(v, u); // 把v合并到u
		st[v] = true;
	}
	// 与u有询问关系的点
	for(auto k : que[u]) {
		if(st[k] && g[u][k] != 0x3f3f3f3f) {
			g[u][k] = g[k][u] = find(k);
		}
	}
		
}

int main() {
	memset(g, 0x3f, sizeof g);
	cin >> n >> m >> s;
	for(int i = 1; i <= N;i++)	f[i] = i; // 起初集合的根节点是自己
	for(int i = 0; i < n - 1;i++) {
		int a, b;
		scanf("%d%d", &a,&b);
		add(a,b);
	}
	for(int i = 0; i < m;i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[l].push_back(r);
		que[r].push_back(l);
	}
	dfs(s);
	
	return 0;
}