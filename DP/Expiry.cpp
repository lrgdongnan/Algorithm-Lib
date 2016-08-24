//题目：奖券兑换
//题目来源：hihoCoder之[Offer收割]编程练习赛6-4
//题目描述：小Hi在游乐园中获得了M张奖券，这些奖券可以用来兑换奖品。
//			可供兑换的奖品一共有N件。第i件奖品需要Wi张奖券才能兑换到，其价值是Pi。  
//			小Hi使用不超过M张奖券所能兑换到的最大奖品总价值是多少？
//解题思路：0-k背包问题
//**********************************************************************************

#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

const int N = 1005;

int a[12][12];
int n, m;

int f[100005];

void DP(int w, int p, int C)
{
	int cur = 1;
	while (C >= cur)
	{
		const int ww = w*cur;
		const int pp = p*cur;
		for (int i = m; i >= ww; --i)
		{
			f[i] = max(f[i], f[i - ww] + pp);
		}
		C -= cur;
		cur <<= 1;
	}
	const int ww = w*C;
	const int pp = p*C;
	for (int i = m; i >= ww; --i) f[i] = max(f[i], f[i - ww] + pp);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++a[x][y];
	}
	for (int i = 1; i <= 10; ++i) 
		for (int j = 1; j <= 10; ++j) 
		if (a[i][j])
		{
			DP(i, j, a[i][j]);
			for (int j = 0; j <= m; j++) cout << f[j] << " ";
			cout << endl;
		}
	int ans = 0;
	for (int i = 1; i <= m; ++i) ans = max(ans, f[i]);
	printf("%d\n", ans);

	system("pause");
	return 0;
}
