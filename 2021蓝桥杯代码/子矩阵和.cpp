#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

// ��b����ƥ��a���е����֣�����iָ��b[0], jָ��a[0],һֱ����iֱ��b[i]==a[j],��ʱj++,�����ң������j�Ƿ񳬹��˷�Χ
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i]; // ��Ҫ�ҵ�������
	for (int i = 0 ; i < m ; i++)
		cin >> b[i];
	int i = 0, j = 0;
	while (i < m && j < n) {
		cout << " ��ǰi��j��ֵ" << i << " " << j << endl;

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