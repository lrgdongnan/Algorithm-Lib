//���ߣ����ٹ�
//ʱ�䣺2016-07-02
//���⣺ʵ�ֹ���������

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#define PAIR pair<int,int>

struct Node
{
	char ch; //�����ַ�
	int freq; //�����ַ�����Ƶ��
	int parent; //���浱ǰ�ڵ㸸�ڵ�����λ�õ�������
	char child; //'0'��ʾ��ǰ��������ӣ�'1'��ʾ��ǰ������Һ���
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
	priority_queue<PAIR,vector<PAIR>,Comp> Q; //��С���ȶ��У�����ÿ��ѡ������Ƶ����С�Ľڵ�ϲ�
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
		Record[p.second].parent = k;
		Record[p.second].child = '0';
		Record[q.second].parent = k;
		Record[q.second].child = '1';
		//Record[p.second].freq = p.first + q.first;
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