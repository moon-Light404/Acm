## KMP

KMP-字符串匹配算法，`pat`模式串，长度为M； `txt`文本串，长度为N。KMP算法是在`txt`中查找子串`pat`,如果存在，返回起始索引，否则返回-1 。

https://zhuanlan.zhihu.com/p/83334559这个知乎专栏讲得很好

### 根据上面的理解

1、如果是暴力枚举的话，就是在 `txt`枚举每一个字符，当这个字符与`pat`开头相同时，就继续枚举下去，直到不匹配，又从`txt`下一个字符开始匹配。这样太费时间，如：

![img](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112042112184.gif)

当字符串中有很多重复的字符时，就会进行很多不必要的操作，比如`pat`中根本没有 `c` 这个字符，应该直接从`txtc 后面的 a` 开始匹配，但是暴力枚举只是单一的遍历`txt`的每一个字符。

2、我们想记录`pat`匹配的状态，记录当前`pat`匹配到哪一步了，这样就可以直接避免`txt`又回到前面重新遍历一次。

3、![image-20211204211751578](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112042117827.png)

假设`pat = ABABC`，初始状态为0，箭头上的字母表示在当前状态下`匹配到该字母的下一状态`。这样就实现了一直遍历`txt`，然后判断`pat`当前的状态就行了。<mark>也就说`pat`的状态数组只与匹配串`pat`有关</mark> 。遇到不属于`pat` 的字符状态回到起始 0。

4、如何构建`pat`的状态数组

状态转移：	**当前的匹配状态**  和   **遇到的字符**





### KMP实现算法

设模式串为 `p`，匹配串为`s`。

<mark>思考</mark>

`next`数组：如next[j]表示**`p[1~j]`串中前缀和后缀相同的最大长度**(部分匹配值)。

设p串： a b c a b

| p      | a    | b    | c    | a    | b    |
| ------ | ---- | ---- | ---- | ---- | ---- |
| 下标   | 1    | 2    | 3    | 4    | 5    |
| next[] | 0    | 0    | 0    | 1    | 2    |

next[5]：前缀 ab、 后缀 ab共同长度为2.

核心思想：在每次失配时，不是把p串往后移一位，而是把p串往后移动至下一次可以和前面部分匹配的位置，这样就可以跳过大多数的失配步骤。而每次p串移动的步数就是通过查找next[ ]数组确定的。

比如要在`s = abababc`寻找模式串`p = ababc`

- 前三个abc已经找到相同，但是第 5个 `a != c`-`s[5] != p[4+1]`
- 这时候kmp 可以根据`next[]数组`，因为`next[4] = 2 `，说明前4个中组成的串`前缀和后缀公共的部分`有 2 个(ab ab)，`j = next[4] = 2`，直接从第 `2 + 1`个开始比较，前两个已经匹配过了，此时`s[5] = a`、`p[2+1] = a`，匹配到了`aba`，加上后面的`bc`，`j`到达了`m`，匹配完成。

<mark>匹配代码</mark>

匹配串`s`长度为n，模式串`p`为m

```c++
// 数据下标从1开始
for(int i = 1; j = 0; i <= n;i++) {
    while(j && s[i] != p[j+1])	j = ne[j];
    if(s[i] == p[j+1])	j++;
    if(j == m) {
        // 输出以0开始的匹配子串的首字母
        cout << i - m; // 若从1开始则 +1
        j = ne[j]; // 匹配多次就用这个
    }
}
```



<mark>模式串next数组</mark>

构建next数组和匹配代码几乎一模一样，就是在模式串`p`找相同的前缀。


```c++
for(int i = 2, j = 0; i <= n;i++) {
    while(j && p[i] != p[j+1])	j = ne[j];
    if(p[i] == p[j+1])	j++; // 相同，之前的子串相同前缀后缀为j，相同统计直接+1
    ne[i] = j; // 1-i中的相同前后缀长度为j
}
```

![image-20211205101910413](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112051019505.png)

如上图。`s[a,b] = p[1,j]`，但是当`s[i]!=p[j+1]`时，可以发现在匹配串p中`1串等于3串`，`s中的2串和p中的3串相等`也就是说我们可以直接从`1串开始匹配`，即`j = next[j](前缀1和后缀3相同同的长度)`,然后从比较`p[j+1] 和p[i]`开始。这样就`避免了s串的回头` 。

### <a href = "https://www.acwing.com/activity/content/problem/content/869/"> ACwingKMP字符串</a>

```c++
#include<iostream>
using namespace std;
const int N = 100010, M = 1000010;
int ne[N];
char p[N], s[M]; // p是模式串、s是匹配串
int main() {
    int n,m;
    cin >> n >> p+1 >> m >> s+1;
    // 求next数组,模式串与自己匹配
    for(int i = 2, j = 0;i <= n;i++) {
        while(j && p[i] != p[j+1])  j = ne[j]; // 相当与从前缀(和后缀相同的位置)j
        if(p[i] == p[j+1])   j++;
        ne[i] = j;
    }
    
    // 利用next数组匹配需要匹配的串
    for(int i = 1,j = 0; i <= m;i++) {
        while(j && s[i] != p[j+1])  j = ne[j];
        if(s[i] == p[j+1])  j++; // 相同的字符数量
        if(j == n) {
            cout << i - n << " "; // 本来是 i -n + 1,但我们初始时下标为1，本题是0
            j = ne[j]; // 匹配下一个,从j位置开始，当前j相当于从ne[j]的位置再次匹配
        }
    }
    
    return 0;
}
```





