

 RSA是一种经典的加密算法。它的基本加密过程如下。

  首先生成两个大质数p,q, 令n = p*q,设d与(p-1)*(q-1)互质，则可以找到e,使得d*e除以(p-1)*(q-1)的余数为1

  n,d,e组成了私钥，n,d构成了公钥。

  当使用公钥加密一个整数X时(X<=n-1)，计算$C = X^d mod n$，则C是加密后的密文。

  当收到密文C时，可以使用私钥解开，计算公式为：$X = C^e mod n$。

  例如：当p = 5, q = 11, n = 55, e = 27。

  若加密数字24,得$24^3$ % 55 = 19。

  解密数字19，得$19^27$ % 55 = 24。

  现在你知道公钥中n = 1001733993063167141,d = 212353,同时，你截获了别人发送的密文C = 20190324,请问，原文是多少？

分析代码：

```c++
// 使用暴力枚举出 n的两个大质数
void BF(ll x) {
	cout << x << " =";
	for (ll i = 1e8 + 1; i < x; i += 2) {
		if (x % i == 0) {
			cout << i << " * ", x /= i;
		}
	}
	cout << x;
}
// 分解得 n =891234941 * 1123984201 = p * q
// 再计算 (p-1)*(q-1)

// 扩展欧几里得求逆元,即求出解密密钥e = 823816093931522017
void extgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1; y = 0;
        return;
    }
    extgcd(a, b, x, y);
    ll t = y;
    y = x - a / b * y;
    x = t;
    return;
}

// 快速幂：因为快速幂计算过程中 ans * a 可能会爆long long，我们将其转化为模加运算
// 快速乘
// 11得二进制数为1011, a * 11 = a * 2(0) + a * 2(1) + a * 2(3) 
ll fast_pro(ll a, ll b, ll mod) {
    ll ans = 0;
    while(b) {
        if(b & 1) {
            ans = (ans + a) % mod;
            // (a + b) % p = (a % p + b % p) % p
        }
        a = (a + a) % mod; // a 2a 4a 8a 16a 32a.....
        b >>= 1;
    }
    return ans;
    // (ans * a) % p = (ans + ans + ans +...)%p
}
// 快速幂，求 a ^b mod (mod)
// 答案:579706994112328949
ll get_pow(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = fast_pro(ans, a, mod);
        }
        a = fast_pro(a, a, mod);
        b >>= 1;
    }
    return ans;
}



```

