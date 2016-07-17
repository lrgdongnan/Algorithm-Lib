//作者：李荣贵
//时间：2016-07-17
//问题来源：hihoCoder太阁最新面经算法竞赛8-B
//题目描述：母函数的运用
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