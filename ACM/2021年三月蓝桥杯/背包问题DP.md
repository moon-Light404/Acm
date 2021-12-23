# 背包问题汇总

### 01背包问题(easy)

有 N 件物品和一个容量是 V 的背包。==每件物品只能使用一次==。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式

第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i件物品的体积和价值。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤10000
0<vi, wi ≤10000

输入样例

```
4 5
1 2
2 4
3 4
4 5
```

输出样例：

```
8
```

 用集合和状态DP分析:

<a href="https://imgtu.com/i/c3qXWV"><img src="https://z3.ax1x.com/2021/04/07/c3qXWV.md.png" alt="c3qXWV.png" border="0" /></a>



```c++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int v[N], w[N]; // 体积和价值
int f[N][N]; // f[i][j], j体积下前i个物品的最大价值

int main() {
	int n, m;
	cin >> n >> m; // n件物品和背包容量m

	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) { // 此物品有选与不选两种情况
			if (j < v[i]) { // 如果背包容量比这件物品的体积还小
				f[i][j] = f[i - 1][j];
			} else
				f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]); 
            // 第2种写法
            // f[i][j] = f[i - 1][j];
            //if(j > v[i])	f[i][j] = max(f[i-1][j-v[i]] + w[i], f[i][j]);
		}
		
	// f[i][j] 表示 体积为j下前i个物品的价值最大值
	cout << f[n][m] << endl;

	return 0;
}
// f[i-1][j] 可以看作是上一次循环计算的结果，因为只用到了一次，可以直接变为一维数组优化空间

 // 优化版本
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];
int main()
{
    int n, m;
    cin >> n >>m;
    for(int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
        
    for(int i = 1;i <= n;i++)
        for(int j = m; j >= v[i];j--) // 逆序保证f[j-v[i]]是上一层的
        {
                f[j] = max(f[j - v[i]] + w[i],f[j]);
        }
    // m m-1 m-2 .... v[i] 从大到小,如果不逆序，那么f[j-v[i]]是在第i层更新过的
    cout << f[m]<< endl;
    return 0;
}
```

==优化分析==
看上面的输出数据, 我们会发现其实二维表里有很多重复的. 这是因为, 从递归式的特点来看, 我们只是基于第i-1层对第i层做了更新, 而第i-1层该是什么样还是什么样.

换言之, 我们只需要知道最后一层的情况, 而不需要存储之前的结果.

看上面的表格, 其实我们最后输出的是最右下角的值.

我们这个时候可以得到一个递归式

 f[v]=max{f[v], f[v-vi]+wi}

理解起来, 是和上面讲的一样的.
但是, 在具体的实现层面上, 有一个很反直觉的点:

不同于二维dp的双重循环, 空间优化版本的内层循环必须是逆序的.

如果这一点理解了, 整个程序的实现就非常容易了.

==为什么优化要逆序==

因为我们采用的是一维数组，每次都是更新此数组的每个数，我们要取得是最后一个数，因为 `f[j]` 要看数组前面的下标 `j-v[i]`，假设我们体积 j 从0开始遍历，设此时遍历到10，数组前面的数都已经在这一层更新过了，那就会出现错误了，应该让后面的下标最先遍历，后面下标遍历了一遍就用不到了。

---



### 完全背包问题

有 N 种物品和一个容量是 V 的背包，每种物品都有==无限件==可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式

第一行两个整数，N，VN，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行两个整数 vi,wivi,wi，用空格隔开，分别表示第 i种物品的体积和价值。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤10000<N,V≤1000
0<vi,wi≤10000<vi,wi≤1000

输入样例

```
4 5
1 2
2 4
3 4
4 5
```

输出样例：

```
10
```

<a href="https://imgtu.com/i/c3q7Zj"><img src="https://z3.ax1x.com/2021/04/07/c3q7Zj.png" alt="c3q7Zj.png" border="0" /></a>



简单写法:

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N][N]; // f[i][j]表示从前i个物品中选且 V <= j 最大价值，每件物品可重复选取
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = 0; j <= m;j++)
        {
            f[i][j] = f[i - 1][j]; // 第i件物品一件也不取
            if(j >= v[i])
            {
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
           
        }
    cout << f[n][m];
    return 0;
}
```



<a href = "https://www.acwing.com/video/945/">代码优化</a>变为==一维数组==

优化写法

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N]; // f[i][j]表示从前i个物品中选且 V <= j 最大价值，每件物品可重复选取
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = v[i]; j <= m;j++) // 不需处理逆序
        {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m];
    return 0;
}
```



---

### 多重背包问题(数量固定)

有 N 种物品和一个容量是 V 的背包。

第 i 种物品==最多有 s 件==，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式

第一行两个整数，N，VN，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 NN 行，每行三个整数 vi,wi,sivi,wi,si，用空格隔开，分别表示第 ii 种物品的体积、价值和数量。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤1000<N,V≤100
0<vi,wi,si≤1000<vi,wi,si≤100

输入样例

```c++
4 5
1 2 3
2 4 1
3 4 3
4 5 2
```

输出样例：

```c++
10
```

本题是01背包问题的一个演化，01背包问题中一个背包只有选与不选两种情况，在多重背包问题中每个背包(有s个背包)`s+1`种选取方法,只要再加1个循环循环取得数量即可。

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N]; // f[i]表示体积为i的背包可以获得的最大价值 
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i] >> s[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = m; j >= v[i];j--) // 从m开始
        {
            for(int k = 1; k <= s[i] &&  k * v[i] <= j;k++)
                f[j] = max(f[j], f[j - k * v[i]] + k *  w[i]);
        }
    cout << f[m];
    return 0;
}

```
#### 标准朴素写法
```c++
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 110;

int v[N], w[N], s[N]; 
 // f[i][j] 表示前i件物品总重量(且总重量 <= j)的最大价格
int f[N][N]; 
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            for(int k = 0; k <= s[i]; k ++){ // 遍历物品的数量
                if(j >=  k * v[i]){
                    f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                    // max 里面也包含了f[i - 1][j]，所以前面可以省
                }
            }
        }
    }

    cout << f[n][m] << endl;

    return 0;
}


```



### <a href="https://www.acwing.com/problem/content/5/">多重背包二进制优化</a>

由于物品数量太大，而且遍历物品数量时有很多不必要的循环，用二进制进行优化

比如 数量200 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 73   ,将二进制数的进行打包成一个新的物品拥有新的体积和价值

<u>这样做得原因是我们不需要一遍一遍的从1到200去遍历数量，二进制数可以凑出1 ~200的任何数量。</u>将每个物品拆分成新的物品。

<mark>转化为了01背包问题，拆分的物品只能用一次</mark>

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 12010, M = 2010; // N * log(s) 1000 * 12
int v[N], w[N];
int f[M];
int n,m;

int main() {
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n;i++) {
        int a, b, s;
        cin >> a >> b >> s; // 体积 价值 数量
        int k = 1;
        while(k <= s) {
            cnt ++;
            v[cnt] = a * k; 
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0) {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
        
        
    }
    // 转换为01背包问题
    n = cnt;
    for(int i = 1; i <= n;i ++)
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}
```

