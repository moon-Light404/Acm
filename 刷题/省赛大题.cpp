// Ð¡Æ½·½
#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x = (i * i % n) * 2;
		if (x < n)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}


