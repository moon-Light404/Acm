// 第一题 
//#include<iostream>
//using namespace std;

//int get(int x) {
//	int res = 0;
//	while(x) {
//		if(x % 10 == 6)	res++;
//		x /= 10;
//	}
//	return res;
//}

//int main() {
//	int ans = 0;
//	for(int i = 1; i <= 2021; i++) {
//		ans += get(i);
//	}
//	cout << ans << endl;
//	return 0;
//}

// 第二题
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//string s;
//int res1, res2;

//int main() {
//	s = "iawaswapwauawhawdwafwanbiopwanivgbikvblvbwawawawvolyuvgbololvolgbyolgyowagbolgawgboplwawaolgyolwaogblwaygbowawagwabwayawopwawagyowabwaowapjwapcfrtuywawacvujwawawaufttyfuftywawawatifgugbgbyguwawawawayugbigwwwytigwygwgbwyoawawgoghwaogwborgrewabouyhwabyuhowabhnwawauygbawyawuwaoawfcawaaaahwaywauwagwawefwaafmbawklawjiawihnwanhawawawawijwajiofjeriofgjrefjhwaewarwaowagwahwauwaiwarwaiwaqwarwahwaqwawwaowapfweofbwewafwahwaiwaewawwawawawawafwawawawaeiufwepfhnewfwahwajwatwafowawajtokshwawafwaiwahwafwahmgoewawawawafkfjkewnwawafiewhfwawawafjkernhawkrenwawawawafujnrheiowanwakawawawawwanoifewajrwaoawawfweojnwawawawawawawafjkwenawawferkwmpwawawawaforeijawawferhfiueorghwuwafguwegfwaghrwiufgwahweofgowaidwiweaiwwawieyiwe";
////	cin >> s;
//	for(int i = 0; i < s.size() - 1; i++) {
//		if(s.substr(i, 2) != "wa" && s.substr(i, 2) != "aw")	continue;
//		if(s.substr(i, 2) == "wa") {
//			int t = i;
//			while(s.substr(t, 2) == "wa")	t += 2;
//			if(t == i + 2)	res1++;
//			else	res2++;
//			i = t - 1;
//		}else {
//			int t = i;
//			while(s.substr(t, 2) == "aw")	t += 2;
//			if(t == i + 2)	res1++;
//			else res2++;
//			i = t - 1;
//		}
//	}
//	cout << res1 <<  " " << res2 << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//ll a[15];
//ll fenmu[15];


//ll gcd(ll a, ll b) {
//	return b ? gcd(b, a % b) : a;
//}

//ll lcm(ll a, ll b) {
//	return a * b / gcd(a , b);
//}

//int main() {
//	a[1] = 1, a[2] = 1;
//	for(int i = 3; i <= 14; i++) {
//		a[i] = a[i - 2] + a[i - 1];
//	}
//	for(int i = 1; i <= 13; i++) {
//		fenmu[i] = a[i] * a[i + 1];
////		cout << fenmu[i] << " ";
//	}
////	cout << endl;
//	ll maxlcm = 1;
//	for(int i = 1; i <= 13; i++) {
//		maxlcm = (ll)lcm(fenmu[i], maxlcm);
//	}
////	cout << maxlcm << endl;
//	ll fenzi = 0;
//	for(int i = 1; i <= 13;i++) {
//		fenzi += (ll)maxlcm / fenmu[i];
//	}
//	cout << fenzi / gcd(fenzi, maxlcm) << "/" << maxlcm / gcd(fenzi, maxlcm) << endl;
//	return 0;
//}

// 第四题 
//#include<iostream>
//using namespace std;
//bool st[11];
//int a[10] = {2,3,3,3,5,6,6,7,7,8};
////vector<int> num[3]; // 分成3组
//int ans;

//void dfs(int u, int k) {
//	if(k == 3)	return;
//	if(u == 10) {
//		if(k == 2)	ans++;
//	}
//	for(int i = 0; i < 10; i++) {
//		if(!st[i]) {
//			st[i] = true;
//			dfs(u + 1, k);
//			st[i] = false;
//		}
//	}
//	dfs(u + 1, k + 1); // 新的一组 
//}

//int main() {
////	dfs(0, 0);
//	cout << 3402000 << endl;
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//int main(){
//	int n,sum=0;
//	cin>>n;
//	string a,s;
//	string b="@wyk";
//	getline(cin,a); // 读入回车 
//	for(int i=1;i<=n;i++){
//		getline(cin,s);
//		if(s.find(b)!=string::npos) sum++;
//	}
//	cout<<sum<<endl;
//	
//}


//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//using namespace std;

