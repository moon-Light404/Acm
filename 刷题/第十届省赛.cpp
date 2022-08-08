//#include<iostream>
//#include<queue>
//using namespace std;
//string s = "010101010010110010010101100101101001000010001010100000100010000010101001000010000000100110011010010101111011010010001000001101001011100011000000010000010000000010101000110100001010000010101010110010110001111100000010100001001010001010000010110000000011001000110101000010101100011010011010101011110111000110110101010010010010100000010001010011100000001010000010100010011010101011111001100001000011101000111000001010100001100010000001000101001100001001110001101000011100100010010101010101010100011010000001000010010000010100101010111010001010101000010111100100101001001000010000010101010100100100010100000000100000001010110011110100011000001010101000111010101001110000100001100001011001111011010000100010101010100001101010100101000010100000111011101001100000001011000100001011001011010010111000000001001010100100000001010010000100010000010001111010100100101001010101101001010100011010101101110000110101110010100001000011000000101001010000010001110000100000100011000011010110100000010010100100100001110110100101000101000000001110110010110101101010100001001010000100001101010100001000100010010001000101011010000100011001000100001010100101010101111101001000000100101000000110010100101001000001000000000010110100000010011101110010010000111010010110111010000000011010001000100010000000100001110100000011001110101000101000100010001111100010101001010000001000100000101001010010101100000001001010100010111010000011110000100001000000011011100000000100000000101110000001100111010111010001000110111010101101111000";
//char g[30][50];

//string s1 = "DLRU";
//int dir[4][2] = {{1,0}, {0,-1},{0,1},{-1,0}}; 
//typedef struct Node {
//	int x, y;
// 	string way;
//}node;
//bool st[30][50];

//string bfs() {
//	queue<node> q;
//	q.push({0,0,""});
//	st[0][0] = true;
//	while(q.size()) {
//		auto t = q.front();
//		q.pop();
//		if(t.x == 29 && t.y == 49)	return t.way;
//		for(int i = 0; i < 4; i++) {
//			int x = t.x, y = t.y;
//			int nx = x + dir[i][0], ny = y + dir[i][1];
//			if(nx < 0 || nx >= 30 || ny < 0 || ny >= 50 || st[nx][ny])	continue;
//			if(g[nx][ny] == '1')	continue;
//			st[nx][ny] = true;
//			q.push({nx, ny, t.way + s1[i]});
//			
//		}
//	}
//	return "";
//}


//int main() {
//	for(int i = 0; i < 30; i++) {
//		for(int j = 0; j < 50; j++) {
//			g[i][j] = s[i * 50 + j];
//		}
//	}
//	cout << bfs() << endl;
//	return 0;
//}

// DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRD
// RRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURR
// URRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRR
// RRDDDDDDRR

// RSA
//#include<iostream>
//using namespace std;
//typedef long long ll;
//ll n = 1001733993063167141;

//void BF(ll x) {
////	1123984201* 891234941
//	cout << x << "= ";
//	for(ll i = 2; i * i <= n; i++) {
//		if(x % i == 0) {
//			cout << x / i << "* " << i << endl;
//			break;
//		}
//	}
//}

//void extgcd(ll a, ll b, ll& x, ll& y) {
//	if(b == 0) {
//		x = 1;
//		y = 0;
//		return;
//	}
//	extgcd(b, a % b, x, y);
//	ll t = y;
//	y = x - (a / b) * y;
//	x = t;
//	return;
//} 

//// a * b % mod
//ll fast_pro(ll a, ll b, ll mod) {
//	ll ans = 0;
//	while(b) {
//		if(b & 1)	ans = (ans + a) % mod;
//		a = (a + a) % mod;
//		b >>= 1;
//	}
//	return ans;
//}

//ll get_pow(ll a, ll b, ll mod) {
//	ll ans = 1;
//	while(b) {
//		if(b & 1)	ans = fast_pro(ans, a, mod);
//		a = fast_pro(a, a, mod);
//		b >>= 1;
//	}
//	return ans;
//}

//int main() {
////	BF(n);
//	ll m = (ll) (1123984201 - 1) * (891234941 - 1);
//	ll a = 212353, b = m, x, y;
//	extgcd(a, b, x, y);
//	ll e = (x % m + m) % m;
//	cout << e << endl;  //823816093931522017
//	ll res = get_pow(20190324, e, n);
//	cout << res << endl;
//	return 0;
//}


// 修改数组暴力 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 10010;
//int a[N];
//int n;

//bool check(int x) {
//	int num = a[x];
//	for(int j = 0; j < x; j++) {
//		if(a[j] == num)	return true; // 前面出现相同的数 
//	}
//	return false;
//}
//int main() {
//	scanf("%d", &n);
//	for(int i = 0; i < n; i++)	scanf("%d", &a[i]);
//	for(int i = 1; i < n; i++) {
//		while(check(i))	a[i]++;
//	}
//	for(int i = 0; i < n; i++)	cout << a[i] << " ";
//		
//	return 0;
//}

// 修改数组并查集
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 1000010;
//int fa[N];
//int n;

//int find(int x) {
//	if(x != fa[x])	fa[x] = find(fa[x]);
//	return fa[x];
//}
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++)	fa[i] = i;
//	for(int i = 0; i < n; i++) {
//		int x;
//		scanf("%d", &x);
//		int t = find(x);
//		cout << t << " ";
//		fa[t] = t + 1;
//	}
//	return 0;
//} 



