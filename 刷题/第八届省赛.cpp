//UDDLUULRUL
//UURLLLRRRU
//RRUURLDLRD
//RUDDDDUUUU
//URUDLLRRUU
//DURLRLDLRL
//ULLURLLRDU
//RDLULLRDDD
//UUDDUDUDLL
//ULRDLUURRR
// รินฌ 
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 10;
//string s = "UDDLUULRULUURLLLRRRURRUURLDLRDRUDDDDUUUUURUDLLRRUUDURLRLDLRLULLURLLRDURDLULLRDDDUUDDUDUDLLULRDLUURRR";
//char g[N][N];
//bool st[N][N];

//bool dfs(int x, int y) {
//	if(x < 0 || x >= 10 || y < 0 || y >= 10)	return true;
//	if(st[x][y])	return false;
//	st[x][y] = true;
//	if(g[x][y] == 'L') {
//		return dfs(x, y-1);
//	}else if(g[x][y] == 'U') {
//		return dfs(x - 1, y);
//	}else if(g[x][y] == 'R') {
//		return dfs(x, y + 1);
//	}else if(g[x][y] == 'D') {
//		return dfs(x + 1, y);
//	}
//	st[x][y] = false;
//}

//int main() {
//	for(int i = 0; i < 10; i++){
//		for(int j = 0; j < 10;j++) {
//			g[i][j] = s[i * 10 + j];
//			cout << g[i][j] << " ";
//		}
//		cout << endl; 
//	}
//	int ans = 0;
//	for(int i = 0; i < 10; i++)
//		for(int j = 0; j < 10; j++) {
//			memset(st, 0, sizeof st);
//			if(dfs(i, j))	ans++;
//		}
//	cout << ans << endl;
//			
//	return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;
const int N = 7;
int ans;
bool st[N][N];

void dfs(int x, int y) {
	if(st[x][y])	
	if(x <= 0 || x >= 6 || y <= 0 || y >= 6)	{
		ans++;
		return;
	} 
	st[x][y] = true;
	st[6 - x][6 - y] = true;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	st[x][y] = false;
	st[6 - x][6 - y] = false;
}


int main() {
	dfs(3,3);
	cout << ans / 4<< endl;
	return 0;
}
