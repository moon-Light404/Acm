// 第二场模拟赛




// 89
//#include <iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	int s = 0;
//	for (int i = 1; i <= 2021; i++) {
//		if (gcd(2021, i) > 1)
//			s++;
//	}
//	cout << s << endl;
//	return 0;
//}

// 平方差
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
//int main() {
//	int sum = 0;
//	for (int i = 1; i <= 2021; i++) {
//		for (int j = 0; j <= i; j++) {
//			int k = i + j * j;
//			int sq = sqrt(k);
//			if (sq * sq == k) {
//				sum++;
//				break;
//			}
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

// 答案：78
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//unordered_map<char, int> mp;
//string s =
//    "FFEEFEAAECFFBDBFBCDADACDEEDCCFFAFADEFBBAFDCDDCDBFEFCEDDBFDBEEFCAAEECEECDCDECADDCDFAEACECFEADCBFECADFDFBAAADCFAFFCEADFDDAEAFAFFDEFECEDEEEDFBDBFDDFFBCFACECEDCAFAFEFAFCDBDCCBCCEADADAEBAFBACACBFCBABFDAFBEFCFDCFBCEDCEAFBCDBDDBDEFCAAAACCFFCBBAAEECFEFCFDEEDCACDACECFFBAAAFACDBFFAEFFCCCDBFADDDBEBCBEEDDECFAFFCDEAFBCBBCBAEDFDBEBBBBABBFDECBCEFAABCBCFFBDBACCFFABEAEBEACBBDCBCCFADDCACFDEDECCCBFAFCBFECAACAFBCFBAF";
//
//int main() {
//	int maxn = -1;
//	for (int i = 0; i < s.size(); i++) {
//		mp[s[i]]++;
//		maxn = max(maxn, mp[s[i]]);
//	}
//	cout << maxn << endl;
//	return 0;
//}

// 第六题：买铅笔
//#include <iostream>
//using namespace std;
//int p, t;
//int main() {
//	cin >> p >> t;
//	int k = t / 12;
//	if (k * 12 != t)
//		k++;
//	cout << k *p << endl;
//	return 0;
//}

// 第七题 直角三角形
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	if (a * a + b * b == c * c || a * a + c * c == b * b || b*b + c * c == a * a)	cout << "YES" << endl;
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//	return 0;
//}











// 第八题
//#include <iostream>
//using namespace std;
//typedef long long LL;
//
//// 求组合数
//LL C(LL n, LL m) {
//	LL res = 1;
//	for (LL i = 1; i <= m; i++) {
//		res = res * (n - m + i) / i;
//	}
//	return res;
//}
//
//int main() {
//	LL n;
//	cin >> n;
//	cout << C(n, n / 2) << endl;
//	return 0;
//}





//
//#include <iostream>
//using namespace std;

//int getTime() {
//	int h1, h2, m1, m2, s1, s2, d = 0;
//	scanf("%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
//	return d * 24 * 3600 + h2 * 3600 + m2 * 60 + s2 - (h1 * 3600 + m1 * 60 + s1);
//}

//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int t1 = getTime();
//		int t2 = getTime();
//		int tt = (t1 + t2) / 2;
//		printf("%02d:%02d:%02d\n", tt / 3600, (tt / 60) % 60, tt % 60);
//	}
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstdio>
//using namespace std;
//int g[20][5] = {
//97,90,0,0,0,
//92,85,96,0,0,
//0,0,0,0,93,
//0,0,0,80,86,
//89,83,97,0,0,
//82,86,0,0,0,
//0,0,0,87,90,
//0,97,96,0,0,
//0,0,89,0,0,
//95,99,0,0,0,
//0,0,96,97,0,
//0,0,0,93,98,
//94,91,0,0,0,
//0,83,87,0,0,
//0,0,98,97,98,
//0,0,0,93,86,
//98,83,99,98,81,
//93,87,92,96,98,
//0,0,0,89,92,
//0,99,96,95,81,
//};
//bool st[21]; // 某个球员已经被选 
//int ans, res;

//void dfs(int u, int ans) { // u表示几号位 
//	if(u == 5) {
//		res = max(res, ans);
//		return;
//	}
//	for(int i = 0; i < 20; i++) {
//		if(!st[i] && g[i][u] > 0) {
//			st[i] = true;
//			dfs(u + 1, ans + g[i][u]);
//			st[i] = false;
//		}
//	}
//}

//int main() {
//	dfs(0, 0);
//	cout << res << endl;
//	return 0;
//}

// 跳跃 
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int a[N][N], f[N][N];
//int n, m; 
//const int INF = 0x3f3f3f3f;

//int main() {
//	cin >> n >> m;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)	
//			cin >> a[i][j];
//	
//	f[1][1] = a[1][1];
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++) {
//			if(i == 1 && j == 1)	continue;
//			int t = -INF;
//			for(int k = 1; k <= 3; k++) {
//				if(i - k < 1)	break;
//				t = max(t, f[i - k][j]);
//			}
//			for(int k = 1; k <= 3; k++) {
//				if(j - k < 1)	break;
//				t = max(t, f[i][j - k]);
//			}
//			for(int i1 = 1; i1 <= 2; i1++)
//				for(int j1 = 1; j1 <= 2; j1++) {
//					if(i1 + j1 > 3)	continue;
//					if(i - i1 >= 1 && j - j1 >= 1)
//						t = max(t, f[i - i1][j - j1]);
//				}
//			f[i][j] = t + a[i][j];
//		}
//		
//	cout << f[n][m] << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int n, m;
//int ans;

//void dfs(int u, int sum, int pre) { // 当前第几个盘子， 已经放了sum个苹果 
//	if(sum > n)	return;
//	if(u > m)	return;
//	if(sum == n) {
//		ans++;
//		return;
//	}
//	for(int i = pre; i <= n; i++) {
//		dfs(u + 1, sum + i, i);
//	}
//}

//int main() {
//	cin >> n >> m;
//	dfs(0, 0, 1);
//	cout << ans << endl;
//	return 0;
//}



