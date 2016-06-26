//hihoCoder太阁最新面经算法竞赛5-2
//时间：2016-06-26
//问题描述：给定一个只包含小写字母'a'-'z'的字符串 S ，你需要将 S 中的字符重新排序，使得任意两个相同的字符不连在一起。
//如果有多个重排后字符串满足条件，输出字典序最小的一个。如果不存在满足条件的字符串，输出INVALID。
//*******************************************************************************************************************
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str, ret;
int cnt[26];

bool isValid(int ch, int len) 
{
	int maxv = 0;
	for (int i = 0; i < 26; i++) 
		maxv = max(maxv, cnt[i]);
	if (cnt[ch] == maxv) 
		return maxv <= len / 2;
	else 
		return maxv <= (len + 1) / 2;
}

int main() {
	cin >> str;
	int n = str.length();
	ret.assign(n, 'o');
	for (int i = 0; i < n; i++)
		cnt[str[i]-'a']++;

	int i;
	for (i = 0; i < n; i++) 
	{
		bool current = false;
		for (int j = 0; j < 26; j++) 
		{
			if (cnt[j] > 0 && (i == 0 || ('a'+j) != ret[i - 1])) 
			{
				cnt[j]--;
				if (isValid(j, n - 1 - i)) 
				{
					ret[i] = 'a'+j;
					current = true;
					break;
				}
				else 
					cnt[j]++;
			}
		}
		if (!current) {
			cout << "INVALID" << endl;
			break;
		}
	}
	if (i==n)
		cout << ret << endl;

	system("pause");
	return 0;
}