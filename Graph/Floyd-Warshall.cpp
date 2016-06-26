//作者：李荣贵
//时间：2016-06-26
//--寻找最短路径之Floyd-Warshall算法

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Info
{
	int cost; //当前结点到起始节点的最短路径代价
	int pre; //当前结点的前驱节点
	Info(){ cost = INT_MAX; pre = -1; }
};
vector<vector<Info>> Path[2]; //存储每个节点对的路径信息，矩阵的行索引表示起始节点，列索引表示终止节点
//其中使用的树的双亲表示法的思想
//由于该算法在迭代过程中不能原地操作，所以此处使用了两个矩阵，迭代过程中不断切换，从而避免了
//每次迭代时进行矩阵复制

int Floyd()
{
	int n = Path[0].size();
	int flag = 0, flag1;
	for (int k = 0; k < n; k++)
	{
		flag1 = flag;
		flag = (flag + 1) % 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Path[flag1][i][k].cost == INT_MAX || Path[flag1][k][j].cost==INT_MAX ||
					Path[flag1][i][j].cost <= Path[flag1][i][k].cost + Path[flag1][k][j].cost)
				{
					Path[flag][i][j] = Path[flag1][i][j];
				}
				else
				{
					Path[flag][i][j].cost = Path[flag1][i][k].cost + Path[flag1][k][j].cost;
					Path[flag][i][j].pre = Path[flag1][k][j].pre;
				}
			}
		}
	}
	return flag;
}
void Print(vector<vector<Info>>& Path)
{
	int n = Path.size();
	cout << "Result:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "From " << i << " to " << j << ": " << Path[i][j].cost << endl;
	}
	cout << endl;
}
int main()
{
	int n, m, u, v, w;
	ifstream in("data.txt"); //从文件中读取图的信息
	in >> n >> m; //n表示途中节点的个数，m表示图中边的条数
	Path[0].assign(n, vector<Info>(n, Info()));
	while (m--)
	{
		in >> u >> v >> w;
		Path[0][u][v].cost = w;
		Path[0][u][v].pre = u;
	}
	for (int i = 0; i < n; i++)
		Path[0][i][i].cost = 0;
	Path[1] = Path[0];

	int nu=Floyd();
	Print(Path[nu]);

	system("pause");
	return 0;
}