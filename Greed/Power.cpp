//题目：小P的强力值
//题目来源：hihoCoder之[Offer收割]编程练习赛5-2
//2016-08-20

//解题思路解析：
//	总体运用贪心算法；
//	首先将公式整体取对数，变为K项相加；
//	然后分n步使用药丸，每次选择一种属性使其提高1点，选择的依据是使属性值增加1带来的对应项的增量值最大；
//	算法中使用最大优先级队列（按各项属性值增加1带来的增量值排序），每次选择队首项即可；

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
	int c, a; //c表示该属性的索引号，a表示该属性的属性值
	double del; //del表示属性值增加1带来的对应项的增量值
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
