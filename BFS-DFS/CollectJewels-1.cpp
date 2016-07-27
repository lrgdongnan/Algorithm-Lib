//作者：李荣贵
//时间：2016-07-27
//题目来源：杭电OJ-1044
//题目简介：BFS的应用
//************************************************************

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int W, H, L, M;
char dun[55][55]; //保存地下城地图
int jew[10]; //保存每个珠宝的价值
bool isVisited[1024][55][55]; //记录BFS过程中某个位置是否经过
//结构体保存每到一个位置时的信息
struct State
{
	int J, x, y;
	int jews, time;
};
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int CollectJewels()
{
	memset(isVisited, 0, sizeof(isVisited));
	State begin, pos, nextpos;
	for (int i = 0; i < H; i++)
	{
		int j;
		for (j = 0; j < W; j++)
		if (dun[i][j] == '@')
		{
			begin.x = i;
			begin.y = j;
			break;
		}
		if (j != W) break;
	}
	begin.J = begin.jews = begin.time = 0;
	isVisited[0][begin.x][begin.y] = true;
	queue<State> Q;
	Q.push(begin);
	int res = -1;
	while (!Q.empty())
	{
		pos = Q.front();
		Q.pop();
		if (pos.time == L) break; //优化操作，如果当前位置的时间已经达到
		//L，那么队列后面位置的时间一定>=L，可终止遍历
		int i;
		for (i = 0; i < 4; i++)
		{
			nextpos = pos;
			nextpos.x += dx[i];
			nextpos.y += dy[i];
			nextpos.time++;
			if(nextpos.x<0 || nextpos.x>=H ||
			nextpos.y<0 || nextpos.y>=W) continue;
			char ch = dun[nextpos.x][nextpos.y];
			if (ch == '*' || isVisited[nextpos.J][nextpos.x][nextpos.y])
				continue;
			isVisited[nextpos.J][nextpos.x][nextpos.y] = true;
			if (ch >= 'A' && ch <= 'J')
			{
				int t = ch - 'A';
				//如果当前位置的珠宝还在，取之
				if (!(nextpos.J & (1 << t)))
				{
					nextpos.jews += jew[t];
					nextpos.J |= (1 << t);
					isVisited[nextpos.J][nextpos.x][nextpos.y] = true;
				}
			}
			else if (ch == '<')
			{
				res = max(res, nextpos.jews);
				//优化操作，如果某种方案可以取得城内所有珠宝，则可以停止
				//尝试其他方案
				if (nextpos.J == ((1 << M) - 1)) break;
				else continue;
			}
			Q.push(nextpos);
		}
		if(i!=4) break;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> W >> H >> L >> M;
		for (int j = 0; j < M; j++)
			cin >> jew[j];
		for (int j = 0; j < H; j++)
			cin >> dun[j];
		int res = CollectJewels();
		cout << "Case " << i << ":\n";
		if (res == -1) cout << "Impossible\n";
		else cout << "The best score is " << res << ".\n";
		if (i != T) cout << endl;
	}

	return 0;
}
