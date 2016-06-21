//���ߣ����ٹ�
//ʱ�䣺2016-06-21
//������������С������֮Kruskal�㷨
//****************************************************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Edge
{
	int u; //�����ӵ�һ��������
	int v; //��������һ��������
	int w; //�ߵ�Ȩֵ
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w < E2.w;
	}
};
//�������鼯
void MakeSet(vector<int>& uset, int n)
{
	uset.assign(n, 0);
	for (int i = 0; i < n; i++)
		uset[i] = i;
}
//���ҵ�ǰԪ�����ڼ��ϵĴ���Ԫ
int FindSet(vector<int>& uset, int u)
{
	int i = u;
	while (uset[i] != i) i = uset[i];
	return i;
}
void Kruskal(const vector<Edge>& edges, int n)
{
	vector<int> uset;
	vector<Edge> SpanTree;
	int Cost = 0, e1, e2;
	MakeSet(uset, n);
	for (int i = 0; i < edges.size(); i++) //��Ȩֵ��С�����˳��ȡ��
	{
		e1 = FindSet(uset, edges[i].u);
		e2 = FindSet(uset, edges[i].v);
		if (e1 != e2) //����ǰ�����ӵ���������ڲ�ͬ�����У�ѡȡ�ñ߲��ϲ�����������
		{
			SpanTree.push_back(edges[i]);
			Cost += edges[i].w;
			uset[e1] = e2; //�ϲ���ǰ�����ӵ������������ڼ���
		}
	}
	cout << "Result:\n";
	cout << "Cost: " << Cost << endl;
	cout << "Edges:\n";
	for (int j = 0; j < SpanTree.size(); j++)
		cout << SpanTree[j].u << " " << SpanTree[j].v << " " << SpanTree[j].w << endl;
	cout << endl;
}
int main()
{
	ifstream in("data.txt");

	int n, m;
	in >> n >> m;
	vector<Edge> edges;
	edges.assign(m, Edge());
	for (int i = 0; i < m; i++)
		in >> edges[i].u >> edges[i].v >> edges[i].w;
	sort(edges.begin(), edges.end()); //����֮�󣬿����Ա�Ȩֵ��С�����˳��ѡȡ��
	Kruskal(edges, n);

	in.close();

	system("pause");
	return 0;
}