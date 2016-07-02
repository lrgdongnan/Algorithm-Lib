//作者：李荣贵
//时间：2016-07-02
//问题：实现哈夫曼编码

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#define PAIR pair<int,int>

struct Node
{
	char ch; //保存字符
	int freq; //保存字符出现频率
	int parent; //保存当前节点父节点所在位置的索引号
	char child; //'0'表示当前结点是左孩子，'1'表示当前结点是右孩子
};
struct Comp
{
	bool operator()(const PAIR& p1,const PAIR& p2)
	{
		return p1.first > p2.first;

	}
};
int main()
{
	ifstream in("data.txt");
	int n, f;
	char c;
	vector<Node> Record;
	priority_queue<PAIR,vector<PAIR>,Comp> Q; //最小优先队列，用于每次选择两个频率最小的节点合并
	in >> n;
	Record.assign(2 * n - 1, Node());
	for (int i = 0; i < n; i++)
	{
		in >> c >> f;
		Record[i].ch = c;
		Record[i].freq = f;
		Q.push(PAIR(f, i));
	}
	PAIR p, q;
	int k = n;
	while (Q.size()>1)
	{
		p = Q.top();
		Q.pop();
		q = Q.top();
		Q.pop();
		Q.push(PAIR(p.first + q.first, k));
		//Record[k].freq = p.first + q.first;
		Record[p.second].parent = k;
		Record[p.second].child = '0';
		Record[q.second].parent = k;
		Record[q.second].child = '1';
		k++;
	}
	Record[Q.top().second].parent = -1;
	string encode;
	for (int i = 0; i < n; i++)
	{
		cout << Record[i].ch << ": ";
		encode = "";
		int k = i;
		while (Record[k].parent != -1)
		{
			encode += Record[k].child;
			k = Record[k].parent;
		}
		reverse(encode.begin(), encode.end());
		cout << encode << endl;
	}

	system("pause");
	return 0;
}
