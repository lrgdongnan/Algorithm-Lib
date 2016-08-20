//题目：单词接龙
//题目描述：
//	拉姆刚开始学习英文单词，对单词排序很感兴趣。
//	如果给拉姆一组单词，他能够迅速确定是否可以将这些单词排列在一个列表中，使得该列表中任何单词的首字母与前一单词的为字母相同。
//	你能编写一个程序来帮助拉姆进行判断吗？
//解题思路：
//	将单词建成一副图，取出每个单词的第一个字母和最后一个字母，连一条有向边，本问题就转化为一个欧拉通路问题。
//	然后根据欧拉性质判断是否存在通路：
//	1.图联通；
//	2.除2个端点外其余节点入度=出度；1个端点入度比出度大1；一个端点入度比出度小1 或 所有节点入度等于出度；
//补充知识：
//	欧拉通路: 通过图中每条边且只通过一次，并且经过每一顶点的通路。
//	欧拉回路: 通过图中每条边且只通过一次，并且经过每一顶点的回路。

//	无向图是否具有欧拉通路或回路的判定:
//		欧拉通路:图连通；图中只有0个或2个度为奇数的节点
//		欧拉回路:图连通；图中所有节点度均为偶数

//	有向图是否具有欧拉通路或回路的判定:
//		欧拉通路:图连通；除2个端点外其余节点入度=出度；1个端点入度比出度大1；一个端点入度比出度小1 
//			或 所有节点入度等于出度
//		欧拉回路:图连通；所有节点入度等于出度
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