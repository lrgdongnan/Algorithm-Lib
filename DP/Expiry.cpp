//��Ŀ����ȯ�һ�
//��Ŀ��Դ��hihoCoder֮[Offer�ո�]�����ϰ��6-4
//��Ŀ������СHi������԰�л����M�Ž�ȯ����Щ��ȯ���������һ���Ʒ��
//			�ɹ��һ��Ľ�Ʒһ����N������i����Ʒ��ҪWi�Ž�ȯ���ܶһ��������ֵ��Pi��  
//			СHiʹ�ò�����M�Ž�ȯ���ܶһ��������Ʒ�ܼ�ֵ�Ƕ��٣�
//����˼·��0-k��������
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
