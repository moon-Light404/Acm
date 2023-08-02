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



> 动态规划解法

```c++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1010;
bool dp[N][N]; // dp[i][j]表示的是(i,j)字符串是否是回文串
string s;
int main() {
    getline(cin, s);
    int n = s.length();
    int maxLen = 1;
    for(int i = 0; i < n;i++)   dp[i][i] = true; // 单个字符也是回文串
    for(int L = 2; L <= n; L++) { // 遍历长度
        for(int i = 0 ;i < n;i++) { // 遍历起点
            int j = i + L - 1; // 终点
            if(j >= n)  break;
            if(s[i] != s[j]) dp[i][j] = false;
            else {
                if(j - i <= 2)  dp[i][j] = true;
                else    dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j] && j - i + 1 > maxLen)  maxLen = j - i + 1;
        }
    }
    cout <<maxLen << endl;
    return 0;
}
```

