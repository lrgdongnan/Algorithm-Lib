//作者：李荣贵
//时间：2016-07-03
//来源：hihoCoder太阁最新面经算法竞赛7-1
//问题：Given N words from the top 100 common words in English (see below for reference), select as many words as 
//      possible as long as no two words share common letters. 
//      Assume that the top 100 common words in English are:
//      the be to of and a in that have i it for not on with he as you do at this but his by from they we say her 
//      she or an will my one all would there their what so up out if about who get which go me when make can like 
//      time no just him know take people into year your good some could them see other than then now look only come 
//      its over think also back after use two how our work first well even new want because any these give day most us
//***********************************************************************************************************************

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory.h>
using namespace std;

int main()
{
	int n;
	vector<string> strs;
	vector<list<int>> Adj;
	cin >> n;
	strs.assign(n, "");
	Adj.assign(n, list<int>());
	for (int i = 0; i < n; i++)
		cin >> strs[i];
	bool hash[26];
	for (int i = 0; i < n; i++)
	{
		memset(hash, 0, 26);
		for (int k = 0; k < strs[i].length(); k++)
			hash[strs[i][k] - 'a'] = true;
		for (int j = i + 1; j < n; j++)
		{
			int k;
			for (k = 0; k < strs[j].length();k++)
			if (hash[strs[j][k] - 'a']) break;
			if (k < strs[j].length())
			{
				Adj[i].push_back(j);
				Adj[j].push_back(i);
			}
		}
	}
	int maxDegree, index, num = n;
	while (1)
	{
		maxDegree = 0;
		for (int i = 0; i < n; i++)
		{
			if (Adj[i].size()>maxDegree)
			{
				maxDegree = Adj[i].size();
				index = i;
			}
		}
		if (maxDegree == 0) break;
		for (auto it = Adj[index].begin(); it != Adj[index].end(); it++)
			Adj[*it].remove(index);
		Adj[index].clear();
		num--;
	}
	cout << num << endl;

	return 0;
}