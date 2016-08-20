//��Ŀ�����ʽ���
//��Ŀ������
//	��ķ�տ�ʼѧϰӢ�ĵ��ʣ��Ե�������ܸ���Ȥ��
//	�������ķһ�鵥�ʣ����ܹ�Ѹ��ȷ���Ƿ���Խ���Щ����������һ���б��У�ʹ�ø��б����κε��ʵ�����ĸ��ǰһ���ʵ�Ϊ��ĸ��ͬ��
//	���ܱ�дһ��������������ķ�����ж���
//����˼·��
//	�����ʽ���һ��ͼ��ȡ��ÿ�����ʵĵ�һ����ĸ�����һ����ĸ����һ������ߣ��������ת��Ϊһ��ŷ��ͨ·���⡣
//	Ȼ�����ŷ�������ж��Ƿ����ͨ·��
//	1.ͼ��ͨ��
//	2.��2���˵�������ڵ����=���ȣ�1���˵���ȱȳ��ȴ�1��һ���˵���ȱȳ���С1 �� ���нڵ���ȵ��ڳ��ȣ�
//����֪ʶ��
//	ŷ��ͨ·: ͨ��ͼ��ÿ������ֻͨ��һ�Σ����Ҿ���ÿһ�����ͨ·��
//	ŷ����·: ͨ��ͼ��ÿ������ֻͨ��һ�Σ����Ҿ���ÿһ����Ļ�·��

//	����ͼ�Ƿ����ŷ��ͨ·���·���ж�:
//		ŷ��ͨ·:ͼ��ͨ��ͼ��ֻ��0����2����Ϊ�����Ľڵ�
//		ŷ����·:ͼ��ͨ��ͼ�����нڵ�Ⱦ�Ϊż��

//	����ͼ�Ƿ����ŷ��ͨ·���·���ж�:
//		ŷ��ͨ·:ͼ��ͨ����2���˵�������ڵ����=���ȣ�1���˵���ȱȳ��ȴ�1��һ���˵���ȱȳ���С1 
//			�� ���нڵ���ȵ��ڳ���
//		ŷ����·:ͼ��ͨ�����нڵ���ȵ��ڳ���
//********************************************************************************************************************************

#include<iostream> 
#include<string> 
#include<algorithm> 
#include<string.h> 
#include<queue> 
using namespace std;

char str[300];
int g[30][30];
int In[30];
int Out[30];
int num[30];

void init()
{
	memset(g, 0, sizeof(g));
	memset(In, 0, sizeof(In));
	memset(Out, 0, sizeof(Out));
	memset(num, 0, sizeof(num));
}

bool bfs(int s, int n)
{
	queue <int> q;
	q.push(s);
	int mark[30];

	memset(mark, 0, sizeof(mark));
	while (!q.empty())
	{
		int front = q.front();
		mark[front] = 1;
		q.pop();
		for (int i = 0; i < 30; i++)
		{
			if (g[front][i] && mark[i] == 0)
			{
				g[front][i] = 0;
				q.push(i);
			}
		}
	}
	int ha = 0;
	for (int i = 0; i < 30; i++)
	if (mark[i]) ha++;

	if (ha == n
		return true;
	return false;
}


int main()
{
	int n, s;

	//freopen("data.txt", "r", stdin); 

	while (cin >> n)
	{
		init();
		bool temp = true;
		for (int i = 0; i < n; i++)
		{
			cin >> str;

			int len = strlen(str);

			Out[str[0] - 'a']++;

			In[str[len - 1] - 'a']++;

			g[str[0] - 'a'][str[len - 1] - 'a'] = 1;

			g[str[len - 1] - 'a'][str[0] - 'a'] = 1;

			if (num[str[0] - 'a'] == 0) num[str[0] - 'a'] = 1;

			if (num[str[len - 1] - 'a'] == 0) num[str[len - 1] - 'a'] = 1;

			s = str[0] - 'a';

		}


		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < 30; i++)
		{

			if ((In[i] - Out[i]) >= 1) sum1++;

			if ((In[i] - Out[i]) <= -1) sum2++;

			if (abs(In[i] - Out[i])>1) temp = false;

		
		if (sum1 >= 2 || sum2 >= 2) temp = false;

		int ha = 0;

		for (int i = 0; i < 30; i++)
		{

			if (num[i] == 1) ha++;

		}
		temp = temp & bfs(s, ha);

		if (temp) cout << "Yes" << endl;
		else cout << "No" << endl;

	}

}