//hihoCoder̫�������澭�㷨����5-2
//ʱ�䣺2016-06-26
//��������������һ��ֻ����Сд��ĸ'a'-'z'���ַ��� S ������Ҫ�� S �е��ַ���������ʹ������������ͬ���ַ�������һ��
//����ж�����ź��ַ�����������������ֵ�����С��һ������������������������ַ��������INVALID��
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