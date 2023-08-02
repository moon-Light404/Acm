#include <iostream>
using namespace std;
const int N = 100010;
int children[N][26], cnt[N], idx;
char s[N];

void insert(char *s) {
	int p = 0; // idx��0��ʼ���������ڵ�û������
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			children[p][u] = ++idx; // ���� p->u �ı�
		p = children[p][u]; // �ӵ�ǰ�����������һ����
	}
	cnt[p]++; // ���p��������ַ��ڵ������ֵ
}

int query(char *s) {
	int p = 0; // �Ӹ��ڵ㿪ʼ����
	for (int i = 0; s[i]; i++) {
		int u = s[i] - 'a';
		if (!children[p][u])
			return 0; // �м�ֵ��ƥ�䣬�Ͳ������²�����
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