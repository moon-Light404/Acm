## 斐波那契的矩阵运算表示

<img src = 'https://i.bmp.ovh/imgs/2021/04/f7f653a61faeb5a5.png' />

<img src = 'https://i.bmp.ovh/imgs/2021/04/e2bcf515540ac4b1.png' />

- ==矩阵乘法==

```c++
const int N = 3;
// 一维乘以三维 --> 结果为一维
void mul(int c[],int a[],int b[][N]) // a是一维，b是二维
{
    int temp[N] = {0};
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++) // 枚举a的一行数
            temp[i] = temp[i] + a[j] * b[j][i]; 
            // 第n个元素 == a的第一行 * b的第n列
    memcpy(c,temp,sizeof temp);
}

// 多维乘以多维矩阵
void mul(int c[][N],int a[][N],int b[][N])
{
    int temp[N][N] = {0};
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            for(int k = 0;k < N;k++) // 新增一层循环
            {
                temp[i][j] = temp[i][j]+a[i][k]*b[k][j];
                // temp[i][j]== a的第i行 * b的第j列
            }
    memcpy(c,temp,sizeof temp);	
}

```

### 题目斐波那契前n项和

 斐波那契前 n 项和

大家都知道 Fibonacci 数列吧，f1=1,f2=1,f3=2,f4=3,…,fn=fn−1+fn−2f1=1,f2=1,f3=2,f4=3,…,fn=fn−1+fn−2。

现在问题很简单，输入 n和 m，求 fn 的前 n 项和 Snmodm。

#### 输入格式

共一行，包含两个整数 n 和 m。

#### 输出格式

输出前 n 项和 Snmodm 的值。

#### 数据范围

1≤n≤20000000001≤n≤2000000000,
1≤m≤10000000101≤m≤1000000010

#### 输入样例：

```
5 1000
```

#### 输出样例：

```c++
12
```

```c++
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
int n, m;
const int N = 3;
// 一维乘以三维 --> 结果为一维
void mul(int c[],int a[],int b[][N]) // a是一维，b是二维
{
    int temp[N] = {0};
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++) // 枚举a的一行数
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m; 
            // 第n个元素 == a的第一行 * b的第n列
    memcpy(c,temp,sizeof temp);
}

// 多维乘以多维矩阵
void mul(int c[][N],int a[][N],int b[][N])
{
    int temp[N][N] = {0};
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            for(int k = 0;k < N;k++) // 新增一层循环
            {
                temp[i][j] = (temp[i][j]+(LL)a[i][k]*b[k][j])%m;
                // temp[i][j]== a的第i行 * b的第j列
            }
    memcpy(c,temp,sizeof temp);
}

int main()
{
    int f1[N] = {1,1,1};
    // 连乘矩阵
    int A[N][N]={
        {0,1,0},
        {1,1,1},
        {0,0,1},
    };
    cin >> n >>m;
    n--;
    // 快速幂
    while(n)
    {
        if(n&1) mul(f1,f1,A);
        mul(A,A,A); // A = A * A,每右移一位乘以一个A
        n >>= 1;
    }
    cout << f1[2] << endl;
    return 0;
}
```

