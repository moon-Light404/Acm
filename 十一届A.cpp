//#include <iostream>

//using namespace std;
//
//int main() {
//	int cnt = 0;
//	for (int i = 1; i <= 2020; i++) {
//		int t = i;
//		while (t) {
//			if (t % 10 == 2)
//				cnt++;
//			t /= 10;
//		}
//	}
//	cout << cnt;
//	return 0;
//}


// 2481215
//#include <iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	int cnt = 0;
//	for (int i = 1; i <= 2020; i++)
//		for (int j = 1; j <= 2020; j++) {
//			if (gcd(i, j) == 1)
//				cnt++;
//		}
//	cout << cnt;
//	return 0;
//}

// 761
//#include <iostream>
//using namespace std;
//const int N = 101;
//int a[N][N];
//int main() {
//	int cnt = 1;
//	int i = 1, j = 1;
//	a[i][j] = 1;
//	while (cnt < 1000) {
//		if (i == 1)
//			j++;
//		a[i][j] = ++cnt;
//
//		while (j > 1)
//			a[++i][--j] = ++cnt;
//
//		if (j == 1)
//			i++;
//		a[i][j] = ++cnt;
//
//		while (i > 1)
//			a[--i][++j] = ++cnt;
//
//	}
//	cout << a[20][20];
//	return 0;
//}



























// �𰸣�80
//#include <iostream>
//#include <set>
//using namespace std;
//set<set<int>> ss; // �ڲ��洢����һ�����ּ���
//// a1 b2 c3 d4 e5 f6 g7 �����ֱ�ʾ�ַ�
//int map[8][8];
//bool st[8]; // �Ƿ�ѡ��
//int cnt;
//
//// ��uΪ�������ĵƹ�
//void dfs(int u, set<int> s) {
//	// û�г��ֹ�������
//	if (!ss.count(s)) {
//		ss.insert(s);
//		cnt++;
//	}
//	if (s.size() == 7)
//		return;
//
//	for (int i = 1; i <= 7; i++) {
//		if (map[u][i] && !st[i]) {
//			st[i] = true;
//			s.insert(i);
//			dfs(i, s);
//			// �ָ��ֳ�
//			st[i] = false;
//			s.erase(i);
//		}
//	}
//}
//
//int main() {
//	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;
//	map[a][b] = map[a][f] = 1;
//	map[b][a] = map[b][g] = map[b][c] = 1;
//	map[c][b] = map[c][g] = map[c][d] = 1;
//	map[d][c] = map[d][e] = 1;
//	map[e][d] = map[e][g] = map[e][f] = 1;
//	map[f][e] = map[f][a] = map[f][g] = 1;
//	map[g][f] = map[g][b] = map[g][e] = map[g][c] = 1;
////	set<int> a;
////	a.insert(1);
////	dfs(1);
//	for (int i = 1; i <= 7; i++) {
//		set<int> s;
//		s.insert(i);
//		dfs(i, s);
//	}
//	cout << ss.size() << endl;
//	return 0;
//}



































// ��������
//#include <iostream>
//using namespace std;
//int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int res1, res2;
//bool f1, f2; // ����������ڶ��ҳ���
//
//bool is_leap(int year) {
//	if (year % 4 == 0 && year % 100)
//		return true;
//	if (year % 400 == 0 )
//		return true;
//	return false;
//}
//
//int Getsum(int a[]) {
//	int sum = 0;
//	for (int i = 1; i <= 4; i++) {
//		sum = sum * 10  + a[i];
//	}
//	for (int i = 4; i >= 1; i--) {
//		sum = sum * 10 + a[i];
//	}
//	return sum;
//}
//
//int main() {
//	int n;
//	cin >> n; // ���������
//
//	int now = n / 10000; // ȡ�����
//	for (int year = now; ; year++) {
////		cout << "��ǰ���" << year << endl;
//		int a[10]; // �洢���ڸ�λ����
//		int t = year;
//		for (int i = 4; i >= 1; i--) {
//			a[i] = t % 10;
//			t /= 10;
//		}
//		int m = a[4] * 10 + a[3];
//		if (m > 12)
//			continue; // �·ݺϷ�
//		int d = a[2] * 10 + a[1];
//		// 2�·�����
//		if (m == 2 && d > day[2] + is_leap(year))
//			continue;
//		if (m != 2 && d > day[m])
//			continue;
//
//		int newYear = Getsum(a);
//		cout << "�������ڣ�" << newYear << endl;
//		if (newYear <= n)
//			continue;
//
//		if (!f1) {
//			res1 = newYear;
//			f1 = true;
//		}
//		// ABAB
//		if (a[1] == a[3] && a[2] == a[4] && a[1] != a[2]) {
//			res2 = newYear;
//			f2 = true;
//		}
//		// �������ڶ��ҵ���
//		if (f1 && f2)
//			break;
//
//	}
////	int a[5] = {0, 1, 2, 3, 4};
////	cout << Getsum(a);
//	cout << res1 << " " << res2 << endl;
//	return 0;
//}


// �ִ���ֵ
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 28;
//int pre[N], nxt[N];
//int last[N]; // Ĭ����һ�γ��ֵ�λ��Ϊ0
//string s;
//// ababc
//int main() {
//	cin >> s;
//	s = "0" + s;
//	int n = s.size() - 1;
//	// ��¼�뵱ǰλ����ĸ��ͬ��ǰһ��λ��
//	for (int i = 1; i <= n; i++) {
//		int c = s[i] - 'a'; // ����ĸת��Ϊ����
//		pre[i] = last[c]; // �뵱ǰλ����ĸ��ͬ����һ����ĸ��λ��
//		last[c] = i; // ��¼��ĸc�³��ֵ�λ��
//	}
//
////	for (int i = 1; i <= n; i++) {
////		cout << pre[i] << " ";
////	}
//	// ��¼�뵱ǰλ����ĸ��ͬ����һ��λ��
//	for (int i = 0; i < N; i++)
//		last[i] = n + 1;
//
//	for (int i = n; i >= 1; i--) {
//		int c = s[i] - 'a';
//		nxt[i] = last[c];
//		last[c] = i;
//	}
////	for (int i = 1; i <= n; i++)
////		cout << nxt[i] << " ";
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += (i - pre[i]) * (nxt[i] - i);
//	}
//	cout << sum;
//	return 0;
//}







