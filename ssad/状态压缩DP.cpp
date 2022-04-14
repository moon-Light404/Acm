// 状态压缩DP










//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 13;
//const int M = 1 << N;
//const int mod = 100000000;
//
//int st[M], map[M]; ///分别存每一行的状态和给出地的状态
//int dp[N][M];  //表示在第i行状态为j时候可以放牛的种数
//bool judge1(int x) { //判断二进制有没有相邻的1
//	return (x & (x << 1));
//}
//
//bool judge2(int i, int x) {
//	return (map[i] & st[x]);
//}
//
//int main() {
//	int n, m, x;
//	while (~scanf("%d%d", &n, &m)) {
//		memset(st, 0, sizeof(st));
//		memset(map, 0, sizeof(map));
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= n; i++) {
//			for (int j = m; j >= 1; j--) {
//				scanf("%d", &x);
//				if (x == 0)
//					map[i] += (1 << (j - 1));
//			}
//
//		}
//		for (int i = 1; i <= n; i++)
//			cout << map[i] << endl;
////		cout << judge1(n) << endl;
////        int k=0;
////        for(int i=0;i<(1<<m);i++){
////            if(!judge1(i))
////                st[k++]=i;
////        }
////        for(int i=0;i<k;i++)
////        {
////            if(!judge2(1,i))
////                dp[1][i]=1;
////        }
////        for(int i=2;i<=n;i++)
////        {
////            for(int j=0;j<k;j++)
////            {
////                if(judge2(i,j))  //判断第i行 假如按状态j放牛的话行不行。
////                    continue;
////                for(int f=0;f<k;f++)
////                {
////                    if(judge2(i-1,f))   //剪枝 判断上一行与其状态是否满足
////                        continue;
////                    if(!(st[j]&st[f]))
////                        dp[i][j]+=dp[i-1][f];
////                }
////            }
////        }
////        int ans=0;
////        for(int i=0;i<k;i++){
////            ans+=dp[n][i];
////            ans%=mod;
////        }
////        printf("%d\n",ans);
//	}
//	return 0;
//}

// acwing.最短Hamilton路径
//#include <iostream>
//#include <cstring>
//using namespace std;
//typedef long long LL;
//const int N = 20, M = 1 << 20;
//// f[i][j] 表示到达j且经过的路径为i(二进制数字串)的最短路径
//LL f[M][N], g[N][N];
//int main() {
//	memset(f, 0x3f, sizeof f);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//			int d;
//			scanf("%d", &d);
//			g[i][j] = d;
//		}
//
//	f[1][0] = 0;
//	for (int state = 0; state < (1 << n); state++)
//		if (state & 1) // 起点从0号点开始
//			for (int j = 0; j < n; j++)
//				if (state >> j & 1) {
//					for (int k = 0; k < n; k++) { // 由k点转化为j点
//						if (state ^ (1 << j) >> k & 1 && g[k][j] != 0) {
//							f[state][j] = min(f[state][j], f[state ^ (1 << j)][k] + g[k][j]);
//						}
//					}
//				}
//	cout << f[(1 << n) - 1][n - 1] << endl;
//	return 0;
//}








//#include <iostream>
//using namespace std;
//const int N = 21, M = 1 << 21;
//typedef long long LL;
//LL f[M][N]; // f[i][j]从0走到j,且路径状态为i的方案数
//bool g[N][N];
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	for (int i = 1; i <= 21; i++)
//		for (int j = 1; j <= 21; j++) {
//			if (gcd(i, j) == 1)
//				g[i - 1][j - 1] = true;
//		}
//	f[1][0] = 1;
//	for (int state = 1; state < M; state++)
//		for (int j = 0; j <= 20; j++)
//			if (state >> j & 1) {
//				for (int k = 0; k <= 20; k++) {
//					if (state ^ (1 << j) >> k & 1 && g[k][j])
//						f[state][j] += f[state ^ (1 << j)][k];
//				}
//			}
//
//	LL ans = 0; // M-1为全1所有点都经过了一次,1和所有数互质,所以其它点都可回到1(原点0)
//	for (int i = 1; i <= 20; i++)
//		ans += f[M - 1][i];
//	cout << ans << endl;
//	return 0;
//}





















// 蓝桥杯国际象棋
//#include <iostream>
//using namespace std;
//typedef long long LL;
//const int M = 105, N = 1 << 6, K = 25;
//LL f[M][N][N][K]; // f[i][a][b][j] 前i列已经摆好，当前状态是a,上一状态是b,前i列总共放了K个
//int m, n, k;
//const int Mod = 1e9 + 7;
//
//bool check(int state, int c) {
//	if (c == 1) {
//		return !(state & (state >> 1)); // 没有连续的1
//	} else {
//		return !(state & (state >> 2)); // 没有间隔一位的1
//	}
//}
//
//int cont(int state) {
//	int res = 0;
//	while (state) {
//		if (state & 1)
//			res++;
//		state >>= 1;
//	}
//	return res;
//}
//
//int main() {
//	cin >> n >> m >> k; // n行m列
//
//	f[0][0][0][0] = 1; // 0列是不存在的，本题从1列开始
//	int st = 1 << n;
//	for (int i = 1; i <= m; i++) // 从第1列开始
//		for (int sc = 0; sc < st; sc++) // 前前列
//			for (int sb = 0; sb < st; sb++) // 前1列
////				if (check((sc | sb), 2))
////					continue;
//				if ((sc >> 2) & sb || sc & (sb >> 2))
//					continue;
//				else
//					for (int sa = 0; sa < st; sa++) { // 当前列的状态
////						if (check((sa | sc), 1) || check((sa | sb), 2))
////							continue;
//						if ((sa >> 1) & sc || (sc >> 1) & sa)
//							continue;
//						if ((sa >> 2) & sb || (sb >> 2) & sa)
//							continue;
//						int t = cont(sa);
//						for (int j = t; j <= k; j++) { // 前i层放几个,第i层已经放了t个
//							f[i][sa][sb][j] = (f[i][sa][sb][j] + f[i - 1][sb][sc][j - t]) % Mod;
//						}
//					}
//	LL ans = 0;
//	for (int i = 0; i < st; i++)
//		for (int j = 0; j < st; j++)
//			ans = (ans + f[m][i][j][k]) % Mod;
//	cout << ans << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//bool check(int state, int c) {
//	if (c == 1) {
//		return (state & (state >> 1)); // 没有连续的1
//	}
//	return (state & (state >> 2)); // 没有间隔一位的1
//}
////100101
//
//int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		if (check(n, m))
//			puts("true");
//		else
//			puts("false");
//	}
//	return 0;
//}


#include <iostream>
using namespace std;
typedef long long LL;
const int N = 21, M = 1 << N;
int g[N][N];
LL f[M][N]; // f[i][j]表示从1走到点j,且路径状态为i的方案数

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	for (int i = 1; i <= 21; i++)
		for (int j = 1; j <= 21; j++)
			if (gcd(i, j) == 1)
				g[i - 1][j - 1] = 1;

	f[1][0] = 1;
	for (int state = 1; state < M; state++)
		if (state & 1)
			for (int j = 0; j <= 20; j++)
				if (state >> j & 1)
					for (int k = 0; k <= 20; k++)
						if (state ^ (1 << j) >> k & 1 && g[k][j])
							f[state][j] += f[state ^ (1 << j)][k];
	LL ans = 0;
	for (int i = 1; i <= 20; i++)
		ans += f[M - 1][i];
	cout << ans << endl;
	return 0;
}

