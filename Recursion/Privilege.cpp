#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
//题目来源：[Offer收割]编程练习赛4
//题目描述：最近天气炎热，小Ho天天宅在家里叫外卖。他常吃的一家餐馆一共有N道菜品，
//			价格分别是A1, A2, ... AN元。并且如果消费总计满X元，还能享受优惠。小Ho是一个不薅羊毛不舒服斯基的人，
//			他希望选择若干道不同的菜品，使得总价在不低于X元的同时尽量低。
//			你能算出这一餐小Ho最少消费多少元吗？

//思路一：枚举法，时间复杂度O(2^N)，用一个整数的二进制数中的一位来表示某个价格的选取与否，
//		  故所有的选取方案对应于1到2^n-1的序列；
#include <set>
#include <assert.h>
using namespace std;


#define N 100020
#define M 100200
#define eps 1e-12
#define inf 0x3f3f3f3f
#define mod 110119
#define LL long long
#define ls (i << 1)
#define rs (ls | 1)
#define md (ll + rr >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define MP make_pair
#define pii pair<int, int>
#define ui unsigned int
#define fi first
#define se second
#define pll pair<LL, LL>
#define pdi pair<double, int>

int n, a[N], X;


int main() {
	scanf("%d%d", &n, &X);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum < X) {
		puts("-1");
		return 0;
	}
	int ans = inf;
	for (int s = 1; s < (1 << n); ++s) {
		int t = 0;
		for (int j = 0; j < n; ++j) {
			if (s >> j & 1) {
				t += a[j];
			}
		}
		if (t >= X) ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}

//思路二：递归，好处就是递归过程中可以进行剪枝，不过递归始终效率低下，应尽量避免使用
#include <iostream>
using namespace std;

int N, X, res;
int price[20];

void Recursion(int k, int cost, int left)
{
	if (cost >= X)
	{
		if (cost < res) res = cost;
		return;
	}
	if (cost + left < X) return;
	Recursion(k + 1, cost, left - price[k]);
	Recursion(k + 1, cost + price[k], left - price[k]);
}

int main()
{
	int sum = 0;
	cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
		sum += price[i];
	}
	if (sum < X) cout << -1 << endl;
	else
	{
		res = sum;
		Recursion(0, 0, sum);
		cout << res << endl;
	}

	return 0;
}