### L2-008 最长对称子串 （25 分)

<mark>动态规划</mark>

对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，于是你应该输出11。

输入格式：
输入在一行中给出长度不超过1000的非空字符串。

输出格式：
在一行中输出最长对称子串的长度。

输入样例：
`Is PAT&TAP symmetric?`

输出样例：
11

原文链接：https://blog.csdn.net/weixin_43264529/article/details/88812551

==暴力DP==

设`A[l][r]`为字符串 `str[l:r]`的最长对称子串

对于第 l 位与第 r 位之间的字符串`str[l:r]`，如果其是对称子串的话，则满足`str[l] == str[r]`，且`str[l+1: r-1]`为对称子串

==初始条件==

`A[i][j] == 1`   - > `i == j`

```c++
#include<isotream>
using namespace std;
vector<vector<int>> A(n,vector<int>(n,0));
int main()
{
    string str = "";
    getline(cin,str);
    int n = str.size();
    for(int i = 0;i < n;i++)
        A[i][i] = 1;
   	int Max = 1;
    for(int len = 1;len < n;len++) // 枚举子串长度
    {
        for(int l = 0;l + len< n;l++)
        {
            int r = l + len;
            if(str[l] == str[r])
            {
                if(A[l+1][r-1] == r - l -1)// 如果该区间的最长对称子串等于总长度
                {
                    A[l][r] = A[l+1][r-1] + 2;
                    if(A[l][r] > Max)
                        Max = A[l][r];
                }
            }
        }
    }    
}
```

