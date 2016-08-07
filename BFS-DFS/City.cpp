//作者：chenalong
//时间：2016-08-07
//题目来源：[Offer收割]编程练习赛4
//题目描述：某市市区由M条南北向的大街和N条东西向的道路组成。
//			其中由北向南第i条路和第i+1条路之间的距离是Bi (1 <= i < N)，
//			由西向东第i条街和第i+1条街之间的距离是Ai (1 <= i < M)。
//			小Ho现在位于第x条路和第y条街的交叉口，他的目的地是第p条路和第q条街的交叉口。
//			由于连日降雨，城市中有K个交叉口积水太深不能通行。小Ho想知道到达目的地的最短路径的长度是多少。
//********************************************************************************************************

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>

#define MAXN 100005
#define MAXM 100005
#define eps 1e-8

typedef long long LL;
using namespace std;

int dis[505][505];
int n, m;
int b[505], a[505];
map<pair<int, int>, int>water;
queue<pair<int, int> >que;
bool judge(int x, int y)
{
	if (1 <= x && x <= n && 1 <= y && y <= m)
	{
		if (water.find(make_pair(x, y)) != water.end())
			return false;
		return true;
	}
	return false;
}
void spfa(int start_x, int start_y, int end_x, int end_y)
{
	while (!que.empty())
		que.pop();
	//cout << n << m<<endl;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		dis[i][j] = 100000000;
	dis[start_x][start_y] = 0;
	que.push(make_pair(start_x, start_y));
	int x, y;
	while (!que.empty())
	{
		pair<int, int> tmp = que.front();
		que.pop();
		x = tmp.first + 1;
		y = tmp.second;
		if (judge(x, y))
		{
			if (dis[x][y] > dis[tmp.first][tmp.second] + b[tmp.first])
			{
				dis[x][y] = dis[tmp.first][tmp.second] + b[tmp.first];
				if (!(x == end_x && y == end_y))
					que.push(make_pair(x, y));
			}
		}

		x = tmp.first - 1;
		y = tmp.second;
		if (judge(x, y))
		{
			if (dis[x][y] > dis[tmp.first][tmp.second] + b[tmp.first - 1])
			{
				dis[x][y] = dis[tmp.first][tmp.second] + b[tmp.first - 1];
				if (!(x == end_x && y == end_y))
					que.push(make_pair(x, y));
			}
		}

		x = tmp.first;
		y = tmp.second + 1;
		if (judge(x, y))
		{
			if (dis[x][y] > dis[tmp.first][tmp.second] + a[tmp.second])
			{
				dis[x][y] = dis[tmp.first][tmp.second] + a[tmp.second];
				if (!(x == end_x && y == end_y))
					que.push(make_pair(x, y));
			}
		}

		x = tmp.first;
		y = tmp.second - 1;
		if (judge(x, y))
		{
			if (dis[x][y] > dis[tmp.first][tmp.second] + a[tmp.second - 1])
			{
				dis[x][y] = dis[tmp.first][tmp.second] + a[tmp.second - 1];
				if (!(x == end_x && y == end_y))
					que.push(make_pair(x, y));
			}
		}

	}


}
int main()
{
	cin >> n >> m;
	for (int i = 1; i<n; i++)
		cin >> b[i];
	for (int i = 1; i<m; i++)
		cin >> a[i];
	int Q, x, y, p, q, k;
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		cin >> x >> y;
		water[make_pair(x, y)] = 1;
	}
	cin >> Q;
	for (int i = 0; i<Q; i++)
	{
		cin >> x >> y >> p >> q;
		spfa(x, y, p, q);
		if (dis[p][q] >= 100000000)
			cout << -1 << endl;
		else
			cout << dis[p][q] << endl;
		/*
		for(int i = 1 ;i <= n;i++)
		{
		for(int j = 1;j<=m;j++)
		cout << dis[i][j] << ' ';
		cout << endl;
		}
		*/
	}

	return 0;
}
