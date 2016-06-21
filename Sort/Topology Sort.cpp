//���ߣ����ٹ�
//ʱ�䣺2016-06-21
//����������
//    ��һ��������������n��m��n��ʾ;�нڵ�����m��ʾ;�б���������������m�У�ÿһ������������v1��v2��
//    v1��v2�ֱ������Ϊv1��v2�Ľڵ㣬ÿ�д���һ����v1ָ��v2�ıߣ��ڵ��Ŵ�0��ʼ������;�д��ڻ���
//    ������ʾ����������������������У�
//****************************************************************************************************

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> Adj; //�ڽӱ�
vector<int> inDegree; //����ÿ���ڵ�����
stack<int> stk; //���浱ǰ���Ϊ0�Ľڵ���

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
		//������ڵ�v�����Ľڵ�
		for (auto it = Adj[v].begin(); it != Adj[v].end(); it++)
		{
			inDegree[*it]--;
			if (inDegree[*it] == 0) stk.push(*it);
		}
		//Adj[v].clear(); //���п���ʡ�ԣ�����������Ч��
		vec.push_back(v);
	}
	if (vec.size() != inDegree.size())
	{
		cout << "ͼ�д��ڻ�·�����ܽ�����������\n";
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
