## LCS最长公共子序列

最长公共子序列（longest common sequence）和最长公共子串（longest common substring）不是一回事儿。即一个给定的序列的==子序列==，就是将给定序列中==零个或多个元素去掉之后==得到的结果。什么是==子串==，给定串中任意个==连续==的字符组成的子序列称为该串的子串。



**动态规划**

设`Ax,Bx`表示 A  和 B的连续前 x 项构成的子序列，用`LCS(x,y)`表示它们的最长公共子序列长度，那原问题就是求`LCS(m,n)`。	

用$L(x,y)$表示Ax和Bx的一个最长公共子序列。

- 求`LCS(x,y)`的方法

(1) `Ax = By`那么A和B的最长公共子序列一定是这个元素

有 `LCS(x,y) = LCs(x-1,y-1)` + 1

(2)$Ax\neq By$ 

如果 $t\neq Ax$,则有$LCS(x,y)=LCS(x-1,y)$,因为与Ax 无关了

如果$t\neq By$，则$LCS(x,y)=LCS(x,y-1)$

---

$LCS(x,y)=LCS(x-1,y-1)+1  (Ax=By)$

$max(LCS(x-1,y),LCS(x,y-1)) (Ax\neq By)$

$0 如果 x=0 或者 y = 0$

---

```c++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int f[N][N]; // f[i][j] 表示s1前i个字符和 s2前j个字符公共子序列的最大值
char s1[N], s2[N];
int main()
{
    int m,n;
    cin >> m >> n; // 字符串的长度
    cin >> s1+1 >> s2+1;
   // f[1][0] = f[0][1] = 0;
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1; j <= n;j++)
        {
            if(s1[i] == s2[j])  f[i][j] = f[i-1][j-1]+1;
            else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    cout << f[m][n];
    return 0;
}
```

