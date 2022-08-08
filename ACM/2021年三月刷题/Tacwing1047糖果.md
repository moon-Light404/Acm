从给出的数中选出来加起来的和是 K 的倍数，在满足倍数的条件下取得最大。

![image-20210326211938318](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210326211938.png)



`f[i-1][j-w%k]` 防止第二维为负数变为`f[i-1][j+k-w%k]`

`a%b` ->`(a+b)%b`



## ==求余的一些性质==

<img src ="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210327101959.png" style="zoom:50%;" />
<img src ="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210327102006.png" style="zoom:50%;" />

```c++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;
int f[N][N]; // f[i][j]表示从前i个物品中选，总和除以k的余数是j,求得是最大值
int w[N]; // 糖果数
// f[i][j] = f[i - 1][j] , f[i - 1][(j-w + n)%n] + w
// 选与不选之分，选的话那么前i-1个物品 + 第 i 个物品w 有余数的性质 余数为(j-w+n)%n
int main()
{
    int m, n;
    cin >> m >> n; // n 是余数
    memset(f,-0x3f,sizeof f);
    f[0][0] = 0; // f数组表示的是值
    // f[0][i]都是无意义的,如果初始化为0的话结果会不正确
    for(int i = 1; i <= m;i++)   cin >> w[i];
    
    for(int i = 1;i <= m;i++)
        for(int j = 0; j < n;j++)
        {
            f[i][j] = max(f[i-1][j], f[i-1][(j-w[i]%n+n)%n] + w[i]);
        }
    cout << f[m][0];
    return 0;
}
```

