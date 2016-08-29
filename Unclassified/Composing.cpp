//时间：2016-08-29
//题目：图片排版
//题目来源：hihoCoder之[Offer收割]编程练习赛7-10
//题目描述：将n张照片放入一张宽为m的文档中，图片按序存放，若当前行剩余宽度小于图片宽度，
//			将图片进行等比例压缩，求删除一张后文档的最小高度；
//*******************************************************************************************

//思路解析：该问题的一般思路是进行二重循环，分别求出删除每一张图片后所得的文档高度并取最小值；
//			这种方案思路清晰，但效率太低，进行了大量的重复计算；
//			优化方案是进行预处理，从而避免了大量的重复计算；程序中f[i]存储第i到n张图片按上述规则
//			存储得到的高度；

#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200000 + 10;
int n, m, w[maxn], h[maxn], f[maxn];

void put(int k, int &W, int &H)
{
	if (W + w[k] <= m) {
		W += w[k];
		H = max(H, h[k]);
	}
	else {
		int new_w = m - W;
		int new_h = (h[k] * new_w + w[k] - 1) / w[k];
		W += new_w;
		H = max(H, new_h);
	}
}

int calc(int W, int H, int k)
{
	while (k <= n && W < m) {
		put(k++, W, H);
	}
	return H + f[k];
}

int main(int argc, char *argv[]) {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &w[i], &h[i]);
	}
	for (int i = n; i >= 1; i--) {
		f[i] = calc(0, 0, i);
	}
	int ret = 100000000;
	int sum = 0, now_w = 0, now_h = 0;
	for (int i = 1; i <= n; i++) {
		int temp = calc(now_w, now_h, i + 1);
		ret = min(ret, sum + temp);
		put(i, now_w, now_h);
		if (now_w == m) {
			sum += now_h;
			now_w = 0;
			now_h = 0;
		}
	}
	printf("%d\n", ret);
	return 0;
}
