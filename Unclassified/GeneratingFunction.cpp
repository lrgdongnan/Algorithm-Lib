//���ߣ����ٹ�
//ʱ�䣺2016-07-17
//������Դ��hihoCoder̫�������澭�㷨����8-B
//��Ŀ������ĸ����������
//************************************************************

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n, m, len;
	double res;
	cin >> n >> m;
	vector<ll> record(m + 1, 0);
	for (int i = 1; i <= 6 && i <= m; i++) record[i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			record[j] = 0;
			for (int k = 1; k <= 6; k++)
			{
				if (j - k <= 0) continue;
				record[j] += record[j - k];
			}
		}
	}
	res = record[m];
	for (int i = 0; i < n; i++) res /= 6.0;
	cout << setprecision(2) << fixed << res * 100 << endl;

	system("pause");
	return 0;
}