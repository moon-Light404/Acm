## 整数拼接

给定一个长度为 nn 的数组 A1,A2,⋅⋅⋅,AnA1,A2,···,An。

你可以从中选出两个数 AiAi 和 AjAj(ii 不等于 jj)，然后将 AiAi 和 AjAj 一前一后拼成一个新的整数。

例如 1212 和 345345 可以拼成 1234512345 或 3451234512。

注意交换 AiAi 和 AjAj 的顺序总是被视为 22 种拼法，即便是 Ai=AjAi=Aj 时。

请你计算有多少种拼法满足拼出的整数是 KK 的倍数。

#### 输入格式

第一行包含 22 个整数 nn 和 KK。

第二行包含 nn 个整数 A1,A2,⋅⋅⋅,AnA1,A2,···,An。

#### 输出格式

一个整数代表答案。

#### 数据范围

1≤n≤1051≤n≤105,
1≤K≤1051≤K≤105,
1≤Ai≤1091≤Ai≤109

#### 输入样例：

```
4 2
1 2 3 4
```

#### 输出样例：

```c++
6
```



```c++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
typedef long long ll;
int cnt[11][N]; // cnt[i][j]乘以10的i次方余上k = j的数的个数
int a[N];
int n, m;
int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)   
        scanf("%d",&a[i]);
    
    for(int i = 0; i < n;i++)
    {
        ll t = a[i]%m;
        for(int j = 0; j < 11;j++)
        {
            cnt[j][t] ++; // 10的j次方 余数为t
            t = t*10%m;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n;i++)
    {
        ll t = a[i]%m;
        int len = to_string(a[i]).size();
        ans += cnt[len][(m-t)%m];
        // 判断是不是重复使用了同一个数
        ll r = t;
        while(len--)    r = r * 10%m;
        if(r==(m-t)%m)  ans--;
    }
    cout << ans;
    return 0;
}
```



`(m-t)%m` 的原因是当`t=a[i]%m=0`时候，这时候 `m-t=m`但是不可能有除以 m 的余数还是m的数字，所以再 余上m就是0，符合条件；当`a[i]%m`不是0时，另一个加数除以k的余数为`m-t`。

最后一个==res-1==的原因是假如在序列中某个数只出现了一次例如 `1212`这个拼接后的数字，12只出现过一次，但是12*100 和12模上 k 后的余数加起来等于m，也会计算在内，所以要减去1。



