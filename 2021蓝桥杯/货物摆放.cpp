#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int inf = 0x3f3f3f3f;
const int maxn = 5e6 + 5;
const int N = 1e7 + 15;
const LL mod = 998244353;
const double pi = acos(-1);

struct node {
	int a, b, c;
	node(int aa, int bb, int cc) {
		a = aa, b = bb, c = cc;
	}
	friend bool operator < (node x, node y) {
		if (x.a == y.a) {
			if (x.b == y.b)
				return x.c < y.c;
			return x.b < y.b;
		}
		return x.a < y.a;
	}
};
set<node>s;
LL n, x[5];
int cnt, prime[maxn], res;
bool is_prime[N], f[maxn];
vector<LL>mid;

void __prime() {
	for (int i = 1; i <= N - 5; i++)
		is_prime[i] = 1;
	is_prime[1] = 0;
	for (int i = 2; i <= N - 5; i++)
		if (is_prime[i]) {
			prime[++cnt] = i;
			for (int j = i; j <= N - 5; j += i)
				is_prime[j] = 0;
		}
}
/*
2021041820210418
2 3 3 3 17 131 2857 5882353
*/

// 求质因数(可重复，所以数相乘等于原数)
void fen() {
	LL now = n;
	for (int i = 1; i <= cnt; i++)
		while (n % prime[i] == 0)
			n /= prime[i], mid.push_back(1LL * prime[i]);
}

// 主要函数
void dfs(int ff, int now, LL mul) {
	cout << "ff:" <<  ff << "  now: " <<  now << "   mul:  " << mul << endl;
	if (now == mid.size()) { // 把所有因数选完了(一轮)
		x[ff] = mul; // 记录此次选数的乘积
		if (ff == 1) { // 如果此次已经选完了两轮
			x[2] = n / x[1] / x[0]; // 直接求出第三个数
			if (s.find(node(x[0], x[1], x[2])) != s.end())
				return;
			s.insert(node(x[0], x[1], x[2]));
			res++; // 在集合中对这对数字(3个)去重
		} else
			dfs(ff + 1, 0, 1); // 遍历下一个乘数
		// 0表示从第一个数开始选，此时第一轮的数字已经选过，被第一轮选的时候标记了
		return;
	}
	if (f[now] == 0) {
		f[now] = 1; // 选这个位置上的数字，标记
		dfs(ff, now + 1, mul * mid[now]);
		f[now] = 0; // 恢复去除标记
		dfs(ff, now + 1, mul); // 不选，f[now]默认0
	} else
		dfs(ff, now + 1, mul); // f[now]=1,这个数已经被前一轮选过了
}

int main() {
	__prime();
//	scanf("%lld", &n);
	n = 2021041820210418;
	fen();
	for (int i = 0; i < mid.size(); i++)
		printf("%d ", mid[i]);
	printf("\n");
	dfs(0, 0, 1);
	// 轮数、因数的位置、乘积(要选3个)
	printf("%d\n", res);
	return 0;
}
