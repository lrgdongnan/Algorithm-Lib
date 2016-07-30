//作者：李荣贵
//时间：2016-07-30
//题目来源：hihoCoder太阁最新面经算法竞赛10-C
//*****************************************************************************

#include <iostream>
using namespace std;

char grid[1000][1001];
int uset[1000000];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int findU(int x, int y)
{
	int p = x * 1000 + y;
	while (uset[p] != p) p = uset[p];
	return p;
}
int main()
{
	int n, x, y, islands = 0, u, v;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		grid[x][y] = '#';
		islands++;
		u = 1000 * x + y;
		uset[u] = u;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (grid[xx][yy] != '#') continue;
			v = findU(xx, yy);
			if (u != v)
			{
				islands--;
				uset[u] = v;
				u = v;
			}
		}
		cout << islands << endl;
	}

	system("pause");
	return 0;
}