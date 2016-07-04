//���ߣ����ٹ�
//ʱ�䣺2016-07-04
//��Ŀ��Դ�������֮������2.3�ڣ�Ѱ�ҷ���ˮ��
//��Ŀ�������ҳ�ID�б��г��ִ�������һ���ID��˼·��ÿ����������ͬID�������������µı���Ŀ��ID
//**********************************************************************************************

#include <iostream>
#include <vector>
using namespace std;

char FindWaterKing(vector<char>& Ch)
{
	char candidate, times = 0;
	for (int i = 0; i < Ch.size(); i++)
	{
		if (times == 0)
		{
			candidate = Ch[i];
			times = 1;
		}
		else
		{
			if (candidate == Ch[i]) times++;
			else times--;
		}
	}
	times = 0;
	for (int j = 0; j < Ch.size();j++)
	if (Ch[j] == candidate) times++;
	if (times>(Ch.size() / 2)) return candidate;
	return '*';
}
int main()
{
	int n;
	vector<char> Ch;
	cin >> n;
	Ch.assign(n, '*');
	for (int i = 0; i < n; i++) cin >> Ch[i];
	char res = FindWaterKing(Ch);
	cout << "Water King: ";
	if (res == '*')
		cout << "No Water King!\n";
	else cout << res << endl;
	
	system("pause");
	return 0;
}