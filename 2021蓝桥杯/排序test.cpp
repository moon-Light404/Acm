#include <iostream>
using namespace std;
const int N = 100;
int a[N];

// ð������
//void bubblesort(int a[], int n) {
//	for (int i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (a[j] > a[j + 1])
//				swap(a[j], a[j + 1]);
//		}
//}


// ѡ������
//void selectSort(int a[], int n) {
//	int idx;
//	for (int i = 0; i < n - 1; i++) {
//		idx = i;
//		for (int j = i + 1; j < n; j++) {
//			if (a[j] < a[idx]) {
//				idx = j; // �ҵ�δ�������е���Сֵ
//			}
//		}
//		swap(a[idx], a[i]);
//	}
//}

// ��������
//void insertSort(int a[], int n) {
//	int pre, cur;
//	for (int i = 1; i < n; i++) {
//		pre = i - 1;
//		cur = a[i];
//		while (pre >= 0 && cur < a[pre]) { // cur��ǰ�����С
//			a[pre + 1] = a[pre];
//			pre--;
//		}
//		a[pre + 1] = cur;
//	}
//}





int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	insertSort(a, n);
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
	int n = -1;
	cout << (n + 10) % 10 << endl;
	return 0;
}