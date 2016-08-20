//题目：凸多边形
//题目来源：hihoCoder之[Offer收割]编程练习赛5-4
//题目描述：
//	给定一个凸多边形的N个顶点。你需要在凸多边形内找到M个点，使得这M个点也围成一个凸多边形，并且围成的面积尽可能大。
//******************************************************************************************************************

#include<iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define N 110
int a[N], b[N];
int n, m, k;

struct P{
	int x, y;
}p[110];
double dp[N][N][N], t[N][N][N];


int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i<n; i++)
			cin >> p[i].x >> p[i].y;
		for (int i = 0; i<n; i++)
			dp[i][i][1] = 0;
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		for (int k = 0; k<n; k++)
			dp[i][j][k] = 0;
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		for (int k = 0; k<n; k++)
			// (1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
			t[i][j][k] = 0.5*abs(p[i].x*p[j].y + p[j].x*p[k].y + p[k].x*p[i].y - p[i].x*p[k].y - p[j].x*p[i].y - p[k].x*p[j].y);
		for (int k = 3; k <= m; k++)
		for (int i = 0; i<n; i++)
		for (int j = (i + 1); j != i; j = (j + 1) % n){
			for (int u = (i + 1); u != j; u = (u + 1) % n)
				dp[i][j][k] = max(dp[i][j][k], dp[i][u][k - 1] + t[i][u][j]);
		}
		double ans = 0;
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			ans = max(ans, dp[i][j][m]);
		printf("%.2lf\n", ans);
		//  cout<<ans<<endl;

	}
	return 0;
}
/*
a1b2a1
*/
