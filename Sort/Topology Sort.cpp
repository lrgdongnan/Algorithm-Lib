//作者：李荣贵
//时间：2016-06-21
//问题描述：
//    第一行输入两个整数n和m，n表示途中节点数，m表示途中边数；接下来输入m行，每一行有两个整数v1和v2，
//    v1和v2分别代表编号为v1、v2的节点，每行代表一条由v1指向v2的边（节点编号从0开始）；若途中存在环，
//    给出提示；否则输出拓扑排序后的序列；
//****************************************************************************************************

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> Adj; //邻接表
vector<int> inDegree; //保存每个节点的入度
stack<int> stk; //保存当前入度为0的节点编号

void CreatGraph()
{
	int n, m, v1, v2;
	cin >> n >> m;
	Adj.assign(n, list<int>());
	inDegree.assign(n, 0);
	while (m--)
	{
		cin >> v1 >> v2;
		Adj[v1].push_back(v2);
		inDegree[v2]++;
	}
	for (int i = 0; i < n; i++)
	if (inDegree[i] == 0) stk.push(i);
}
void tpSort()
{
	vector<int> vec;
	int v;
	while (!stk.empty())
	{
		v = stk.top();
		stk.pop();
		//inDegree[v] = -1;
		//遍历与节点v相连的节点
		for (auto it = Adj[v].begin(); it != Adj[v].end(); it++)
		{
			inDegree[*it]--;
			if (inDegree[*it] == 0) stk.push(*it);
		}
		//Adj[v].clear(); //本行可以省略，以提升程序效率
		vec.push_back(v);
	}
	if (vec.size() != inDegree.size())
	{
		cout << "图中存在环路，不能进行拓扑排序！\n";
		return;
	}
	for (auto item : vec)
		cout << item << " ";
	cout << endl;
}
int main()
{
	CreatGraph();
	tpSort();

	system("pause");
	return 0;
}
