//���ߣ����ٹ�
//ʱ�䣺2016-06-21
//����������
//    ����һ���ַ��� S ��������Ҫ������ɾ�Ĳ������԰� S ���һ�������ַ�����
//	  һ�β�������������λ�ò���һ���ַ�������ɾ������һ���ַ������߰�����һ���ַ��޸ĳ����������ַ���
//****************************************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Record;
int Recursion(string& str, int begin, int end)
{
	if (begin > end) return 0;
	if (begin == end){ Record[begin][end] = 0; return 0; }
	if (Record[begin][end]) return Record[begin][end];
	int res;
	if (str[begin] == str[end])
		res = Recursion(str, begin + 1, end - 1);
	else
	{
		int val1 = Recursion(str, begin, end - 1);
		int val2 = Recursion(str, begin + 1, end);
		int val3 = Recursion(str, begin + 1, end - 1);
		res = min(val1, min(val2, val3)) + 1;
	}
	Record[begin][end] = res;
	return res;
}

int main()
{
	string str;
	cin >> str;
	int n = str.length();
	Record.assign(n, vector<int>(n, 0));
	Recursion(str, 0, n - 1);
	cout << Record[0][n - 1] << endl;

	return 0;
}
