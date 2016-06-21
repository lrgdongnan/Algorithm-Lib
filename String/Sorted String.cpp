//作者：李荣贵
//时间：2016-06-21
//问题描述：
//    对于一个01字符串，你每次可以将一个0修改成1，或者将一个1修改成0。那么，你最少需要修改多少次才能
//    把一个01串 S 变为有序01字符串(有序01字符串是指满足所有0在所有1之前的01串)呢？
//****************************************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T, Count, n;
	string str;
	vector<int> preRecord, postRecord;
	cin >> T;
	while (T--)
	{
		cin >> str;
		n = str.length();
		Count = INT_MAX;
		preRecord.assign(n + 1, 0);
		postRecord.assign(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (str[i - 1] == '1') preRecord[i] = preRecord[i - 1] + 1;
			else preRecord[i] = preRecord[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (str[i] == '0') postRecord[i] = postRecord[i + 1] + 1;
			else postRecord[i] = postRecord[i + 1];
		}
		for (int i = 0; i <= n; i++)
			Count = min(Count, preRecord[i] + postRecord[i]);
		cout << Count << endl;
	}

	return 0;
}