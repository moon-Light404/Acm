//// ���ű�����

//// ������
//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 20210605;
//bool st[N];
//
//vector<int> prime; // ������
//int main() {
//	int ans = 0;
//	st[1] = st[0] = true; // 0��1��������
//	for (int i = 2; i <= N; i++) {
//		if (!st[i]) {
//			prime.push_back(i);
//			int temp = i;
//			bool flag = true;
//			while (temp) {
//				if (st[temp % 10]) {
//					flag = false;
//					break;
//				}
//				temp /= 10;
//			}
//			if (flag)
//				ans++; // ������
//		}
//		for (int j = 0; i * prime[j] <= N; j++) {
//			st[i * prime[j]] = true; // ������
//			if (i % prime[j] == 0)
//				break;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

// ��СȨֵ
//#include <iostream>
//#include <cstring>
//using namespace std;
//typedef long long LL;
//const int N = 2021;
//LL INF = 1e18;
//LL f[N];
//int main() {
//	memset(f, 127, sizeof f);
//	f[1] = 1;
//	for (int i = 1; i <= N; i++) {
//		if (i == 1)
//			continue;
//		for (int j = 0; j < i; j++) { // ���������Ľ�����Ϊj
//			int l = j, r = i - 1 - j;
//			f[i] = min(f[i], 1 + 2 * f[l] + 3 * f[r] + l * l * r);
//		}
//	}
//	cout << f[2021];
//	return 0;
//}





















// ��������(״ѹDP)
//#include <iostream>
//using namespace std;
//const int N = 10;
//int f[N][1 << 8]; // f[i][j]��ʾǰi-1���Ѿ��ںã������굽��i�е�״̬Ϊj
//const int M = 1 << 8;
//
//// �ж�������0�ǲ���ż��
//bool isP(int y) {
//	int res = 0;
//	for (int i = 0; i < 8; i++) {
//		if (y >> i & 1) {
//			if (res & 1)
//				return false; // ������0
//			res = 0;
//		} else
//			res++;
//	}
//	if (res & 1)
//		return false;
//	return true;
//}
//
//int main() {
////	int n;
////	while (cin >> n)
////		cout << isP(n) << endl;
//	f[1][0] = 1;
//	for (int i = 2; i <= 9; i++) {
//		for (int state = 0; state < M; state++) // ���굽��i�е�״̬
//			for (int j = 0; j < M; j++) { // ���굽��i-1�е�״̬
//				if (state & j)
//					continue; // ����ռ��ͬһ��λ��
//				if (!isP(state | j))
//					continue;
//				f[i][state] += f[i - 1][j];
//			}
//	}
//	cout << f[9][0] << endl;
//	return 0;
//}

// �����������
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef long long LL;
//const int N = 1e7;
//LL a[N];
//LL sum[N];
//void init() {
//	for (LL i = 1; i <= N; i++) {
//		a[i] = i * (i + 1) / 2;
//		sum[i] = sum[i - 1] + a[i];
//	}
//}
//
//LL get_res(LL x) {
//	LL n = upper_bound(a + 1, a + N, x) - (a + 1); // ��x�����ڵڼ���ĺ���
//	LL temp = x - n * (n + 1) / 2; // ��ȥǰ�����з�����ܸ���
//	return sum[n] + (1 + temp) * temp / 2;
//}
//
//int main() {
//	init();
//
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		LL l, r;
//		scanf("%lld%lld", &l, &r);
//		printf("%lld\n", get_res(r) - get_res(l - 1));
//	}
//	return 0;
//}



