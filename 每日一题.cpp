//// 提高课矩阵距离

//#include <iostream>
//#include <queue>
//#include <cstring>
//#define x first
//#define y second
//using namespace std;
//using T = pair<int, int>;
//const int N = 1010;
//char g[N][N];
//int dist[N][N]; // 最后的距离数组
//int n, m;
//queue<T> q;
//
//void bfs() {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			if (g[i][j] == '1') {
//				dist[i][j] = 0;
//				q.push({i, j});
//			}
//		}
//	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = t.x + dx[i], ny = t.y + dy[i];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//				continue;
//			if (dist[nx][ny] != -1)
//				continue;
//			dist[nx][ny] = dist[t.x][t.y] + 1;
//			q.push({nx, ny});
//		}
//	}
//}
//
//int main() {
//	memset(dist, -1, sizeof dist);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	bfs();
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			cout << dist[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}

// 魔板
//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//typedef struct sta {
//	string sta;
//	vector<char> op;
//} state;
//// A 87654321
//// B 41236785
//// C 17245368
//string en;
//unordered_map<string, bool>	st; // 状态判重
//
//string A(string state) {
//	string newstate = state;
//	reverse(newstate.begin(), newstate.end());
//	return newstate;
//}
//
//string B(string state) {
//	string newstate = state;
//	for (int i = 0; i < 4; i++) {
//		newstate[(i + 1) % 4] = state[i % 4];
//	}
//	for (int j = 7; j > 3; j--) {
//		newstate[(j - 1) % 4 + 4] = state[j % 4 + 4];
//	}
//	return newstate;
//}
//
//string C(string state) {
//	string newstate = state;
//	newstate[2] = state[1];
//	newstate[5] = state[2];
//	newstate[1] = state[6];
//	newstate[6] = state[5];
//	return newstate;
//}
//
//void bfs() {
//	queue<state> q;
//	state start;
//	start.sta = "12345678";
//	q.push(start);
//	st[start.sta] = true;
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		if (t.sta == en) { // 每次进入循环判断是否找到目标
//			cout << t.op.size() << endl;
//			for (auto a : t.op) {
//				cout << a;
//			}
//		}
//		string Astate = A(t.sta);
//		if (!st[Astate]) {
//			state s;
//			s.sta = Astate;
//			s.op = t.op;
//			s.op.push_back('A');
//			st[Astate] = true;
//			q.push(s);
//		}
//
//		string Bstate = B(t.sta);
//		if (!st[Bstate]) {
//			state s;
//			s.sta = Bstate;
//			s.op = t.op;
//			s.op.push_back('B');
//			st[Bstate] = true;
//			q.push(s);
//		}
//
//		string Cstate = C(t.sta);
//		if (!st[Cstate]) {
//			state s;
//			s.sta = Cstate;
//			s.op = t.op;
//			s.op.push_back('C');
//			st[Cstate] = true;
//			q.push(s);
//		}
//	}
//}
//
//int main() {
//	for (int i = 1; i <= 8; i++) {
//		int s;
//		cin >> s;
//		en += '0' + s;
//	}
//	bfs();
////	cout << A(s) << endl;
////	cout << B(s) << endl;
////	cout << C(s) << endl;
//	return 0;
//}

//
//#include <iostream>
//#include <deque>
//#define x first
//#define y second
//using namespace std;
//const int N = 510;
//using T = pair<int, int>;
//char g[N][N];
//int dist[N][N];
//bool st[N][N];
//int n, m;
//int bfs() {
//	memset(dist, 0x3f, sizeof dist);
//	deque<T> q;
//	q.push_back({0, 0});
//	dist[0][0] = 0;
//	char ds[] = "\\/\\/"; // 点可以向四周扩展的理想对角线
//	int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
//	int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1}; // 都是顺时针对应的方向
//	while (q.size()) {
//		auto t = q.front(); // 存储的是点的坐标
//		q.pop_front();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = t.x + dx[i], ny = t.y + dy[i];
//			if (nx < 0 || nx > n || ny < 0 || ny > m)
//				continue;
//
//			int fx = t.x + ix[i], fy = t.y + iy[i];
//			// 不存在通路边权为1， 刚好存在通路边权为0
//			int d = dist[t.x][t.y] + (g[fx][fy] != ds[i]);
//			if (dist[nx][ny] > d) {
//				dist[nx][ny] = d;
//				// 边权为1
//				if (g[fx][fy] != ds[i])
//					q.push_back({nx, ny});
//				else
//					q.push_front({nx, ny});
//			}
//		}
//	}
//	return dist[n][m]; // 点比方块的坐标多1
//
//}
//
//int main() {
//	int T;
//
//	cin >> T;
//	while (T--) {
//		cin >> n >> m;
//		for (int i = 0; i < n; i++)
//			cin >> g[i];
//		int t = bfs();
//		if (t == 0x3f3f3f3f)
//			puts("NO SOLUTION");
//		else
//			cout << t << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_map>
//#include <queue>
//#define x first
//#define y second
//using namespace std;
//using PII = pair<char, string>;
//// string 是由 PII中的string经过 char变化过来的
//unordered_map<string, PII> apre, bpre;
//
//// da表示从起点出发的字符串到起点的距离， db表示终点
//// 出发的字符串到终点的距离
//unordered_map<string, int>da, db;
//// 分别存储起点、终点出发的字符串
//queue<string> qa, qb;
//
//string start, en = "12345678x";
//
//
//int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//
//char ds[5] = {'u', 'r', 'd', 'l'}; // 上右下左
//string midtemp; // 中间值字符串
//int num = 0;
//
//int extend(queue<string> &q, unordered_map<string, int>& da, unordered_map<string, int>& db,
//           unordered_map<string, PII> &pre) {
//	// 只扩展一次
//	int dist = da[q.front()];
//	while (q.size() && da[q.front()] == dist) {
//		auto t = q.front();
//		q.pop();
//		int k = t.find('x');
//		int x = k / 3, y = k % 3;
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i], ny = y + dy[i];
//			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)  continue;
//			// 交换操作
//			swap(t[k], t[nx * 3 + ny]);
//			string r = t; // 交换后的string为r
//			swap(t[k], t[nx * 3 + ny]);
//			if (db.count(r))	{
//				midtemp = r; // 前后相遇了
//				// cout << r << endl;
//				pre[r] = {ds[i], t}; // 记得记录状态转移，不然获取不了上一个状态
//				return da[t] + 1 + db[r];
//			}
//			if (da.count(r))
//				continue;
//			da[r] = da[t] + 1;
//			pre[r] = {ds[i], t}; // r 是由 t转化而来的
//			q.push(r);
//		}
//	}
//	return -1;
//}
//
//int bfs(string A, string B) {
//	qa.push(A);
//	da[A] = 0;
//
//	qb.push(B);
//	db[B] = 0;
//	// 循环条件：qa qb都不空
//	while (qa.size() && qb.size()) {
//		if (num >= 100000) {
//		    return -1;
//		}
//		int t;
//		if (qa.size() <= qb.size()) {
//			t = extend(qa, da, db, apre);
//			num += qa.size();
//// 			cout << qa.size() << endl;
//		} else {
//			t = extend(qb, db, da, bpre);
//			num += qb.size();
//// 			cout << qb.size() << endl;
//		}
//		if (t != -1)
//			return t;
//	}
//	return -1;
//}
//
//int main() {
//	char c;
//	while (cin >> c)
//		start += c;
//	
//	int res = bfs(start, en);
//	if(res == -1)   cout << "unsolvable" << endl;
//	else {
//    	string res1, res2;
//    	string t1 = midtemp; // 拷贝中间字符串值
//    // 	cout << midtemp << endl;
//    // 	cout << start << " " << en << endl;
//    	int i = 0;
//    	while (t1 != start) {
//    		res1 += apre[t1].x;
//    		t1 = apre[t1].y; // 上一个状态
//    	}
//    	reverse(res1.begin(), res1.end());
//        string t2 = midtemp;
//    	while (t2 != en) {
//    		char aa = bpre[t2].x;
//    		// 方向要反过来
//    		if(aa == 'u' || aa == 'd')  aa = 'u' + 'd' - aa;
//    		else    aa = 'l' + 'r' - aa;
//    		res2 += aa;
//    		t2 = bpre[t2].y;
//    	}
//    	cout << res1 << res2 << endl;
//	}
//	return 0;
//}






