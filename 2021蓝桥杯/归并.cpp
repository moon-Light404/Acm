#include <iostream>
#include <cmath>
using namespace std;

const int N = 10010;
int q[N];

void merge(int a[], int l1, int r1, int l2, int r2) {
	int i = l1, j = l2;
	int index = 0;
	int temp[N];
	while (i <= r1 && j <= r2) {
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		if (a[i] >= a[j])
			temp[index++] = a[j++];
	}
	while (i <= r1)
		temp[index++] = a[i++];
	while (j <= r2)
		temp[index++] = a[j++];
	for (int k = 0; k < index; k++)
		a[l1 + k] = temp[k];
}

void mergeSort(int A[], int left, int right) {
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid + 1, right);
	merge(A, left, mid, mid  + 1, right);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	mergeSort(q, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << q[i] << " ";
	return 0;
}