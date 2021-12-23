## 逆序对的数量

给定一个长度为 nn 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 ii 个和第 jj 个元素，如果满足 i<ji<j 且 a[i]>a[j]a[i]>a[j]，则其为一个逆序对；否则不是。

#### 输入格式

第一行包含整数 nn，表示数列的长度。

第二行包含 nn 个整数，表示整个数列。

#### 输出格式

输出一个整数，表示逆序对的个数。

#### 数据范围

1≤n≤1000001≤n≤100000

#### 输入样例：

```
6
2 3 4 5 6 1
```

#### 输出样例：

```c++
5
```

![image-20210404125125710](https://i.loli.net/2021/04/04/i3lLKd6ezn7Irap.png)



```c++
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N];
LL ans;

void merge(int l1, int r1, int l2, int r2) {
	int tmp[r2 - l1 + 1];
	int index = 0;
	int j = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (a[l1] <= a[l2])
			tmp[index++] = a[l1++];

		else {
			// 记录逆序对的数量,即前面的数大于后面的
//			cout << "sucess";
			ans += r1 - l1 + 1;
			tmp[index++] = a[l2++];
		}
	}
	while (l1 <= r1)
		tmp[index++] = a[l1++];
	while (l2 <= r2)
		tmp[index++] = a[l2++];
	for (int i = 0; i < index; i++)
		a[j + i] = tmp[i]; // 修改l1
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(left, mid, mid + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergeSort(a, 0, n - 1); // 0和n-1都是下标
//	for (int i = 0; i < n; i++)
//		cout << a[i];
	cout << ans;
	return 0;
}
```

