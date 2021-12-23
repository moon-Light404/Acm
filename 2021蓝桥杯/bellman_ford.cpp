#include <iostream>
using namespace std;
const int M = 1000;
const int N = 1000;

int n, m;       // n��ʾ������m��ʾ����
int dist[N];        // dist[x]�洢1��x�����·����
int backup[N]; // ��������,�����ͱ�֤���������һ��
struct Edge {   // �ߣ�a��ʾ���㣬b��ʾ��㣬w��ʾ�ߵ�Ȩ��
	int a, b, w;
} edges[M];

// ��1��n�����·���룬����޷���1�ߵ�n���򷵻�-1��
int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	// ��ʼʱ��1�ŵ㵽������ľ���Ϊinf
	dist[1] = 0;

	// �����n�ε�����Ȼ���ɳ����ǲ���ʽ����˵������һ��������n+1�����·�����ɳ���ԭ��·�������ٴ���������ͬ�ĵ㣬˵��ͼ�д��ڸ�Ȩ��·��
	for (int i = 0; i < n; i ++ ) {
		memcpy(backup, dist, sizeof dist); // ��������,��Ϊ����������ʱ���Ӱ��������ĸ�����Ϣ
		for (int j = 0; j < m; j ++ ) { // ����ÿ���߱�
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			if (dist[b] > backup[a] + w)
				dist[b] = backup[a] + w;
		}
		for (int k = 1; k <= n; k++)
			cout << dist[k] << "   ";
		cout << endl;
	}

	if (dist[n] > 0x3f3f3f3f / 2)
		return -1;
	return dist[n];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w}; // ����һ����
	}
	bellman_ford();
	return 0;
	/*���
	5 8
	1 2 -1
	1 3 4
	2 5 2
	2 4 2
	4 2 1
	5 4 -3
	4 3 5
	2 3 3
	0   -1   4   1061109564   1061109567
	0   -1   2   1   1
	0   -1   2   -2   1
	0   -1   2   -2   1
	0   -1   2   -2   1
	*/
}
