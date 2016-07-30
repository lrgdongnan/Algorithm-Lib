//作者：李荣贵
//时间：2016-07-28
//题目来源：hihoCoder太阁最新面经算法竞赛10-B
//题目描述：Given N lists of customer purchase, your task is to find the products that appear in all of the lists.
//			A purchase list consists of several lines. Each line contains 3 parts: the product id (format XXXX-XXXX), 
//			the purchase date (format mm/dd/yyyy) and the price (with decimal places). Two product are considered equal 
//			if both the product id and the price are equal. 
//解题思路：用一个map存储第一个顾客的商品，map中键为id+price，值为该商品出现次数；统计商品在所有顾客中出现次数，
//			一个清单中重复商品只计数一次（用set实现）；
//***********************************************************************************************************************

#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	string id, date, price;
	map<string, int> M;
	set<string> S;
	vector<string> res;

	cin >> n >> m;
	for (int k = 0; k < m;k++)
	{
		cin >> id >> date >> price;
		auto it = M.find(id + price);
		if (it == M.end())
			M[id + price] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> m;
		S.clear();
		while (m--)
		{
			cin >> id >> date >> price;
			string str = id + price;
			if (S.find(str) == S.end())
			{
				S.insert(str);
				auto it = M.find(str);
				if (it != M.end()) it->second++;
			}
		}
	}
	for (auto it = M.begin(); it != M.end();it++)
	if (it->second == n) res.push_back(it->first.substr(0, 9));
	sort(res.begin(), res.end());
	for (string& item : res)
		cout << item << endl;

	return 0;
}
