#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

// 在b中找匹配a序列的数字，先让i指向b[0], j指向a[0],一直递增i直到b[i]==a[j],这时j++,继续找，看最后j是否超过了范围
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i]; // 需要找的子序列
	for (int i = 0 ; i < m ; i++)
		cin >> b[i];
	int i = 0, j = 0;
	while (i < m && j < n) {
		cout << " 当前i、j的值" << i << " " << j << endl;

		while (a[i] != a[j]) {
			cout << "a[i] : " << a[i] << endl;
			i++;
		}
		if (a[i] == a[j])
			j++;
	}

	if (j == n)
		cout << "Yes";
	else if (j < n)
		cout << "No";
	return 0;
}