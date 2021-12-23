/*纯质数
*/
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 20210610;

bool prime[N];

void find_prime() {
	prime[0] = 1;
	prime[1] = 1; // 非素数
	for (ll i = 2; i <= N; i++) {
		if (!prime[i]) {
			for (ll j = i * i; j <= N; j += i) {
				prime[j] = 1; // 非素数
			}
		}
	}
}

int main() {
	find_prime();
	int sum = 0; // 记录个数
	for (int k = 1; k <= 20210605; k++) {
		if (!prime[k]) {
			int i = k;
			while (i) {
				if (!prime[i % 10]) {
					i /= 10;
					continue;
				} else
					break;
			}
			if (i == 0) {
				sum++;
				cout << k << " ";
			}

		}

	}
	cout << sum;
	return 0;
}