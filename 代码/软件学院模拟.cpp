

//
//int main() {
//	double l = 2.0, r = 3.0;
//	while(fabs(r - l) > 1e-8) {
//		double mid = (l + r) / 2;
//		if(pow(mid, mid) > 10.0) {
//			r = mid;
//			cout << r << endl;
//		}
//		else {
//			l = mid;
//			cout << l << endl;
//		}
//	}
//	cout << r << endl;
//	printf("%f", r);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const int N = 9;
//int cnt[N], res[20], ans;
//// 从1到8种选数 
//void dfs(int u, int last) { 
//	if(u == 17) {
//		ans++;
////		for(int i = 1; i <= 16; i++)	cout << res[i] << " ";
////		cout << endl;
//		return; 
//	}
//	for(int i = 1; i <= 8; i++) {
//		if(last != i && cnt[i]) {
//			cnt[i]--;
////			res[u] = i;
//			dfs(u + 1, i);
//			cnt[i]++;
//		}
//	}
//}
//int main(){
//	for(int i = 1;i <= 8; i++)	cnt[i] = 2;
//	dfs(1, 0); 
//	cout << ans << endl;
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<vector>
//using namespace std;
//int n;

//typedef struct Node {
//	int s, a, b;
//	bool operator < (const Node& t) const {
//		if(s != t.s)	return s < t.s;
//		else if(a != t.a)	return a < t.a;
//		else	return b < t.b;
//	}
//}node;
//vector<node> q;
//int main() {
//	scanf("%d", &n);
//	for(int i = 0; i * i <= n; i++)
//		for(int j = i; i * i + j * j <= n; j++) {
//			int s = i * i + j * j;
//			q.push_back({s, i, j});
//		}
//	sort(q.begin(), q.end());
//	
//	for(int a = 0; a * a <= n; a++)
//		for(int b = a; a * a + b * b <= n; b++) {
//			int res = n - a * a - b * b;
//			int l = 0, r = q.size() - 1;
//			while(l < r) {
//				int mid = l + r >> 1;
//				if(q[mid].s >= res)	r = mid;
//				else l = mid + 1;
//			}
//			if(q[r].s == res) {
//				cout << a << " "<< b << " " << q[r].a << " " << q[r].b << endl;
//				return 0;
//			}
//		}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll maxn = LLONG_MAX;
//bool check(ll x) {
//	if((x % 2) && (x % 5) && (x % 11) && (x % 13))	return true;
//	return false;
//}
//int main() {
//	ll ans = 0;
//	for(ll i = 2; i <= maxn; i++)	
//		if(check(i))	ans++;
//	cout << ans << endl;
//	return 0;
//}

// 第七题 
//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//const int N = 100010;
//int h[N], e[N * 2], ne[N * 2], idx, w[N];
//int n, k;
//int dist[N];
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx;
//	++idx;
//}

//int bfs(int u) {
//	memset(dist, -1, sizeof dist);
//	queue<int> q;
//	q.push(u);
//	dist[u] = 0; // 初始根节点层数为0 
//	int res = w[u];
//	
//	while(q.size() && dist[q.front()] < k) {
//		int t = q.front();
//		q.pop();
//		for(int i = h[t]; i != -1; i = ne[i]) {
//			int j = e[i];
//			if(dist[j] == -1) {
//				dist[j] = dist[t] + 1;
//				q.push(j);
//				res += w[j];
//			}
//		}
//	}
//	return res;
//}

//int main() {
//	memset(h, -1, sizeof h);
//	scanf("%d%d", &n, &k);
//	for(int i = 0; i < n - 1; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//	}
//	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
//	for(int i = 1; i <= n; i++) {
//		cout << bfs(i) << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<cmath>
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll maxl = LLONG_MAX;

//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}

//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}

//int main() {
//	int s[4] = {2, 5, 11, 13};
//	//for(int i = 0; i < 4; i++)
////		for(int j = i + 1; j < 4; j++) {
////			for(int k = j + 1; k < 4; k++) {
////				cout << s[i] << " " << s[j] << " " << s[k] << ": ";
////				cout << lcm(lcm(s[i], s[j]), s[k]) << endl;
////			}
////		}
//	int k = lcm(lcm(2,5),11);
//	k = lcm(k, 13);
////	cout << k;
//	ll ans = 0;
//	ll sum1, sum2, sum3, sum4;
//	sum1 = maxl / 2 + maxl / 5 + maxl / 11 + maxl / 13;
//	sum2 = maxl / 10 + maxl / 22 + maxl/26 + maxl/55 + maxl/65 + maxl/143;
//	sum3 = maxl/110 + maxl/130 + maxl/286 + maxl/715;
//	sum4 = maxl/1430;
//	cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
//	ans = sum1 - sum2 + sum3 - sum4;
//	cout << maxl - ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int N = 100010;
//int h[N], e[N], ne[N], idx;
//int ty[N]; // 星球种类 
//int n, m, s, t;
//void add(int a,int b, int c) {
//	e[idx]= b;
//	ne[idx] = h[a];
//	w[idx] = c;
//	h[a] = idx;
//	++idx;
//}


//int main() {
//	scanf("%d%d%d%d", &n,&m,&s,&t);
//	
//	return 0;
//}



