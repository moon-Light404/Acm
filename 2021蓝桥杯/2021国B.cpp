// ��Ȥ����




//#include <iostream>
//#include <cmath>
//#define ll long long
//using namespace std;
//const int N = 1e8 + 5;
//int a[N], w[N];
//int t;
//
//void init() {
//	int d = 1, k = 1;
//	for (int i = 1; i < N; i++) {
//		if (d <= k) {
//			a[i] = d;
//			d++;
//		} else {
//			i--; // ��ʱiλ��û��¼�����֣�����Ҫ������ѭ�������ٴ�+1
//			d = 1;
//			k++;
//		}
//	}
//}
//
//signed main() {
//	init();
//	for (int i = 1; i < 100; i++)
//		cout << a[i] << " ";
//	for (int i = 1; i < N; i++) {
//		w[i] = w[i - 1] + a[i]; // ����ǰ׺��
//	}
//	cin >> t;
//	int k, j;
//	while (t--) {
//		cin >> k >> j;
//		if (k == j)
//			cout << a[k] << endl;
//		else
//			cout << w[j] - w[k - 1] << endl;
//	}
//}


// ����������
//#include <iostream>
//using namespace std;
//int n, k;
//
//int get_sum(int n) {
//	int sum = 0;
//	while (n) {
//		if (n & 1)
//			sum++;
//		n >>= 1;
//	}
//	return sum;
//}
//
//int main() {
//	cin >> n >> k;
//	int res = 0;
//	for (int i = 1; i <= n; i++) {
//		if (get_sum(i) == k) {
//			res++;
//			cout << i << " ";
//		}
//
//	}
//	cout << res;
//	return 0;
//}