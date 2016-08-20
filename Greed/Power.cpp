//��Ŀ��СP��ǿ��ֵ
//��Ŀ��Դ��hihoCoder֮[Offer�ո�]�����ϰ��5-2
//2016-08-20

//����˼·������
//	��������̰���㷨��
//	���Ƚ���ʽ����ȡ��������ΪK����ӣ�
//	Ȼ���n��ʹ��ҩ�裬ÿ��ѡ��һ������ʹ�����1�㣬ѡ���������ʹ����ֵ����1�����Ķ�Ӧ�������ֵ���
//	�㷨��ʹ��������ȼ����У�����������ֵ����1����������ֵ���򣩣�ÿ��ѡ�������ɣ�

#include <iostream>
#include <queue>
#include <algorithm>
#include<cmath>
using namespace std;

#define N 100100
int a[N], b[N];
#define inf 0x3f3f3f3f
#define exp 2.718281828459
int n, m, k;

struct P{
	int c, a; //c��ʾ�����Ե������ţ�a��ʾ�����Ե�����ֵ
	double del; //del��ʾ����ֵ����1�����Ķ�Ӧ�������ֵ
	P(int c1, double d, int bb) :c(c1), del(d), a(bb){}
	bool operator <(P b)const 
	{
		return del<b.del;
	}
};

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 0; i<k; i++)
			cin >> a[i];
		for (int i = 0; i<k; i++)
			cin >> b[i];
		priority_queue<P> que;
		double ans = 0;
		for (int i = 0; i<k; i++)
		{
			que.push(P(i, 1.0 / b[i] * (log(a[i] + 1) - log(a[i])), a[i]));
			ans = ans + 1.0 / b[i] * log(a[i]);
		}
		//   cout<<"ans="<<ans<<endl;
		P p1(1, 2.0, 3);
		for (int i = 0; i<n; i++)
		{
			p1 = que.top();
			que.pop();
			ans = ans + p1.del;
			p1.a++;
			p1.del = 1.0 / b[p1.c] * (log(p1.a + 1) - log(p1.a));
			que.push(p1);
			//   cout<<ans<<" "<<a[i]<<endl;
		}
		//  cout<<ans<<endl;
		ans = pow(exp, ans);
		printf("%.7f\n", ans);
		//   cout<<ans<<endl;
	}

	return 0;
}
/*
a1b2a1
*/