//#include<cstdio>
//#include<iostream>
//using namespace std;
//int arr[20];
//int ans = 0;
//bool st[10];
//void dfs(int u){ // u表示位置 
//	if(u == 17) {
//		for(int i = 1; i <= 16; i++)	cout << arr[i] << " ";
//		cout << endl;
//		ans++;
//		return;
//	}
//	if(arr[u] != 0)	dfs(u + 1);
//	for(int i = 1; i <= 8; i++) {
//		if(!st[i] && u + i + 1 <= 16 && arr[u + i + 1] == 0) {
//			st[i] = true;
//			arr[u] = i;
//			arr[u + i + 1] = i;
//			dfs(u + 1);
//			st[i] = false;
//			arr[u] = 0;
//			arr[u + i + 1] = 0;
//		}
//	}
//}
//int main(){
//	dfs(1);
//	cout<<ans<<endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int N = 100010;
//typedef long long ll;
//int h[N], e[N], ne[N], idx, w[N];
//int type[N]; // 星球的种类
//int dist[N][2][2];
//bool st[N][2][2];
//typedef struct Node{
//	int v, ty1, ty2; 
//}node; 

//int n, m, s, T;
//void add(int a, int b, int c) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	w[idx] = c;
//	h[a] = idx++;	
//}

//int spfa(int s) {
//	memset(dist, 0x3f, sizeof dist);
//	queue<node> q;
//	node tmp;
//	tmp.v = s;
//	if(type[s] == 1) {
//		tmp.ty1 = 1, tmp.ty2 = 0;
//	}
//	else if(type[s] == 2) {
//		tmp.ty1 = 0, tmp.ty2 = 1;
//	}
//	else {
//		tmp.ty1 = 0, tmp.ty2 = 0;
//	}
//	q.push(tmp);
//	st[tmp.v][tmp.ty1][tmp.ty2] = true;
//	dist[tmp.v][tmp.ty1][tmp.ty2] = 0;
//	while(q.size()) {
//		auto t = q.front();
//		q.pop();
//		int u = t.v, t1 = t.ty1, t2 = t.ty2;
//		st[u][t1][t2] = false;
//		for(int i = h[u]; i != -1; i = ne[i]) {
//			int j = e[i];
//			if(type[j] == 3) {
//				if(dist[j][t1][t2] > dist[u][t1][t2]) {
//					dist[j][t1][t2] = dist[u][t1][t2] + w[i];
//					if(!st[j][t1][t2]) {
//						q.push({j, t1, t2});
//						st[j][t1][t2] = true;
//					}
//				}
//			}else if(type[j] == 1 && !t1 && !t2) {
//				if(dist[j][1][0] > dist[u][t1][t2]) {
//					dist[j][1][0] = dist[u][t1][t2] + w[i];
//					if(!st[j][1][0]) {
//						q.push({j, 1, 0});
//						st[j][1][0] = true;
//					}
//				}
//			}else if(type[j] == 2 && t1 == 1 && t2 == 0) {
//				if(dist[j][1][1] > dist[u][t1][t2]) {
//					dist[j][1][1] = dist[u][t1][t2] + w[i];
//					if(!st[j][1][1]) {
//						q.push({j, 1, 1});
//						st[j][1][1] = true;
//					}
//				}
//			}
//		}
//	}
//	if(dist[T][1][1] == 0x3f3f3f3f)	return -1;
//	return dist[T][1][1];
//}

//int main() {
//	memset(h, -1, sizeof h);
//	scanf("%d%d%d%d", &n, &m, &s, &T);
//	for(int i = 1; i <= n; i++)	scanf("%d", &type[i]);
//	while(m--) {
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		add(a, b, c); 
//	}
//	cout << spfa(s) << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
// 
//using namespace std;
// 
//long long C(int n, int m)
//{
//    long long s=1;
//    if(n < m)
//        s=0;
//    else if (n == m || m == 0)
//        s=1;
//    else
//        for(int i=1; i<=m; i++)
//            s = s * (n - i + 1) / i;
// 
//     return s;
// }
// 
//int main(){
//    int n;
//    while(cin>>n){
//        cout<<C(n,4)+C(n,2)+1<<endl;
//    }
//    return 0;
//}
 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 100010, M = 21;
int f[N][M], w[N];
int d[N][M];
vector<int> g[N];
int n, k;

void dfs(int u, int fa) {
	for(int i = 0; i <= k; i++)	d[u][i] = w[u];
	for(auto v : g[u]) {
		if(v != fa) {
			dfs(v, u);
			for(int j = 1; j <= k; j++)
				d[u][j] += d[v][j - 1];
		}
	}
}

void dfs2(int u, int fa) {
	for(auto v : g[u]) {
		if(v != fa) {
			f[v][1] = (f[u][0] + d[v][1]);
			for(int j = 2; j <= k; j++) {
				f[v][j] = (f[u][j-1] - d[v][j - 2] + d[v][j]);
			}
			dfs2(v, u);
		}
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)	cin >> w[i];
	dfs(1, 1);
//	dfs2(1, 0);
	//for(int i = 1; i <= n; i++)
//		cout << f[i][k] << endl;
//	for(int i = 1; i <= n; i++){
//		for(int j = 0; j <= k; j++)
//			cout << d[i][j] << " ";
//		cout << endl;
//	}	
	for(int i = 0; i <= k; i++)
		f[1][i] = d[1][i];
	for(int i = 1; i <= n; i++)	f[i][0] = w[i];
	dfs2(1, 1);
	for(int i = 1; i <= n; i++)	cout << f[i][k] << endl;
	return 0;
}


