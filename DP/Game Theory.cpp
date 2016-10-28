//题目：博弈论
//题目来源：http://hihocoder.com/contest/hihointerview13/problem/1
//题目大意：小强和boss进行智力PK，规则是有一个非负整数数组，两人从小强开始，依次轮流从剩余序列的任意一端取一个数，
//使得自己获取的数累计值最大。假设小强和boss都足够聪明，每次选取都做出最优决策，求出最终两人获取的分数。
//****************************************************************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

int Second(int[], int, int);

int First(int money[], int i, int j)
{
	if (i > j) return 0;
	else if (i == j) return money[i];
	return max(money[i] + Second(money, i + 1, j), money[j] + Second(money, i, j - 1));
}

int Second(int money[], int i, int j)
{
	if (i > j) return 0;
	return min(First(money, i + 1, j), First(money, i, j - 1));
}

int money[1000];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> money[i];
	cout << First(money, 0, N - 1) << endl;

	system("pause");
	return 0;
}

//********************************************************************************************************
//使用DP进行优化
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int money[1000];

int Win(int money[], int n)
{
	vector<vector<int>> f(n, vector<int>(n, 0)), s(n, vector<int>(n, 0));
	for (int j = 0; j < n; j++)
	{
		f[j][j] = money[j];
		for (int i = j - 1; i >= 0; i--)
		{
			f[i][j] = max(money[i] + s[i + 1][j], money[j] + s[i][j - 1]);
			s[i][j] = min(f[i + 1][j], f[i][j - 1]);
		}
	}
	return f[0][n - 1];
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> money[i];
	cout << Win(money, N) << endl;

	system("pause");
	return 0;
}