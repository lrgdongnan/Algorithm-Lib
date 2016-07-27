//作者：totoday
//时间：2016-06-28
//题目来源：hihoCoder太阁最新面经算法竞赛5-3
//描述：
//小Hi正处在由 N × M 个房间组成的矩阵迷宫中。为了描述方便，我们把左上角的房间的坐标定为(0, 0),右下角房间的坐标定为
//(N-1, M-1)。每个房间可能是3种状态之一：开放的、关闭的、或者上锁的。开放房间用'.'表示。小Hi可以从一个开放房间到达
//另一个相邻的(上下左右)开放房间。关闭房间用'#'表示。小Hi永远不能进入一个关闭的房间。上锁的房间用大写字母('A', 'B',
// 'C' ...)表示。小Hi在取得相应的钥匙前不能进入上锁的房间，而一旦取得钥匙就可以反复进入上锁的房间。每个房间的锁都是
//不同的，相应的钥匙在迷宫中的某一房间里，小Hi进入该房间就可以取得钥匙。小Hi一开始处于一个开放房间，坐标(a, b)。迷
//宫的出口是一个开放或者上锁的房间，坐标(c, d)。假设小Hi每移动到一个相邻房间需要花费单位1的时间，那么小Hi到达出口最
//少需要花费多少时间？
//输入：
//第一行包含7个整数: N , M , K , a , b , c , d . 其中N , M是矩阵的行列数；K 是上锁的房间数目，(a, b)是起始位置，
//(c, d)是出口位置。(1 ≤ N, M ≤ 100, 0 ≤ K ≤ 5, 0 ≤ a, c < N, 0 ≤ b, d < M)以下 N 行每行包含 M 个字符，表示迷宫矩阵。
//再以下 K 行每行两个整数 x, y，依次表示上锁房间A , B , C ....的钥匙所在房间坐标。(0 ≤ x < N, 0 ≤ y < M) 
//输出：
//输出到达出口的最短时间。如果小Hi永远到达不了出口，输出-1。
//-------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include <fstream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
struct Item
{
	int x, y, z, d; //x,y分别表示当前位置的坐标，
	//用z中的位来记录走到当前位置获取的钥匙，d表示当前坐标到起点坐标的最短距离
	Item(int a1, int a2, int a3, int a4) :x(a1), y(a2), z(a3), d(a4){}
};

int n, m, k, sx, sy, ex, ey;
vector<string> maze;
vector<vector<bool>> vis[32];
map<pair<int, int>, int> mp;

bool check(int x, int y, int z){
	if (!(0 <= x && x < n && 0 <= y && y < m))return false;
	if (maze[x][y] == '#' || vis[z][x][y]) return false;
	if (maze[x][y] != '.' && (z&(1 << (maze[x][y] - 'A'))) == 0) return false;
	return true;
}

int main()
{
	ifstream in("data.txt");
	in >> n >> m >> k >> sx >> sy >> ex >> ey;
	maze.assign(n, "");
	//for (int i = 0; i < 32; i++) vis[i].assign(n, vector<bool>(m, false));
	vis[0].assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) in >> maze[i];
	for (int i = 0; i < k; i++){
		int x, y;
		in >> x >> y;
		mp[pair<int, int>(x, y)] = i;
	}

	queue<Item> q;
	q.push(Item(sx, sy, 0, 0));
	vis[0][sx][sy] = true;
	int ans = -1;
	while (!q.empty()){
		Item now = q.front(); q.pop();
		int x = now.x, y = now.y, z = now.z, d = now.d;
		int i;
		for (i = 0; i < 4; i++){
			int xx = x + dx[i], yy = y + dy[i], zz = z, dd = d + 1;
			if (!check(xx, yy, zz)) continue;
			if (mp.count(pair<int, int>(xx, yy)))
			{
				zz |= (1 << mp[pair<int, int>(xx, yy)]);
				vis[zz].assign(n, vector<bool>(m, false));
			}
			q.push(Item(xx, yy, zz, dd));
			vis[zz][xx][yy] = true;
			if (xx == ex && yy == ey) {
				ans = dd;
				break;
			}
		}
		if (i != 4) break;
	}
	cout << ans << endl;

	system("pause");
	return 0;
}

