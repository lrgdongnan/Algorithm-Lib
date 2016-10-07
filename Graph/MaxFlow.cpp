//题目来源：杭电OJ-1532
//算法描述：构造图的残存网络，然后使用BFS算法寻找增广路径，并更新残存网络，循环寻找知道不存在残存网络为止；

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int Remain[201][201];
int Path[201];
int Flow[201];
int m;

int BFS()
{
	for (int i = 1; i <= m; i++) Path[i] = -1;
	queue<int> Q;
	Q.push(1);
	Flow[1] = INT_MAX;
	Path[1] = 1;
	int p;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		for (int i = 1; i <= m; i++)
		{
			if (Remain[p][i] > 0 && Path[i] == -1)
			{
				Q.push(i);
				Path[i] = p;
				Flow[i] = min(Flow[p], Remain[p][i]);
				if (i == m) return Flow[m];
			}
		}
	}
	return -1;
}
int MaxFlow()
{
	int ans = 0, f, pos, par;
	while ((f=BFS()) != -1)
	{
		ans += f;
		pos = m;
		while (pos != 1)
		{
			par = Path[pos];
			Remain[par][pos] -= f;
			Remain[pos][par] += f;
			pos = par;
		}
	}
	return ans;
}
int main()
{
	int n, u, v, c;
	while (cin >> n >> m)
	{
		memset(Remain, 0, sizeof(Remain));
		for (int i = 0; i < n; i++)
		{
			cin >> u >> v >> c;
			Remain[u][v] += c;
		}
		cout << MaxFlow() << endl;
	}

	return 0;
}

