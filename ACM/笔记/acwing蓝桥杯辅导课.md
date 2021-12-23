# acwing蓝桥杯辅导课

## 时间复杂度

<img src="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210322120212.png" alt="img" style="zoom:150%;" />



## 整数二分

==第一类==

![image-20210301194835639](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210301194835.png)

`M = (L+R+1)/2`是为了防止 L 的值一直不变而导致死循

![image-20210301195405293](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210301195405.png)

![image-20210301195246784](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210301195246.png)

![image-20210301195322533](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210301195322.png)

### 整数二分步骤

- 找一个区间[L,R],使得答案一定在该区间中
- 找一个判断条件，使得该判断条件具有二段性，并且答案一定是该二段性的分界线
- 分析终点M在该判断条件下是否成立，如果成立，考虑答案在哪个区间；如果不成立，考虑答案在哪个区间
- 如果更新方式写的是==R = mid,则不用做任何处理==；如果写的是L = mid,则需要在计算mid时加上1再除以2

### 二分查找

```c++
int binarySearch(int arr[],int key){
    int low = 0;
    int high = sizeof(arr)/sizeof(int) - 1;
    int mid = 0;
    
    while(low <= high){
        mid = (low+high)/2; // 取中间位置,逐步缩小区间范围
        
        if(key < arr[mid])
            high = mid - 1;
        else if (key > arr[mid])
            low = mid + 1;
        else break;
    }
    return mid;
}
```

 #### ==acwing789==

给定一个按照升序排列的长度为n的整数数组，以及 q 个查询。

对于每个查询，返回一个元素k的起始位置和终止位置（位置从0开始计数）。

如果数组中不存在该元素，则返回“-1 -1”。

输入格式

第一行包含整数n和q，表示数组长度和询问个数。

第二行包含n个整数（均在1~10000范围内），表示完整数组。

接下来q行，每行包含一个整数k，表示一个询问元素。

输出格式

共q行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回“-1 -1”。

数据范围

1≤n≤1000001≤n≤100000
1≤q≤100001≤q≤10000
1≤k≤100001≤k≤10000

输入样例：

```
6 3
1 2 2 3 3 4
3
4
5
```

输出样例：

```
3 4
5 5
-1 -1
```



==解答==

<img src="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210301212719.png" alt="img" style="zoom: 25%;" />

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>

using namespace std;

const int N  = 100010;
int g[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &g[i]);

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x); // 输入要查找的数

		int l = 0, r = n - 1; // 左右端点
		// 二分求左端点找 >=x 的第一个位置
		while (l < r) {
			int mid = l + r >> 1; // 除以2
			if (g[mid] >= x)
				r = mid; // 注意r一直等于mid
			else
				l = mid + 1;

		}

		if (g[r] == x) {
			cout << r << ' ';
			r = n - 1; // l可以不变，因为l在左端点
			// 二分找右端点 <= x 的第一个位置
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (g[mid] <= x)
					l = mid; // 这时是l一直等于mid

				else
					r = mid - 1;
			}
			cout << l<< endl;
		} else
			cout << "-1 -1" << endl;

	}
	return 0;
}
```



### 实数二分

这个较为简单,不用考虑向上或向下取整等条件

### acwing790

给定一个浮点数n，求它的三次方根。

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    double k,mid;
    cin >> k;
    
    double l = -10000, r = 10000;
    
    while(r-l > 1e-8){
        mid = (r+l)/2;
        if(mid * mid * mid > k) r = mid; // mid取大了，向左边取数mid
        else l = mid;
    }
    printf("%lf\n",mid); // lf默认6位
    return 0;
}
```

把算法问题转化为二分的要求就是找到 ==单调性== 的一个关系，然后要找的的中间变量可以把其分成二段性的特点，==在这个变量的左边一定满足什么条件；右边满足另外一条件==



## 前缀和





#### ==acwing795 前缀和==

输入一个长度为 nn 的整数序列。

接下来再输入 mm 个询问，每个询问输入一对 l,rl,r。

对于每个询问，输出原序列中从第 ll 个数到第 rr 个数的和。

输入格式

第一行包含两个整数 nn 和 mm。

第二行包含 nn 个整数，表示整数数列。

接下来 mm 行，每行包含两个整数 ll 和 rr，表示一个询问的区间范围。

输出格式

共m行，每行输出一个询问的结果。

数据范围

1≤l≤r≤n1≤l≤r≤n,
1≤n,m≤1000001≤n,m≤100000,
−1000≤数列中元素的值≤1000

解析：这题是让我们从一个矩阵中找到一个子矩阵并求和，因为直接循环遍历太耗费时间，因此可以考虑二维前缀和

```c++
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;

int n,m,q;
int a[N][N],s[N][N];

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i <= n;i++){ // 坐标从1,1 开始不为0
        for(int j = 1;j<=m;j++){   
        scanf("%d",&a[i][j]);
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]; // 边读入数据边计算前缀和，时间复杂度就减少了很多
            // 也可以把两个数组合并为一个数组节约空间,即
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]
        }
    }
    
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]); // 使用之前已经计算好的前缀和数组计算直接输入结果
    }
    return 0;
}
```





#### 利用前缀和矩阵计算某个子矩阵的和(二维)



## DP动态规划

### 背包问题



### 完全背包问题

![img](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210316155923.png)



### ==acwing1205 买不到的数目==

`裴蜀定理：如果 p , q最大公约数为d ， 一定存在两个整数a ， b 使得 aq + bq = d.`

`如果 a,ba,b 均是正整数且互质，那么由 ax+by,x≥0,y≥0ax+by,x≥0,y≥0 不能凑出的最大数是 ab−a−b`

<b>acwing525小凯的疑惑(类似题目)</b>        <a href = https://www.acwing.com/solution/content/3165/>==y总题解==</a>

### ==acwing1211 蚂蚁感冒==

<a href = https://www.acwing.com/problem/content/1213/>原题目链接</a>

<b>解析</b>

可以把两只蚂蚁相撞等价于<b>穿过</b>，因为两只蚂蚁相撞之后状态是一样的，最后所有蚂蚁一定会全部离开木棍。



<i>right == 右边向左走； left == 左边向右走</i>

