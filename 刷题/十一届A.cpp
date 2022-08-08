//#include <iostream>

//using namespace std;
//
//int main() {
//	int cnt = 0;
//	for (int i = 1; i <= 2020; i++) {
//		int t = i;
//		while (t) {
//			if (t % 10 == 2)
//				cnt++;
//			t /= 10;
//		}
//	}
//	cout << cnt;
//	return 0;
//}



// 2481215
//#include <iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	int cnt = 0;
//	for (int i = 1; i <= 2020; i++)
//		for (int j = 1; j <= 2020; j++) {
//			if (gcd(i, j) == 1)
//				cnt++;
//		}
//	cout << cnt;
//	return 0;
//}

// 761




// 答案：80
//#include <iostream>
//#include <set>
//using namespace std;
//set<set<int>> ss; // 内部存储的是一串数字集合
//// a1 b2 c3 d4 e5 f6 g7 用数字表示字符
//int map[8][8];
//bool st[8]; // 是否被选择
//int cnt;
//
//// 以u为起点出发的灯管
//void dfs(int u, set<int> s) {
//	// 没有出现过的序列
//	if (!ss.count(s)) {
//		ss.insert(s);
//		cnt++;
//	}
//	if (s.size() == 7)
//		return;
//
//	for (int i = 1; i <= 7; i++) {
//		if (map[u][i] && !st[i]) {
//			st[i] = true;
//			s.insert(i);
//			dfs(i, s);
//			// 恢复现场
//			st[i] = false;
//			s.erase(i);
//		}
//	}
//}
//
//int main() {
//	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;
//	map[a][b] = map[a][f] = 1;
//	map[b][a] = map[b][g] = map[b][c] = 1;
//	map[c][b] = map[c][g] = map[c][d] = 1;
//	map[d][c] = map[d][e] = 1;
//	map[e][d] = map[e][g] = map[e][f] = 1;
//	map[f][e] = map[f][a] = map[f][g] = 1;
//	map[g][f] = map[g][b] = map[g][e] = map[g][c] = 1;
////	set<int> a;
////	a.insert(1);
////	dfs(1);
//	for (int i = 1; i <= 7; i++) {
//		set<int> s;
//		s.insert(i);
//		dfs(i, s);
//	}
//	cout << ss.size() << endl;
//	return 0;
//}



// 回文日期
//#include <iostream>
//using namespace std;
//int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int res1, res2;
//bool f1, f2; // 标记两个日期都找出了
//
//bool is_leap(int year) {
//	if (year % 4 == 0 && year % 100)
//		return true;
//	if (year % 400 == 0 )
//		return true;
//	return false;
//}
//
//int Getsum(int a[]) {
//	int sum = 0;
//	for (int i = 1; i <= 4; i++) {
//		sum = sum * 10  + a[i];
//	}
//	for (int i = 4; i >= 1; i--) {
//		sum = sum * 10 + a[i];
//	}
//	return sum;
//}
//
//int main() {
//	int n;
//	cin >> n; // 输入的日期
//
//	int now = n / 10000; // 取出年份
//	for (int year = now; ; year++) {
////		cout << "当前年份" << year << endl;
//		int a[10]; // 存储日期各位数字
//		int t = year;
//		for (int i = 4; i >= 1; i--) {
//			a[i] = t % 10;
//			t /= 10;
//		}
//		int m = a[4] * 10 + a[3];
//		if (m > 12)
//			continue; // 月份合法
//		int d = a[2] * 10 + a[1];
//		// 2月份特判
//		if (m == 2 && d > day[2] + is_leap(year))
//			continue;
//		if (m != 2 && d > day[m])
//			continue;
//
//		int newYear = Getsum(a);
//		cout << "回文日期：" << newYear << endl;
//		if (newYear <= n)
//			continue;
//
//		if (!f1) {
//			res1 = newYear;
//			f1 = true;
//		}
//		// ABAB
//		if (a[1] == a[3] && a[2] == a[4] && a[1] != a[2]) {
//			res2 = newYear;
//			f2 = true;
//		}
//		// 两个日期都找到了
//		if (f1 && f2)
//			break;
//
//	}
////	int a[5] = {0, 1, 2, 3, 4};
////	cout << Getsum(a);
//	cout << res1 << " " << res2 << endl;
//	return 0;
//}


// 字串分值
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 28;
//int pre[N], nxt[N];
//int last[N]; // 默认上一次出现的位置为0
//string s;
//// ababc
//int main() {
//	cin >> s;
//	s = "0" + s;
//	int n = s.size() - 1;
//	// 记录与当前位置字母相同的前一个位置
//	for (int i = 1; i <= n; i++) {
//		int c = s[i] - 'a'; // 把字母转化为数字
//		pre[i] = last[c]; // 与当前位置字母相同的上一个字母的位置
//		last[c] = i; // 记录字母c新出现的位置
//	}
//
////	for (int i = 1; i <= n; i++) {
////		cout << pre[i] << " ";
////	}
//	// 记录与当前位置字母相同的下一个位置
//	for (int i = 0; i < N; i++)
//		last[i] = n + 1;
//
//	for (int i = n; i >= 1; i--) {
//		int c = s[i] - 'a';
//		nxt[i] = last[c];
//		last[c] = i;
//	}
////	for (int i = 1; i <= n; i++)
////		cout << nxt[i] << " ";
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += (i - pre[i]) * (nxt[i] - i);
//	}
//	cout << sum;
//	return 0;
//}





