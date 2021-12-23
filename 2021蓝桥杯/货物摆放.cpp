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

// ��������(���ظ�����������˵���ԭ��)
void fen() {
	LL now = n;
	for (int i = 1; i <= cnt; i++)
		while (n % prime[i] == 0)
			n /= prime[i], mid.push_back(1LL * prime[i]);
}

// ��Ҫ����
void dfs(int ff, int now, LL mul) {
	cout << "ff:" <<  ff << "  now: " <<  now << "   mul:  " << mul << endl;
	if (now == mid.size()) { // ����������ѡ����(һ��)
		x[ff] = mul; // ��¼�˴�ѡ���ĳ˻�
		if (ff == 1) { // ����˴��Ѿ�ѡ��������
			x[2] = n / x[1] / x[0]; // ֱ�������������
			if (s.find(node(x[0], x[1], x[2])) != s.end())
				return;
			s.insert(node(x[0], x[1], x[2]));
			res++; // �ڼ����ж��������(3��)ȥ��
		} else
			dfs(ff + 1, 0, 1); // ������һ������
		// 0��ʾ�ӵ�һ������ʼѡ����ʱ��һ�ֵ������Ѿ�ѡ��������һ��ѡ��ʱ������
		return;
	}
	if (f[now] == 0) {
		f[now] = 1; // ѡ���λ���ϵ����֣����
		dfs(ff, now + 1, mul * mid[now]);
		f[now] = 0; // �ָ�ȥ�����
		dfs(ff, now + 1, mul); // ��ѡ��f[now]Ĭ��0
	} else
		dfs(ff, now + 1, mul); // f[now]=1,������Ѿ���ǰһ��ѡ����
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
	// ������������λ�á��˻�(Ҫѡ3��)
	printf("%d\n", res);
	return 0;
}
