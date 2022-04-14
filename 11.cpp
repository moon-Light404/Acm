// C题 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 200010;
//typedef long long ll;
//int a[N];
//int sum[N];
//int n;

//int main() {
//	scanf("%d", &n);
//	for(int i = 1; i <= n; i++)	{
//		scanf("%d", &a[i]);
//		sum[i] = sum[i - 1] + a[i];
//	}	
//	ll res = 0;
//	for(int i = 1; i < n; i++) {
//		res += (ll)a[i] * (sum[n] - sum[i]);
//	}
//	res *= (ll)sum[n];
//	cout << res << endl;
//	return 0;
//}

// 选数异或D 待优化 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 100010;
//int a[N];
//int n, m, x;

//bool query(int l, int r) {
//	for(int i = l; i < r; i++)
//		for(int j = i + 1; j <= r; j++)
//			if((a[i] ^ a[j]) == x) {
//				return true;
//			}
//	return false;
//}

//int main() {
//	scanf("%d%d%d", &n, &m, &x);
//	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
//	while(m--) {
//		int l, r;
//		scanf("%d%d", &l, &r);
//		if(query(l, r))	puts("yes");
//		else	puts("no");
//	}
//	return 0;
//}

// F题 
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 100010;
//int h[N], tmp[N]; // 对应位置的石头高度、或没有石头 
//int n, k; // 要来回2k次
// 
//bool check(int x, int cnt) {
//	while(cnt--){ // 来回cnt次 2 * cnt 
//		int pos = 0; // 当前位置 
//		for(int i = 1; i < n; i++) {
//			
//		}
//		if(pos + x >= n) h[pos]--, pos = n;
//		else	return false; // 到不了终点
//		
//		for(int i = n - 1; i >= 1; i--) {
//			while(h[i] >= 1 && pos - x <= i) 
//			if(pos != n) h[pos]--;
//			pos = i;
//			if(pos - x > i)	return false;
//		} 
//		if(pos - x <= 0)	h[pos]--, pos = 0;
//		else	return false;
//	}
//	return true;
//}

//int main() {
//	scanf("%d%d", &n, &k);
//	for(int i = 1; i < n; i++)	scanf("%d", &tmp[i]);
//	int l = 1, r = n;
//	while(l < r) {
//		memcpy(h, tmp, sizeof tmp);
//		int mid = l + r >> 1;
//		if(check(mid, k))	r = mid;
//		else l = mid + 1;
//	}
//	cout << r << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const int N = 100010;
//int a[N], f[N];
//int n, m;
//int main() {
//	cin >> n >> m;
//	for(int i = 1; i <= n; i++)	cin >> a[i];
//	for(int i = 1; i <= n; i++) {
//		f[i] = 1;
//		for(int j = 1; j < i; j++)
//			if(a[j] <= a[i])	f[i] = max(f[i], f[j] + 1);
//	}
//	for(int i = 1; i <= n; i++)	cout << f[i] << " ";
//	return 0;
//}

// 扫描游戏 

//#include<iostream>
//#include<vector>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 200010;
//int n, L;
//int ans[N];

//typedef struct Node {
//	int id; // 第几个被扫描到 
//	int x, y, z;
//	int sum;
//	//bool operator < (const Node& t) const {
////		if(sum != t.sum)	return sum < t.sum;
////	}
//}node;
//bool st[N];

//vector<node> q;

//int main() {
//	scanf("%d%d", &n, &L);
//	memset(ans, -1, sizeof ans);
//	for(int i = 1; i <= n; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		q.push_back({1,a, b, c, a * a + b * b});
//	}
//	int cnt = 0;
//	for(int i = 0; i < q.size(); i++) {
//		int j = i;
//		if(L * L >= q[j].sum) {
//			while(q[j].sum <= L * L) {
//				ans[q[j].id] = cnt;
//				L += q[j].z;
//				j++;
//			}
//		}
//		i = j - 1;
//		cnt++;
//	}
//	for(int i = 1; i <= n; i++)	
//		printf("%d ", ans[i]); 
//	return 0;
//}





