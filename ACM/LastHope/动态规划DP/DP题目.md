**别人的博客**：https://blog.csdn.net/zesong2019/article/details/115493248

#### 最大子矩阵和

思路：1、用前缀和思想，`pre[i][j]`表示 第$j$ 列 中的前 $i(行)$个数的和，先初始化

2、遍历子矩阵的上界和下界(上行和下行)，即确定一个上界和下界，然后把这之间的每一列当成一个元素去从左到右遍历每一列。

3、按照最大子段和的方法对每一个确定的上界和下界进行列的遍历。

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int a[N][N], pre[N][N];
int ans;

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			pre[i][j] = pre[i-1][j] + a[i][j];
			cout << pre[i][j] << " ";
		} 
		cout << endl;
	}
	
	for(int i = 1; i <= n; i++) // 上界 
		for(int j = i; j <= n; j++) { // 下界 
			int sum = 0;
			for(int k = 1; k <= m; k++) {
				if(sum + pre[j][k] - pre[i-1][k] < 0) {
					sum = 0;
				}else 
					sum += pre[j][k] - pre[i-1][k];
				ans = max(ans, sum);
			}
		}
	cout << ans << endl;
	return 0;
}
```

