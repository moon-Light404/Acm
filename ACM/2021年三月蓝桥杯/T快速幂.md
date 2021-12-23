https://zhuanlan.zhihu.com/p/95902286知乎链接

包含调试信息

```c++
#include <iostream>
using namespace std;
int cnt = 0;

int qpow(int a, int n) {
	cnt++;
	cout << "times of cnt:" << cnt << endl;
	if (n == 0) // 递归终点{
		return 1;
	}

	else if (n % 2 == 1) {
		int k = qpow(a, n - 1);
		int l = k * a;
		return l;
	}

	else {
		int temp = qpow(a, n / 2);
		return temp * temp;
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	int res = qpow(m, n);
	cout << res << endl;
	return 0;
}
```



### 非递归快速幂

```c++
int qpow(int a,int n) // 计算a^n次方
{
    int ans = 1;
    while(n)
    {
        if(n&1) // 当前n的末位为1
        {
            ans *= a;
        }
        a *= a;
        n >>= 1; // n向右移一位
    }
    return ans;
}
```

