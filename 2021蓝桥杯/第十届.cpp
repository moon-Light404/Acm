// ������ֵ 2857

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 1, b = 1;
//	int k = 0;
//	for (int i = 4; i <= 20190324; i++) {
//		k = (a + b) % 10000;
//		a = b;
//		b = k;
//	}
//	cout << k;
//	return 0;
//}















// RSA
//#include <iostream>
//using namespace std;
//typedef long long ll;
void BF(ll x) {
	cout << x << " =";
	for (ll i = 1e8 + 1; i < x; i += 2) {
		if (x % i == 0) {
			cout << i << " * ", x /= i;
		}
	}
	cout << x;
}
//void extgcd(ll a, ll b, ll &x, ll &y) {
//	if (b == 0) {
//		x = 1;
//		y = 0;
//		return;
//		// ��b=0��gcd(a,b)=a,ax+by=a
//	}
//	extgcd(b, a % b, x, y);
//	ll t = y;
////	x = y;
////	y = t - a / b * y;
//	y = x - a / b * y;
//	x = t;
//	return;
//}

// ���ٳ�,���˷���Ϊ�ӷ�����ֹ�˷���longlong
//ll fast_pro(ll a, ll b, ll mod) {
//	ll ans = 0;
//	while (b) {
//		if (b & 1)
//			ans = (ans + a) % mod;
//		a = (a + a) % mod;
//		b >>= 1;
//	}
//	return ans;
//}

//a * b mod (mod)
//ll get_pow(ll a, ll b, ll mod) {
//	ll ans = 1;
//	while (b) {
//		if (b & 1)
//			ans = fast_pro(ans, a, mod);
//		a = fast_pro(a, a, mod);
//		b >>= 1;
//	}
//	return ans;
//}

//
//void exgcd(ll a, ll b, ll &x, ll &y) {
//	if (b == 0) {
//		x = 1;
//		y = 0;
//		return;
//	}
//	exgcd(b, a % b, y, x);
//	y -= (a / b) * x;
//}
//
//ll rev(ll t, ll m) {
//	ll  x, y;
//	exgcd(t, m, x, y);
//	return (x % m + m) % m;
//}
//e = 823816093931522017

//int main() {
////	BF(1001733993063167141);
////	ll x = 0, y = 0;
////	ll d = 212353;
////	ll n = 1001733991047948000;
////	extgcd(d, n, x, y);
////	cout << (x + n) % n;
//// ��Ԫ 823816093931522017
//	ll a = 20190324, b = 823816093931522017;
//	ll n = 1001733993063167141;
//	cout << get_pow(a, b, n);
//	return 0;
//}

// ��ȫ��������Ȩֵ
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100010;
int a[N];
int n;
int main() {
//	 �±��1��ʼ�����Ϊk�ڵ���=2^(k-1),�ڵ�����Ϊ2^k-1
//	cin >> n;
//	int ans = 0, sum, deep; // ��С���
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//	for (int i = 1; i <= log2(n + 1); i++) { // ��������
//		sum = 0;
//		for (int j = pow(2, i - 1); j <= n && j <= pow(2, i) - 1; j++) {
//			sum += a[j];
//		}
//		cout << sum << endl;
//		if (i == 1 || sum > ans)	{
//			ans = sum, deep = i; // i�������
//		}
//	}
//	cout << deep;
//	return 0;
	cout << log2(8) << endl;
}