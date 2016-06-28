//���ߣ�totoday
//ʱ�䣺2016-06-28
//��Ŀ��Դ��hihoCoder̫�������澭�㷨����5-3
//������
//СHi�������� N �� M ��������ɵľ����Թ��С�Ϊ���������㣬���ǰ����Ͻǵķ�������궨Ϊ(0, 0),���½Ƿ�������궨Ϊ
//(N-1, M-1)��ÿ�����������3��״̬֮һ�����ŵġ��رյġ����������ġ����ŷ�����'.'��ʾ��СHi���Դ�һ�����ŷ��䵽��
//��һ�����ڵ�(��������)���ŷ��䡣�رշ�����'#'��ʾ��СHi��Զ���ܽ���һ���رյķ��䡣�����ķ����ô�д��ĸ('A', 'B',
// 'C' ...)��ʾ��СHi��ȡ����Ӧ��Կ��ǰ���ܽ��������ķ��䣬��һ��ȡ��Կ�׾Ϳ��Է������������ķ��䡣ÿ�������������
//��ͬ�ģ���Ӧ��Կ�����Թ��е�ĳһ�����СHi����÷���Ϳ���ȡ��Կ�ס�СHiһ��ʼ����һ�����ŷ��䣬����(a, b)����
//���ĳ�����һ�����Ż��������ķ��䣬����(c, d)������СHiÿ�ƶ���һ�����ڷ�����Ҫ���ѵ�λ1��ʱ�䣬��ôСHi���������
//����Ҫ���Ѷ���ʱ�䣿
//���룺
//��һ�а���7������: N , M , K , a , b , c , d . ����N , M�Ǿ������������K �������ķ�����Ŀ��(a, b)����ʼλ�ã�
//(c, d)�ǳ���λ�á�(1 �� N, M �� 100, 0 �� K �� 5, 0 �� a, c < N, 0 �� b, d < M)���� N ��ÿ�а��� M ���ַ�����ʾ�Թ�����
//������ K ��ÿ���������� x, y�����α�ʾ��������A , B , C ....��Կ�����ڷ������ꡣ(0 �� x < N, 0 �� y < M) 
//�����
//���������ڵ����ʱ�䡣���СHi��Զ���ﲻ�˳��ڣ����-1��
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
	int x, y, z, d; //x,y�ֱ��ʾ��ǰλ�õ����꣬
	//��z�е�λ����¼�ߵ���ǰλ�û�ȡ��Կ�ף�d��ʾ��ǰ���굽����������̾���
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








