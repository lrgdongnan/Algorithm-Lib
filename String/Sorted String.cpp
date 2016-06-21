//���ߣ����ٹ�
//ʱ�䣺2016-06-21
//����������
//    ����һ��01�ַ�������ÿ�ο��Խ�һ��0�޸ĳ�1�����߽�һ��1�޸ĳ�0����ô����������Ҫ�޸Ķ��ٴβ���
//    ��һ��01�� S ��Ϊ����01�ַ���(����01�ַ�����ָ��������0������1֮ǰ��01��)�أ�
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