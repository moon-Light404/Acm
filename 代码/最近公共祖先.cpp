// tarjin�㷨
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 500010;
int h[N], e[N], ne[N], idx;
int n, m, s; // sΪ���ڵ�
int f[N]; // ָ���Ǹ��ڵ�
bool st[N]; // ��Ǹø��ڵ�������Ƿ��������
// ���ϵĸ��ڵ�

int g[N][N]; // i��j����С��������
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
		merge(v, u); // ��v�ϲ���u
		st[v] = true;
	}
	// ��u��ѯ�ʹ�ϵ�ĵ�
	for(auto k : que[u]) {
		if(st[k] && g[u][k] != 0x3f3f3f3f) {
			g[u][k] = g[k][u] = find(k);
		}
	}
		
}

int main() {
	memset(g, 0x3f, sizeof g);
	cin >> n >> m >> s;
	for(int i = 1; i <= N;i++)	f[i] = i; // ������ϵĸ��ڵ����Լ�
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