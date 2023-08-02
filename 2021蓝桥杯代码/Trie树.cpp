#include <iostream>
using namespace std;
const int N = 100010;
int children[N][26], cnt[N], idx;
char s[N];

void insert(char *s) {
	int p = 0; // idx从0开始遍历，根节点没有数据
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			children[p][u] = ++idx; // 增加 p->u 的边
		p = children[p][u]; // 从当前索引继续查找或插入
	}
	cnt[p]++; // 最后p代表最后字符节点的索引值
}

int query(char *s) {
	int p = 0; // 从根节点开始查找
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			return 0; // 中间值都匹配，就不用往下查找了
		p = children[p][u];
	}
	return cnt[p];
}

int main() {
	int n;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'I') {
			cin >> s;
			insert(s);
		}

		else if (c == 'Q') {
			cin >> s;
			cout << query(s);
		}

	}

	return 0;
}