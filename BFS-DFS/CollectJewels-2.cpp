//作者：李荣贵
//时间：2016-07-27
//题目来源：杭电OJ-1044
//题目简介：BFS+DFS的应用
//*********************************************************************************************

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int W, H, L, M, ans, sum;
char dun[55][55];
int jew[15];
bool isVisited[55][55];
int Graph[15][15];
bool isUsed[15];

struct State
{
	int x, y;
	int time;
	State(int a, int b, int c) :x(a), y(b), time(c){}
};
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{
	memset(isVisited, 0, sizeof(isVisited));
	char ch = dun[x][y];
	int u;
	if(ch=='@') u=0;
	else if (ch >= 'A') u = ch - 'A' + 1;
	State pos(0, 0, 0), nextpos(0, 0, 0);
	queue<State> Q;
	isVisited[x][y] = true;
	Q.push(State(x, y, 0));
	while (!Q.empty())
	{
		pos = Q.front();
		Q.pop();
		if (pos.time == L) break;
		for (int i = 0; i < 4; i++)
		{
			nextpos.x = pos.x + dx[i];
			nextpos.y = pos.y + dy[i];
			nextpos.time = pos.time + 1;
			if (nextpos.x < 0 || nextpos.x >= H ||
				nextpos.y < 0 || nextpos.y >= W) continue;
			if (dun[nextpos.x][nextpos.y] == '*' || isVisited[nextpos.x][nextpos.y])
				continue;
			isVisited[nextpos.x][nextpos.y] = true;
			char ch = dun[nextpos.x][nextpos.y];
			if (ch == '@')
			{
				Graph[u][0] = Graph[0][u] = nextpos.time;
			}
			else if (ch >= 'A' && ch <= 'J')
			{
				int v = ch - 'A' + 1;
				Graph[u][v] = Graph[v][u] = nextpos.time;
			}
			else if (ch == '<')
			{
				Graph[u][M + 1] = Graph[M + 1][u] = nextpos.time;
			}
			Q.push(nextpos);
		}
	}
}

void DFS(int pos, int Time, int je)
{
	if (Time > L) return;
	if(ans==sum) return;
	if (pos == M + 1)
	{
		if (je > ans) ans = je;
		return;
	}
	
	for (int i = 1; i < M + 2; i++)
	{
		if (isUsed[i] || Graph[pos][i] == 0) continue;
		
		isUsed[i] = true;
		DFS(i, Time + Graph[pos][i], je + jew[i]);
		isUsed[i] = false;
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> W >> H >> L >> M;
		sum=0;
		for (int j = 1; j <= M; j++)
		{
			cin >> jew[j];
			sum+=jew[j];
		}
		jew[0]=jew[M+1]=0;
		for (int i = 0; i < H; i++)
			cin >> dun[i];
		memset(Graph,0,sizeof(Graph));
		for (int i = 0; i < H;i++)
		for (int j = 0; j < W; j++)
		{
			if (dun[i][j] == '@' || (dun[i][j] >= 'A' && dun[i][j] <= 'J'))
				BFS(i, j);
		}
		memset(isUsed, 0, sizeof(isUsed));
		isUsed[0]=true;
		ans = -1;
		DFS(0, 0, 0);
		cout<<"Case "<<i<<":\n";
		if (ans == -1) cout << "Impossible\n";
		else cout << "The best score is " << ans << ".\n";
		if (i != T) cout << endl;
		
	}

	return 0;
}
