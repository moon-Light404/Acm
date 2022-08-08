<a href = "https://www.acwing.com/problem/content/900/">acwing898</a>

给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

```
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
```

#### 输入格式

第一行包含整数 nn，表示数字三角形的层数。

接下来 nn 行，每行包含若干整数，其中第 ii 行表示数字三角形第 ii 层包含的整数。

#### 输出格式

输出一个整数，表示最大的路径数字和。

#### 数据范围

1≤n≤5001≤n≤500,
−10000≤三角形中的整数≤10000−10000≤三角形中的整数≤10000

#### 输入样例：

```
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
```

#### 输出样例：

## 递推写法
```
30
```

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 510;
int a[N][N], f[N][N]; // f[i][j] 表示从(i,j)到底层可以到达的最大值
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    
    for(int i = 1;i <= n;i++)   f[n][i] = a[n][i];
    
    for(int i = n - 1; i >= 1;i--) // 因为已知的是最后一层，所以从下面往上递推直到第一层
        for(int j = 1;j <= i;j++)
            f[i][j] = a[i][j] + max(f[i+1][j], f[i+1][j+1]);
    cout << f[1][1];
    return 0;
}
```

## 递归写法(只适用于非负整数)
```c++
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
int a[N][N], f[N][N]; // f[i][j] 表示从(i,j)到底层可以到达的最大值
int n;
int solve(int i, int j) // i,j 是坐标
{
    if (f[i][j] >= 0)   return f[i][j];
    return a[i][j] + (i == n ? 0 : max(solve(i+1, j),solve(i+1,j+1)));
}
int main()
{
    memset(f,-1,sizeof f);
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    
    cout << solve(1,1);
    return 0;
}
```

<a href = "https://www.acwing.com/solution/content/41326/">数字三角形变形细节</a>

<u>题意</u>

对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。

路径上的每一步只能从一个数走到下一层和它最近的左边的那个数或者右边的那个数。

此外，向左下走的次数与向右下走的次数相差不能超过 1。



==解析==

此题需要记录向左下和右下的步数，我们可以用一个下标记录向右或向左走的次数，然后根据总步是偶数还是奇数直接取下标,然后找到最大值

x + y == n  |x-y| <= 1

```c++
#include <iostream>
#include <algorithm>
#include <cstdio>
int s[110][110], n;
int f[110][110][110];


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			scanf("%d", &s[i][j]);
	}
	for (int i = 1; i <= n; i++)
		f[n][i][0] = s[n][i];/*在最后一层n，向左下走0步的最大值即为s[n][i]*/
	for (int i = n - 1; i >= 1; i--) { /*从下面往上遍历，避免边界等问题*/
		for (int j = 1; j <= i; j++) {
			for (int k = 0; k <= n - i; k++) {
				f[i][j][k] = f[i + 1][j + 1][k] + s[i][j]; /*从右下上来*/
				if (k >= 1)
					f[i][j][k] = std::max(f[i][j][k], f[i + 1][j][k - 1] + s[i][j]);
			}
		}
	}
	int res = 0;
	if (n % 2 == 1)
		printf("%d", f[1][1][(n - 1) / 2]);
	else
		printf("%d", std::max(f[1][1][(n - 1) / 2], f[1][1][(n/2)]));
	return 0;
}


```