//const int N = 100010, M = 5010;
//int fa[N];
//struct Edge {
//	int a, b;
//	int t;
//	bool operator < (const Edge& k) const {
//		return t < k.t;
//	}
//}edges[N];
//int n, m, cnt;

//int find(int x) {
//	if(x != fa[x])	fa[x] = find(fa[x]);
//	return fa[x];
//}

//int main() {
//	scanf("%d%d", &n, &m);
//	for(int i = 1; i <= n; i++)	fa[i] = i;
//	for(int i = 0; i < m; i++) {
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		edges[cnt++] = {a, b, c};
//	}
//	sort(edges, edges + cnt);
//	int ans = 0, idx = 0;
//	for(int i = 0; i < m; i++) {
//		int a = edges[i].a, b = edges[i].b, t = edges[i].t;
//		int na = find(a), nb = find(b);
//		if(na != nb) {
//			fa[na] = nb;
//			ans = t;
//			idx++;
//		}
//		if(idx == n - 1) {
//			break;
//		}	
//	}
//	if(idx != n - 1)	puts("-1");
//	else cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 2010;
//int fa[N];
//int n, m;
//int find(int x) {
//	if(x != fa[x])	fa[x] = find(fa[x]);
//	return fa[x];	
//}

//int main() {
//	cin >> n >> m;
//	for(int i = 1;i <= n; i++)	fa[i] = i;
//	int cnt = 0;
//	while(m--) {
//		int a, b;
//		cin >> a >> b;
//		int na = find(a), nb = find(b);
//		if(na != nb) {
//			fa[na] = nb;
//			cnt++;
//		}
//	}
//	if(cnt != n - 1)	cout << "-1" << endl;
//	else cout << cnt << endl;
//	return 0;
//}





//#include<iostream>
//using namespace std;
//const int N = 200010;
//int a[N], pre[N];
//int n, m;
//int ans;

//int get(int x, int y) {
//	return (x - 1) * m + y;	
//}

//int main() {
//	cin >> n >> m;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)
//			cin >> a[get(i, j)];
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= m; j++)
//			pre[get(i,j)] = pre[get(i - 1, j)] + a[get(i, j)];
//	 
//	for(int i = 1; i <= n; i++) // 上行 
//		for(int j = i; j <= n; j++) { // 下行 
//			int sum = 0;
//			for(int k = 1; k <= m; k++) {
//				if(sum + pre[get(j, k)] - pre[get(i - 1, k)] < 0) {
//					sum = 0;
//				}else sum += pre[get(j, k)] - pre[get(i - 1, k)];
//				ans = max(ans, sum);
//			}
//		}
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int mod = 1e9 + 7;
//int n = 20210411;

//int fast_pro(int a, int b, int mod) {
//	int ans = 0;
//	while(b) {
//		if(b & 1)	ans = (ans + a) % mod;
//		a = (a + a) % mod;
//		b >>= 1;
//	}
//	return ans;
//}

//int get_pow(int a, int b, int mod) {
//	int ans = 1;
//	while(b) {
//		if(b & 1)	ans = fast_pro(ans, a, mod);
//		a = fast_pro(a, a, mod);
//		b >>= 1;	
//	}
//	return ans;
//}
//int main() {
//	int res = 0, t = 0;
//	for(int i = 1; i <= n - 1; i++) {
//		t = t % mod  + i % mod;
//		res = res % mod + t % mod;
//	}
//	cout << res % mod + get_pow(n, 2, mod) << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int N = 2010;
//int h[N], e[N * 2], ne[N * 2], idx;
//int n, m;
//bool st[N];
//int dist[N][N]; // 到某点的距离 
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}

//void bfs(int u) {
//	queue<int> q;
//	q.push(u);
//	dist[u][u] = 0;
//	st[u] = true;
//	while(q.size()) {
//		auto t = q.front();
//		q.pop();
//		for(int i = h[t]; i != -1; i = ne[i]) {
//			int j = e[i];
//			if(!st[j]) {
//				dist[u][j] = dist[u][t] + 1;
//				q.push(j);
//				st[j] = true;
//			}
//		}
//	}
//}


//int main() {
//	memset(h, -1, sizeof h);
//	memset(dist, 0x3f, sizeof dist);
//	cin >> n >> m;
//	while(m--) {
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a); 
//	}
//	
//	for(int i = 1; i <= n; i++) {
//		memset(st, false, sizeof st);
//		bfs(i);
//	}
//	int maxd = -1e9;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= n; j++) {
//			if(dist[i][j] == 0x3f3f3f3f) {
//				cout << "-1" << endl;
//				return 0;
//			}
//			maxd = max(maxd, dist[i][j]);
//		}
//	cout << maxd << endl;
//	
//	
//	return 0;
//}

