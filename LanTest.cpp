// ���ű���ϰϵͳ

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
//		re
//		cin >> hex;
//		hex_to_de(hex);s.push_back(r); // ����
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


#include <iostream>
using namespace std;
typedef int ElemType;
//�������ṹ
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *left, *right;
} BiTNode, *BiTree; // BiTree��ָ�����͵�


// �������
void InorderTraverse(BiTree T) {
	if (T) {
		InorderTraverse(T->left);
		cout << T->data << " ";
		InorderTraverse(T->right);
	}
}

// ǰ�����
void PreorderTraverse(BiTree T) {
	if (T) {
		cout << T->data << " ";
		PreorderTraverse(T->left);
		PreorderTraverse(T->right);
	}
}

// �������
void LastorderTraverse(BiTree T) {
	if (T) {
		LastorderTraverse(T->left);
		LastorderTraverse(T->right);
		cout << T->data << " ";
	}
}

//����������
void createBiTree(BiTree &T) {
	ElemType d;
	cin >> d;
	if (d == -1)
		T = NULL;
	else {
		T = new BiTNode;
		T->data = d;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

void Copy(BiTree T, BiTree &newT) {
	if(T == NULL) {
		newT = NULL;
		return;
	}
	else {
		newT = new BiTNode;
		newT->data = T->data; // ���Ƹ��ڵ�
		Copy(T->left, newT->left);
		Copy(T->right, newT->right);
	}
}
int main() {
	BiTree T;
	cout << " ��������Ҫ��������" << endl;
	createBiTree(T);
	cout << "�������" << endl;
	InorderTraverse(T);
	cout << endl;
	cout << "ǰ�����" << endl;
	PreorderTraverse(T);
	cout << endl;
	cout << "�������" << endl;
	LastorderTraverse(T);
	return 0;
}





