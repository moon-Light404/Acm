你有一张某海域 N×NN×N 像素的照片，”.”表示海洋、”#”表示陆地，如下所示：

```
.......
.##....
.##....
....##.
..####.
...###.
.......
```

其中”上下左右”四个方向上连在一起的一片陆地组成一座岛屿，例如上图就有 2座岛屿。

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。

具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

例如上图中的海域未来会变成如下样子：

```
.......
.......
.......
.......
....#..
.......
.......
```

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

#### 输入格式

第一行包含一个整数N。

以下 NN 行 NN 列，包含一个由字符”#”和”.”构成的 N×NN×N 字符矩阵，代表一张海域照片，”#”表示陆地，”.”表示海洋。

照片保证第 11 行、第 11 列、第 NN 行、第 NN 列的像素都是海洋。

#### 输出格式

一个整数表示答案。

#### 数据范围

1≤N≤10001≤N≤1000

#### 输入样例1：

```
7
.......
.##....
.##....
....##.
..####.
...###.
.......
```

#### 输出样例1：

```
1
```

#### 输入样例2：

```
9
.........
.##.##...
.#####...
.##.##...
.........
.##.#....
.#.###...
.#..#....
.........
```

#### 输出样例2：

```c++
1
```



- 第一种用==bfs==解题，遍历出当前与某个陆地块相邻的的块，并全部标记为true,在循环中记录所有块的数目和与海洋相邻的块数目，再判断两者是否相等，相等则这个陆地将要被淹没

```c++
#include<iostream>
#include<queue>
using namespace std;
const int N = 1010;
char g[N][N];
bool st[N][N]; // 判断是否走过 数组
int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
int n;
typedef pair<int,int> PII;
queue<PII> q;
void bfs(int i, int j, int& total, int& sea)
{
   q.push({i,j});
   st[i][j] = true;
   while(q.size())
   {
       auto t = q.front();
       q.pop();
       total++;
       bool is_sea = false;
       for(int i = 0 ; i < 4;i++)
       {
           int x = t.first + dx[i], y = t.second + dy[i];
           if( x < 0 || x >= n || y < 0 || y >= n) continue;
           if(st[x][y]) continue;
           if(g[x][y] == '.')
           {
               // 4个方向里面是否出现了'.'h
               is_sea = true; // 记录沿海的陆地元素
               continue;
           }
           
           // g[x][y] = '#'
           q.push({x,y});
           st[x][y] = true;
           
       }
       
       if(is_sea) sea++;
   }
    
}
int main()
{
    int cnt = 0;
    cin >> n;
    for(int i = 0;i < n;i++) scanf("%s",g[i]);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            if(g[i][j] == '#' && !st[i][j])
            {
                
                int total = 0, sea = 0;
                bfs(i,j,total,sea);
                if(total == sea) // 陆地都靠近海洋
                cnt++;
            }
        }
    cout << cnt;
    return 0;
}
```



- 第二种，==dfs==解题，给每块陆地编号，编号为数组的下标找出每个陆地内部是否有四个方向都是陆地的块'#'，找到了就给这个数组下标对应的值加1

```c++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1100;
char g[N][N];
int n;
int ans[N*N];
bool vis[N][N];
void dfs(int x, int y, int len)
{
    if(x < 1 || x > n || y < 1 || y > n)    return;
    
    if(g[x][y] == '.')  return;
    if(vis[x][y])   return;
    
    vis[x][y] = true;
    // ans数组记录有多少个块四周都是陆地,不会被淹没
    if(g[x][y+1] == '#' && g[x][y-1] == '#' && g[x+1][y]=='#'&& g[x-1][y]=='#')  ans[len]++;
    dfs(x+1,y,len);
    dfs(x-1,y,len);
    dfs(x,y+1,len);
    dfs(x,y-1,len);
}
int main()
{
    int len = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> g[i] + 1;
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
        {
            if(g[i][j] == '#' && !vis[i][j])
            {
                
                dfs(i, j, len);
                len++; // len 记录陆地数量
            }
        }
    int res = 0;
    for(int i = 0;i < len;i++)
    {
        if(ans[i] == 0)   res++;
    }
    cout << res;
    return 0;
}
```

