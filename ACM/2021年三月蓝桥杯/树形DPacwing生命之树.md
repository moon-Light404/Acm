在X森林里，上帝创建了生命之树。

==树形DP==



他给每棵树的每个节点（叶子也称为一个节点）上，都标了一个整数，代表这个点的和谐值。

上帝要在这棵树内选出一个非空节点集 SS，使得对于 SS 中的任意两个点 a,ba,b，都存在一个点列 {a,v1,v2,…,vk,b}{a,v1,v2,…,vk,b} 使得这个点列中的每个点都是 SS 里面的元素，且序列中相邻两个点间有一条边相连。

在这个前提下，上帝要使得 SS 中的点所对应的整数的和尽量大。

这个最大的和就是上帝给生命之树的评分。

经过 atm 的努力，他已经知道了上帝给每棵树上每个节点上的整数。

但是由于 atm 不擅长计算，他不知道怎样有效的求评分。

他需要你为他写一个程序来计算一棵树的分数。

#### 输入格式

第一行一个整数 nn 表示这棵树有 nn 个节点。

第二行 nn 个整数，依次表示每个节点的评分。

接下来 n−1n−1 行，每行 22 个整数 u,vu,v，表示存在一条 uu 到 vv 的边。

由于这是一棵树，所以是不存在环的。

树的节点编号从 11 到 nn。

#### 输出格式

输出一行一个数，表示上帝给这棵树的分数。

#### 数据范围

1≤n≤1051≤n≤105,
每个节点的评分的绝对值均不超过 106106。

#### 输入样例：

```
5
1 -2 -3 4 5
4 2
3 1
1 2
2 5
```

#### 输出样例：

```
8
```



题意：在一棵树中找到一个连通块使得其和最大	

<a href="https://imgtu.com/i/c3LKwd"><img src="https://z3.ax1x.com/2021/04/07/c3LKwd.png" alt="c3LKwd.png" border="0" /></a>

```c++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1000010, M = N * 2;
int h[N], e[N], ne[M], w[N], idx; // 注意w表示结点的评分，而不是边的权值
LL f[N]; // 状态数组

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u,int fa) // 记录父节点防止又回头往上搜,u 表示的是结点编号从 1 - n
{
    f[u] = w[u]; // 记录点的值
    for(int i = h[u];i != -1;i = ne[i]) // h[u]表示的是 u 为起点的边的编号，再用ne[i]找到上一个以 u 为起点的编号，直到找到所有
    // 在其之前加入的领边
    {
        int j = e[i]; // 记录的是终点
        if(j != fa)
        {
            dfs(j,u); // 此时的父节点是u
            f[u] += max(0ll,f[j]);
        }
    }
}
int main()
{
    int n; 
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= n;i++)   scanf("%d",&w[i]);
    
    // 边数 = 点数 - 1
    for(int i = 0;i < n - 1; i ++)
    {
        int a, b;
        scanf("%d%d",&a, &b);
        add(a,b), add(b,a);
    }
    dfs(1,-1); // 从上面的1结点开始向下搜
    LL res = f[1];
    for(int i = 2; i <= n; i++)
    {
        res = max(res,f[i]);
    }
    cout << res;
    return 0;
}
```

