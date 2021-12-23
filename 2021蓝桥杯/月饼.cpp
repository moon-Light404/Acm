// 月饼
#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1010;

struct Cake {
	double s; // 存量
	double w, avg; // 单价平均值
} cake[N];

bool cmp(Cake a, Cake b) {
	return a.avg > b.avg;
}
double D = 0; // 需求量

int n;
double sa[N], wa[N];

int main() {
	cin >> n >> D;
	for (int i = 1; i <= n; i++) {
		cin >> cake[i].s;
	}
	for (int i = 1; i <= n; i++)	{
		cin >> cake[i].w;
		cake[i].avg = cake[i].w / cake[i].s;
	}
	sort(cake + 1, cake + n + 1, cmp);
	int cnt = 1;
	double prof = 0.0; // 收益
	while (D > 0) {
		if (D - cake[cnt].s >= 0) {
			prof += cake[cnt].w;
			D -= cake[cnt].s;
			cnt++;
		} else  {
			prof += D * cake[cnt].avg;
			break;
		}
	}
	printf("%.2lf", prof);
	return 0;
}