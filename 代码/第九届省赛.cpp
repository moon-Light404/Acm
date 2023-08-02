// 星期一 
//#include<iostream>
//using namespace std;

//bool is_leap(int year) {
//	return year % 400 == 0 || year % 4 == 0 && year % 100;
//}
//int main() {
//	int res = 0;
//	for(int i = 1901; i <= 2000; i++) {
//		res += 365;
//		if(is_leap(i))	res++;
//	}
//	int k = res % 7;
//	cout << k << " " << res / 7 << endl; 
//	return 0;
//}

// 乘积尾0 
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[100] = {
//5650, 4542, 3554, 473, 946, 4114, 3871, 9073, 90, 4329,
//2758, 7949, 6113, 5659, 5245, 7432, 3051, 4434, 6704, 3594,
//9937, 1173, 6866, 3397, 4759, 7557, 3070, 2287, 1453, 9899,
//1486, 5722, 3135, 1170, 4014, 5510, 5120, 729, 2880, 9019,
//2049, 698, 4582, 4346, 4427, 646, 9742, 7340, 1230, 7683,
//5693, 7015, 6887, 7381, 4172, 4341, 2909, 2027, 7355, 5649,
//6701, 6645, 1671, 5978, 2704, 9926, 295, 3125, 3878, 6785,
//2066, 4247, 4800, 1578, 6652, 4616, 1113, 6205, 3264, 2915,
//3966, 5291, 2904, 1285, 2193, 1428, 2265, 8730, 9436, 7074,
//689, 5510, 8243, 6114, 337, 4096, 8199, 7313, 3685, 211
//};

//int main() {
//	int res2 = 0, res5 = 0;
//	for(int i = 0; i < 100; i++) {
//		int x = a[i];
//		while(x % 2 == 0) {
//			x /= 2;
//			res2++;
//		}
//		while(x % 5 == 0) {
//			x /= 5;
//			res5++;
//		}
//	}
//	cout << min(res2, res5) << endl;
//	return 0;
//}

// 分数: 答案1048575/524288 
//#include<iostream>
//using namespace std;
//const int N = 1 << 19;
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;	
//}

//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}

//int main() {
//	int fenzi = 0;
//	for(int i = 1, j = 1; i <= 20; i++, j *= 2) {
//		fenzi += N / j;
//	}
//	int t = gcd(fenzi, N);
//	cout << fenzi / t << "/"<<N/t << endl;
//	return 0;
//}


// 第几个幸运数
#include <iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;
map<LL, int> mp;
int cnt;
LL maxn = 59084709587505;

int main() {
	priority_queue<LL, vector<LL>, greater<LL>> q;
	q.push(1);
	while(1) {
		LL t = q.top();
		q.pop();
		
		if(t == maxn)	{
			cout << cnt << endl;
			break;
		}
		LL tmp = t * 3;
		if(mp[tmp] == 0) {
			q.push(tmp);	
			mp[tmp] = 1;
		}
		tmp = t * 5;
		if(mp[tmp] == 0) {
			q.push(tmp);	
			mp[tmp] = 1;
		}
		tmp = t * 7;
		if(mp[tmp] == 0) {
			q.push(tmp);	
			mp[tmp] = 1;
		}
		cnt++;
	}
	
	return 0;
}
 
