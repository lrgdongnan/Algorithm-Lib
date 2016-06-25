//���ߣ����ٹ�
//ʱ�䣺2016-06-25
//--Ѱ�����·��֮Dijkstra�㷨
//***********************************************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;
//�ڽӱ��нڵ㣬ÿ���ڵ���ýڵ��Ӧ��������ָ��һ����
struct Node
{
	int u; //���յ�ڵ��
	int w; //��Ȩֵ
	Node(int a, int b) :u(a), w(b){}
};
struct Record
{
	int pre; //·���е�ǰ�ڵ��ǰһ�ڵ�
	int cost; //��ǰ�ڵ㵽Դ�ڵ�����·������
};
int n, m, s; //n��ʾͼ�нڵ������m��ʾͼ�б�����s��ʾԴ�ڵ�
vector<list<Node>> Adj; //ͼ���ڽӱ�
vector<Record> Path; //����˫�ױ�ʾ���洢Դ�ڵ㵽�������нڵ�����·����Ϣ
void Dijkstra()
{	
	vector<bool> isUsed(n, false); //����ĳ�����Ŷ�Ӧ��ֵΪtrue����ʾ�������Ŷ�Ӧ�Ľڵ�
	//��S������
	list<int> Assi; //Assi�д洢�ŵ�ǰ�ĺ�ѡ�ڵ�
	Path.assign(n, Record());
	//·����Ϣ��ʼ��
	for (int i = 0; i < n; i++)
	{
		Path[i].pre = i;
		Path[i].cost = INT_MAX;
	}
	isUsed[s] = true;
	for (auto it = Adj[s].begin(); it != Adj[s].end(); it++)
	{
		Path[it->u].pre = s;
		Path[it->u].cost = it->w;
		Assi.push_back(it->u);
	}
	while (!Assi.empty())
	{
		list<int>::iterator It;
		int minCost = INT_MAX;
		//��Assi��ѡ�������С�Ľڵ���뵽S������
		for (auto it = Assi.begin(); it != Assi.end(); it++)
		{
			if (minCost > Path[*it].cost)
			{
				minCost = Path[*it].cost;
				It = it;
			}
		}
		int u = *It;
		Assi.erase(It);
		isUsed[u] = true;
		//����ѡ�нڵ�ֱ�����������Ҳ���S�����еĽڵ�����ɳڲ���
		//ͬʱ����Assi������
		for (auto it = Adj[u].begin(); it != Adj[u].end(); it++)
		{
			if (isUsed[it->u]) continue;
			if (Path[it->u].cost == INT_MAX) Assi.push_back(it->u);
			if (Path[it->u].cost > minCost + it->w)
			{
				Path[it->u].cost = minCost + it->w;
				Path[it->u].pre = u;
			}
		}
	}
}
void Traverse(int k)
{
	if (Path[k].pre == k) { cout << k; return; }
	Traverse(Path[k].pre);
	cout << " " << k;
}
void Print()
{
	cout << "Result:\n";
	for (int i = 0; i < n; i++)
	{
		if (i == s) continue;
		cout << "From " << s << " to " << i << ": ";
		if (Path[i].cost == INT_MAX){ cout << "No path\n\n"; continue; }
		Traverse(i);
		cout << endl;
		cout << "Minimal Cost: " << Path[i].cost << endl << endl;
	}
}
int main()
{
	ifstream in("data.txt"); //���ļ��ж�ȡͼ����Ϣ
	in >> n >> m >> s;
	int u, v, w;
	Adj.assign(n, list<Node>());
	while (m--)
	{
		in >> u >> v >> w;
		Adj[u].push_back(Node(v, w));
	}
	in.close();

	Dijkstra();
	Print();

	system("pause");
	return 0;
}