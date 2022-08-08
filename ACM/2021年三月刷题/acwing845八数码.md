## 八数码

在一个 3×3 的网格中，1∼8 这 8 个数字和一个 `x` 恰好不重不漏地分布在这 3×3 的网格中。

例如：

```
1 2 3
x 4 6
7 5 8
```

在游戏过程中，可以把 `x` 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

```
1 2 3
4 5 6
7 8 x
```

例如，示例中图形就可以通过让 `x` 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

```
1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
```

现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

#### 输入格式

输入占一行，将 3×3 的初始网格描绘出来。

例如，如果初始网格如下所示：

```
1 2 3 
x 4 6 
7 5 8 
```

则输入为：`1 2 3 x 4 6 7 5 8`

#### 输出格式

输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 −1−1。

#### 输入样例：

```
2  3  4  1  5  x  7  6  8
```

#### 输出样例

```c++
19
```

分析:用`bfs`把当前的下一步找出来，用一个结构体存储当前的状态和步数，循环遍历四个方向(判断是否能走且合法)

用==string直接表示状态==

```c++
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
string start;
string dest = "12345678x";
struct state{
    string s;
    int step;
}tmp;
set<string> sset; // 存储每次的字符串状态
int bfs(string s)
{
    state t1, t2;
    queue<state> q;
    tmp.step = 0;
    tmp.s = s;
    q.push(tmp);
    
    while(q.size())
    {
        t1 = q.front();
        q.pop();
        if(t1.s == dest)
        {
            cout << t1.step;
            return 0;
        }
        int pos = t1.s.find('x'); // 找到x的位置
        // 向左走
        if(pos-1 >= 0 && pos-1!=2 && pos-1!=5)
        {
            string str = t1.s;
            swap(str[pos],str[pos-1]);
            if(!sset.count(str)) // 如果这个字符串(状态)没有出现过
            {
                sset.insert(str);
                t2.s = str;
                t2.step = t1.step + 1;
                q.push(t2);
            }
        }
        // 向右走
        if(pos+1 <= 8 && pos+1!=3 && pos+1!=6)
        {
            string str = t1.s;
            swap(str[pos],str[pos+1]);
            if(!sset.count(str)) // 如果这个字符串(状态)没有出现过
            {
                sset.insert(str);
                t2.s = str;
                t2.step = t1.step + 1;
                q.push(t2);
            }
        }
        // 向上走
        if(pos-3 >= 0)
        {
            string str = t1.s;
            swap(str[pos],str[pos-3]);
            if(!sset.count(str)) // 如果这个字符串(状态)没有出现过
            {
                sset.insert(str);
                t2.s = str;
                t2.step = t1.step + 1;
                q.push(t2);
            }
        }
        // 向下走
        if(pos+3<=8)
        {
            string str = t1.s;
            swap(str[pos],str[pos+3]);
            if(!sset.count(str)) // 如果这个字符串(状态)没有出现过
            {
                sset.insert(str);
                t2.s = str;
                t2.step = t1.step + 1;
                q.push(t2);
            }
        }
        
    }
    return -1;
}
int main()
{
    char a; // 当作字符
    for(int i = 0;i < 9;i++)
    {
        cin >> a;
        start = start + a; // 转化为字符串
    }
    
    int k = bfs(start);
    if(k==-1)
    {
        cout << k;
    }
    return 0;
}
```



用`unordered_map<string,int>`记录当前字符串状态已经是第几步,并且把一维数组变为二维数组的下标

```c++
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
string start,en= "12345678x";

unordered_map<string,int> d; // 不会排序的map
int dx[4] = {0,-1,0,1}, dy[4]={1,0,-1,0};

int bfs(string start)
{
    queue<string> q;
    d[start] = 0;
    q.push(start);
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int distance = d[t]; // 表示所走的步数
        if(t == en)
        {
            cout << distance << endl;
            return 0;
        }
        int k = t.find('x');
        // 把一维下标转换为二维
        int x = k/3, y = k%3;
        // s
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // 越界判断
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3)  continue;
            
            swap(t[k],t[nx*3+ny]); // 修改字符串
            if(!d.count(t)) // 这个状态没出现过
            {
                d[t] = distance + 1; // 步数加1 
                q.push(t);
            }
            // 恢复现场
            swap(t[k],t[nx*3+ny]);
        }
    }
    return -1;
}
int main()
{
    char c;
    for(int i = 0;i < 9;i++)
    {
        cin >> c;
        start += c;
    }
    int g = bfs(start);
    if(g == -1)
    {
        cout << g;
    }
    
    return 0;
}
```

