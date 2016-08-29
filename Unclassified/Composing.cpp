//ʱ�䣺2016-08-29
//��Ŀ��ͼƬ�Ű�
//��Ŀ��Դ��hihoCoder֮[Offer�ո�]�����ϰ��7-10
//��Ŀ��������n����Ƭ����һ�ſ�Ϊm���ĵ��У�ͼƬ�����ţ�����ǰ��ʣ����С��ͼƬ��ȣ�
//			��ͼƬ���еȱ���ѹ������ɾ��һ�ź��ĵ�����С�߶ȣ�
//*******************************************************************************************

//˼·�������������һ��˼·�ǽ��ж���ѭ�����ֱ����ɾ��ÿһ��ͼƬ�����õ��ĵ��߶Ȳ�ȡ��Сֵ��
//			���ַ���˼·��������Ч��̫�ͣ������˴������ظ����㣻
//			�Ż������ǽ���Ԥ�����Ӷ������˴������ظ����㣻������f[i]�洢��i��n��ͼƬ����������
//			�洢�õ��ĸ߶ȣ�

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