// 合并检测
//#include<iostream>
//using namespace std;

//int main() {
//	int ans = 0x3f3f3f3f, tempx = 1;
//	int x = 10000;
//	for(int i = 1; i <= x; i++) {
//		int t = x / i;
//		if(x % i != 0)	t += 1;
//		t = t + 0.01 * x * i;
//		if(ans > t)	ans = t, tempx = i;		
//	}
//	cout << tempx;
//	return 0;
//} 

// 分配口罩
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int a[15] = {9090400, 8499400, 5926800,8547000, 4958200, 4422600, 5751200,
//4175600, 6309600, 5865200, 6604400, 4635000, 10663400, 8087200, 4554000};
//int ans = 0x3f3f3f3f;

//void dfs(int u, int s1, int s2) {
//	if(u == 15) {
//		ans = min(ans, abs(s1 -s2));
//		return;
//	}
//	dfs(u + 1, s1 + a[u], s2);
//	dfs(u + 1, s1, s2 + a[u]);
//}
//int main() {
//	dfs(0, 0, 0);
//	cout << ans;
//	return 0;
//} 

// 完美平方数 




// 解码 
//#include<iostream>
//#include<cstring>
//using namespace std;
//string s;
//int main() {
//	cin >> s;
//	string ans;
//	for(int i = 0; i < s.size(); i++) {
//		if(isdigit(s[i])) {
//			int n = s[i] - '0' - 1;
//			while(n--)	ans += s[i-1];
//		}
//		else	ans += s[i];
//	}
//	cout << ans << endl;
//	return 0;
//}

// 走方格 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 31;
//int f[N][N];
//int n, m;
//int main() {
//	cin >> n >> m;
//	if(n % 2 == 0 && m % 2 == 0) {
//		puts("0");
//	}else {
//		for(int i = 1; i <= n; i++)	f[n][1] = 1;
//		for(int j = 1; j <= m; j++)	f[1][j] = 1;
//		for(int i = 2; i <= n; i++)
//			for(int j = 2; j <= m; j++) {
//				if((i & 1) || (j & 1))
//					f[i][j] += (f[i - 1][j] + f[i][j-1]);
//			}
//		cout << f[n][m] << endl;
//	}
//	return 0;
//}

//include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int N =31;
//int n;
//int x[N];
//int y[N];
//int r[N];
//bool vis[N];
//int ans;

//void dfs(int step,int sum){
//    if(step==n){
//        ans=max(ans,sum);
//        return;
//    }
//    for(int i=1;i<=n;i++){
//        if(!vis[i]){
//            int tmp=r[i];
//            for(int j=1;j<=n;j++){
//               if(vis[j] && j!=i && ((pow(x[i]-x[j],2)+pow(y[i]-y[j],2))<pow(r[i]+r[j],2)) )
//                    r[i]=0;
//            }
//            vis[i]=true;
//            dfs(step+1,sum+r[i]*r[i]);
//            vis[i]=false;
//            r[i]=tmp;
//        }
//    }

//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        cin>>x[i]>>y[i]>>r[i];
//    dfs(0,0);
//    cout<<ans<<endl;
//}

// 数字三角形
//#include<iostream>
//#include<cmath>
//#include<cstdio>
//using namespace std;
//const int N = 110;
//int g[N][N];
//int n;
//struct Node {
//	int sum = 0; // 从最顶点走到当前点向左、右各走了几步 
//	int l = 0;
//	int r = 0;
//};
//Node f[N][N];
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= i; j++) {
//			int s;
//			scanf("%d", &s);
//			f[i][j].sum = s;
//		}
//	for(int i = 2; i <= n; i++)
//		for(int j = 1; j <= i; j++) {
//			if(f[i-1][j-1].sum > f[i-1][j].sum) {
//				f[i][j].sum += f[i-1][j-1].sum;
//				f[i][j].l  = f[i-1][j-1].l;
//				f[i][j].r = f[i-1][j-1].r + 1;
//			}else {
//				f[i][j].sum += f[i-1][j].sum;
//				f[i][j].r = f[i-1][j].r;
//				f[i][j].l = f[i-1][j].l + 1;
//			}
//		}
//	int ans = 0;
//	for(int i = 1; i <= n;i++) {
//		if(abs(f[n][i].l - f[n][i].r) <= 1)
//			ans = max(ans, f[n][i].sum);
//	}
//	cout << ans << endl;
//	return 0;
//} 

//#include<iostream>
//using namespace std;
//typedef long long LL;
//LL n;
//const int N = 3020;
//LL f[N][N];
//bool flag;

//int main() {
//	cin >> n;
//	LL cnt = 1; // 计数 
//	f[1][1] = 1;
//	if(n == 1) {
//		cout << "1" << endl;
//		return 0;
//	}
//	for(int i = 2; i <= N; i++) {
//		if(!flag)
//			for(int j = 1; j <= i; j++) {
//				if(j == 1 || j == i)	f[i][j] = 1;
//				else	f[i][j] = f[i-1][j-1] + f[i-1][j];
//				cout << f[i][j] << " ";
//				cnt++;
//				if(f[i][j] == n) {
//					flag = true;
//					break;
//				}
//			}	
//		cout << endl;
//	}
//		
//	cout << cnt << endl;
//	return 0;
//}







